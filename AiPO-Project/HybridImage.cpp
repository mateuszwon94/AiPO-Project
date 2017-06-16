#include "HybridImage.h"

HybridImage::HybridImage(cv::Mat* left_image, cv::Mat* right_image) {
	ImageLeft_ = left_image;
	ImageRigth_ = right_image;
	ImageMixed_ = nullptr;
}

HybridImage::~HybridImage() {
	delete ImageMixed_;
}