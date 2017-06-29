#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <vector>
#include <cmath>
#include "HybridImage.h"

using namespace cv;
using namespace std;


HybridImage::HybridImage(Mat* left_image, Mat* right_image)
	: ImageLeft_(left_image), ImageRight_(right_image), ImageMixed_(nullptr) { }

HybridImage::~HybridImage() {
	delete ImageMixed_;
}

Mat* HybridImage::getHybridImage() {
	return ImageMixed_;
}

void HybridImage::calculateHybridImage(double alpha) {
	Mat imageLeftDFT = calculateDFT(*ImageLeft_);
	Mat imageRightDFT = calculateDFT(*ImageRight_);

	int rows = imageLeftDFT.rows;
	int cols = imageLeftDFT.cols;
	Mat lowPassFilter = makeGaussianFilter(rows, cols, alpha, false);
	Mat highPassFilter = makeGaussianFilter(rows, cols, alpha, true);

	Mat filtered_left_image(imageLeftDFT.rows, imageLeftDFT.cols, imageLeftDFT.type());
	Mat filtered_right_image(imageRightDFT.rows, imageRightDFT.cols, imageRightDFT.type());
	Mat mixed_image(imageLeftDFT.rows, imageLeftDFT.cols, imageLeftDFT.type());
	for (size_t i = 0; i < rows; ++i) {
		for (size_t j = 0; j < cols; ++j) {
			filtered_left_image.at<float>(i, j) = imageLeftDFT.at<float>(i, j) * highPassFilter.at<float>(i, j);
			filtered_right_image.at<float>(i, j) = imageRightDFT.at<float>(i, j) * lowPassFilter.at<float>(i, j);
			mixed_image.at<float>(i, j) = filtered_left_image.at<float>(i, j) + filtered_right_image.at<float>(i, j);
		}
	}

	Mat imageMixed = calculateIDFT(mixed_image);
	ImageMixed_ = new Mat(imageMixed);
}

Mat HybridImage::swapQuarters(Mat complex_image) {
	Mat tmp;
	Mat q0(complex_image, Rect(0, 0, complex_image.cols / 2, complex_image.rows / 2));
	Mat q1(complex_image, Rect(complex_image.cols / 2, 0, complex_image.cols / 2, complex_image.rows / 2));
	Mat q2(complex_image, Rect(0, complex_image.rows / 2, complex_image.cols / 2, complex_image.rows / 2));
	Mat q3(complex_image, Rect(complex_image.cols / 2, complex_image.rows / 2, complex_image.cols / 2, complex_image.rows / 2));
	q0.copyTo(tmp);	q3.copyTo(q0); tmp.copyTo(q3);
	q1.copyTo(tmp);	q2.copyTo(q1); tmp.copyTo(q2);
	return complex_image;
}

Mat HybridImage::calculateDFT(Mat image) {
	Mat image_with_border, complex_image;
	image.convertTo(image, CV_32FC1);
	copyMakeBorder(image, image_with_border, 0, getOptimalDFTSize(image.rows) - image.rows, 0, getOptimalDFTSize(image.cols) - image.cols, BORDER_CONSTANT, Scalar::all(0));
	Mat planes[] = { Mat_<float>(image_with_border), Mat::zeros(image_with_border.size(), CV_32FC1) };
	merge(planes, 2, complex_image);
	dft(complex_image, complex_image, DFT_COMPLEX_OUTPUT);
	return complex_image;
}


Mat HybridImage::calculateIDFT(Mat complex_image) {
	Mat output_image;
	idft(complex_image, output_image, DFT_SCALE | DFT_REAL_OUTPUT);
	output_image.convertTo(output_image, CV_8UC1);
	normalize(output_image, output_image, 0, 255, CV_MINMAX);
	return output_image;
}

Mat HybridImage::makeGaussianFilter(size_t numRows, size_t numCols, double sigma, bool highPass) {
	size_t centerI = int(numRows / 2.0) + (numRows % 2);
	size_t centerJ = int(numCols / 2.0) + (numCols % 2);

	Mat filter[] = {
		Mat(numRows, numCols, CV_32FC1, Scalar::all(0)),
		Mat(numRows, numCols, CV_32FC1, Scalar::all(0))
	};

	circle(filter[0], Point(centerI, centerJ), sigma * numRows / 1000, Scalar::all(1), -1);
	GaussianBlur(filter[0], filter[0], Size(int(sigma / 2) * 8 + 1, int(sigma / 2) * 8 + 1), 0);
	if (highPass) {
		for (size_t i = 0; i < numRows; ++i) {
			for (size_t j = 0; j < numRows; ++j) {
				filter[0].at<float>(i, j) = fabs(1 - filter[0].at<float>(i, j));
			}
		}
	}
	filter[0] = swapQuarters(filter[0]);
	filter[1] = filter[0].clone();
	Mat merged;
	merge(filter, 2, merged);
	return merged;
}