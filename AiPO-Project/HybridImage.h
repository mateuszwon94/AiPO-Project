#pragma once

#include <opencv2/core.hpp>
#include <QFileDialog> 


class HybridImage {

public:
	HybridImage(cv::Mat* left_image, cv::Mat* right_image);
	~HybridImage();
	cv::Mat* getHybridImage();

private:
	cv::Mat* ImageLeft_;
	cv::Mat* ImageRigth_;
	cv::Mat* ImageMixed_;
};