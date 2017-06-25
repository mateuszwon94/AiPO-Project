#pragma once

#include <opencv2/core.hpp>
#include <vector>
#include <QFileDialog> 


class HybridImage {

public:
	HybridImage(cv::Mat* left_image, cv::Mat* right_image);
	~HybridImage();
	cv::Mat* getHybridImage();
	void calculateHybridImage(double alpha);

private:
	cv::Mat calculateDFT(cv::Mat image);
	cv::Mat calculateIDFT(cv::Mat complex_image);
	cv::Mat swapQuarters(cv::Mat complex_image);

	cv::Mat* ImageLeft_;
	cv::Mat* ImageRight_;
	cv::Mat* ImageMixed_;
};