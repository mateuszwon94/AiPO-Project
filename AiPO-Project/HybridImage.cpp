#include <opencv2/opencv.hpp>
#include <opencv2/core/core.hpp>
#include <vector>
#include "HybridImage.h"

using namespace cv;
using namespace std;

bool IsInCenterBox(int x, int y, int xSize, int ySize, double alpha) {
	if ( x >= xSize * 2 - xSize * alpha / 2 &&
		xSize / 2 + xSize * alpha / 2 >= x &&
		y >= ySize / 2 - ySize * alpha / 2 &&
		ySize / 2 + ySize * alpha / 2 >= y )
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
	vector<Mat> imageLeftChannels(3), imageRightChannels(3);

	split(*ImageLeft_, imageLeftChannels);
	split(*ImageRight_, imageRightChannels);

	vector<Mat> imageMixedChannels(imageLeftChannels.size());

	int rows = ImageLeft_->rows;
	int cols = ImageLeft_->cols;

	for ( size_t i = 0; i < imageLeftChannels.size(); ++i ) {
		Mat imageLeftChannelDFT = calculateDFT(imageLeftChannels[i]);
		Mat imageRightChannelDFT = calculateDFT(imageRightChannels[i]);

		Mat channel = Mat(rows, cols, CV_32FC2);

		for ( size_t x = 0; x < rows; ++x ) {
			for ( size_t y = 0; y < cols; ++y ) {
				if ( IsInCenterBox(x, y, rows, cols, alpha) ) {
					channel.at<float>(x, y) = imageLeftChannelDFT.at<float>(x, y);
				} else {
					channel.at<float>(x, y) = imageRightChannelDFT.at<float>(x, y);
				}
			}
		}

		imageMixedChannels[i] = calculateIDFT(channel);
	}

	Mat merged;
	merge(imageLeftChannels, merged);

	ImageMixed_ = new Mat(merged);

}

Mat HybridImage::calculateDFT(Mat image) {
	Mat image_with_border, bwimage, complex_image;
	image.convertTo(bwimage, CV_32FC1);
	copyMakeBorder(bwimage, image_with_border, 0, getOptimalDFTSize(bwimage.rows) - bwimage.rows, 0, getOptimalDFTSize(bwimage.cols) - bwimage.cols, BORDER_CONSTANT, Scalar::all(0));
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