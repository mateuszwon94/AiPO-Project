#include "HybridImage.h"

HybridImage::HybridImage(cv::Mat* left_image, cv::Mat* right_image) {
	ImageLeft_ = left_image;
	ImageRigth_ = right_image;
	//ImageMixed_ = nullptr;
	ImageMixed_ = left_image;
}

HybridImage::~HybridImage() {
	delete ImageMixed_;
}

cv::Mat* HybridImage::getHybridImage() {
	return ImageMixed_;
}