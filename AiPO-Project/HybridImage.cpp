#include <opencv2/opencv.hpp>
#include "HybridImage.h"

using namespace cv;

HybridImage::HybridImage(Mat* left_image, Mat* right_image) {
	ImageLeft_ = left_image;
	ImageRight_ = right_image;
	ImageMixed_ = nullptr;
}

HybridImage::~HybridImage() {
	delete ImageMixed_;
}

Mat* HybridImage::getHybridImage() {
	return ImageMixed_;
}

void HybridImage::calculateHybridImage(double alpha) {
	Mat ImageLeftDFT_ = calculateDFT(ImageLeft_);
	Mat ImageRighDFT_ = calculateDFT(ImageRight_);
	ImageMixed_ = calculateIDFT(ImageLeftDFT_);

}

Mat HybridImage::calculateDFT(Mat* image) {
	Mat image_with_border, bwimage, complex_image, transformata, tmp;
	cvtColor(*image, bwimage, CV_RGB2GRAY);
	bwimage.convertTo(bwimage, CV_32FC1);
	copyMakeBorder(bwimage, image_with_border, 0, getOptimalDFTSize(bwimage.rows) - bwimage.rows, 0, getOptimalDFTSize(bwimage.cols) - bwimage.cols, BORDER_CONSTANT, Scalar::all(0));
	Mat planes[] = { Mat_<float>(image_with_border), Mat::zeros(image_with_border.size(), CV_32FC1) };
	merge(planes, 2, complex_image);
	dft(complex_image, complex_image, DFT_COMPLEX_OUTPUT, 0);
	return complex_image;
}

Mat* HybridImage::calculateIDFT(Mat complex_image) {
	Mat transformata_odwrotna, output_image;
	idft(complex_image, transformata_odwrotna, DFT_SCALE | DFT_REAL_OUTPUT, 0);
	transformata_odwrotna.convertTo(output_image, CV_8UC1);
	cvtColor(output_image, output_image, CV_GRAY2RGB);
	return new Mat(output_image);
}