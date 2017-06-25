#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <vector>
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

	for ( size_t i = 0; i < imageLeftChannels.size(); ++i ) {
		Mat imageLeftChannelDFT = calculateDFT(imageLeftChannels[i]);
		Mat imageRightChannelDFT = calculateDFT(imageRightChannels[i]);

		int rows = imageLeftChannelDFT.rows;
		int cols = imageLeftChannelDFT.cols;

		Mat left_channel = swapQuarters(imageLeftChannelDFT);
		Mat right_channel = swapQuarters(imageRightChannelDFT);
		Mat mixed_channel = Mat(imageRightChannelDFT.size(), imageLeftChannelDFT.type());

		for ( size_t x = 0; x < rows; ++x) {
			for ( size_t y = 0; y < cols; ++y) {
				if (IsInCenterBox(x, y, rows, cols, alpha))
					mixed_channel.at<float>(x, y) = imag(imageLeftChannelDFT.at<float>(x, y));
				else
					mixed_channel.at<float>(x, y) = imag(imageRightChannelDFT.at<float>(x, y));
			}
		}
		mixed_channel = swapQuarters(mixed_channel);
		imageMixedChannels[i] = calculateIDFT(mixed_channel);
	}
	
	Mat merged;
	merge(imageMixedChannels, merged);
	ImageMixed_ = new Mat(merged);
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
	dft(complex_image, complex_image, DFT_COMPLEX_OUTPUT, 0);
	return complex_image;
}

Mat HybridImage::calculateIDFT(Mat complex_image) {
	Mat output_image;
	idft(complex_image, output_image, DFT_SCALE | DFT_REAL_OUTPUT, 0);
	output_image.convertTo(output_image, CV_8UC1);
	return output_image;
}