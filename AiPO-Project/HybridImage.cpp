#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <vector>
#include <cmath>
#include "HybridImage.h"

using namespace cv;
using namespace std;

bool IsInCenterBox(int x, int y, double xSize, double ySize, double alpha) {
	if ( x >= int((xSize - xSize * alpha) / 2.0) &&
		int((xSize + xSize * alpha) / 2.0) >= x &&
		y >= int((ySize - ySize * alpha) / 2.0) &&
		int((ySize + ySize * alpha) / 2.0) >= y )
		return true;
	else return false;
}

HybridImage::HybridImage(Mat* left_image, Mat* right_image) 
	: ImageLeft_(left_image), ImageRight_(right_image), ImageMixed_(nullptr) {
}

HybridImage::~HybridImage() {
	delete ImageMixed_;
}

Mat* HybridImage::getHybridImage() {
	return ImageMixed_;
}

void HybridImage::calculateHybridImage(double alpha) {
	vector<Mat> imageLeftChannels(3), imageRightChannels(3), imageMixedChannels(3);

	split(*ImageLeft_, imageLeftChannels);
	split(*ImageRight_, imageRightChannels);

	int rows = ImageLeft_->rows;
	int cols = ImageLeft_->cols;

	Mat lowPassFilter = makeGaussianFilter(rows, cols, alpha, false);
	Mat highPassFilter = makeGaussianFilter(rows, cols, alpha, true);

	for ( size_t i = 0; i < imageLeftChannels.size(); ++i ) {
		Mat imageLeftChannelDFT = calculateDFT(imageLeftChannels[i]);
		Mat imageRightChannelDFT = calculateDFT(imageRightChannels[i]);

		Mat left_channel = swapQuarters(imageLeftChannelDFT);

		for ( size_t x = 0; x < rows; ++x ) {
			for ( size_t y = 0; y < cols; ++y ) {
				left_channel.at<float>(x, y) *= highPassFilter.at<float>(x, y);
			}
		}

		Mat right_channel = swapQuarters(imageRightChannelDFT);

		for ( size_t x = 0; x < rows; ++x ) {
			for ( size_t y = 0; y < cols; ++y ) {
				right_channel.at<float>(x, y) *= lowPassFilter.at<float>(x, y);
			}
		}

		Mat mixed_channel = left_channel + right_channel;
		mixed_channel = swapQuarters(mixed_channel);
		imageMixedChannels[i] = calculateIDFT(mixed_channel);
	}
	
	Mat merged;
	merge(imageMixedChannels, merged);
	ImageMixed_ = new Mat(merged);
}

Mat& HybridImage::swapQuarters(Mat& complex_image) {
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
	dft(complex_image, complex_image, DFT_COMPLEX_OUTPUT, 0);
	return complex_image;
}

Mat HybridImage::filterDFT(Mat imageDFT, Mat filter) {
	return Mat(imageDFT * filter);
}

Mat HybridImage::calculateIDFT(Mat complex_image) {
	Mat output_image;
	idft(complex_image, output_image, DFT_SCALE | DFT_REAL_OUTPUT, 0);
	output_image.convertTo(output_image, CV_8UC1);
	return output_image;
}

Mat HybridImage::makeGaussianFilter(size_t numRows, size_t numCols, double sigma, bool highPass) {
	size_t centerI = numRows % 2 == 1 ? int(numRows / 2) + 1 : int(numRows / 2);
	size_t centerJ = numCols % 2 == 1 ? int(numCols / 2) + 1 : int(numCols / 2);

	Mat filter(numRows, numCols, CV_32FC1);

	for ( size_t i = 0; i < numRows; ++i ) {
		for ( size_t j = 0; j < numRows; ++j ) {
			float coefficient = exp(-1.0 * (pow(i - centerI, 2) + pow(j - centerJ, 2)) / (2 * pow(sigma, 2)));
			filter.at<float>(i, j) = highPass ? 1 - coefficient : coefficient;
		}
	}

	return filter;
}