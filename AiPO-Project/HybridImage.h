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
	cv::Mat makeGaussianFilter(size_t numRows, size_t numCols, double sigma, bool highPass = true);
	cv::Mat filter(const cv::Mat &spectrum, double cutoffFreq, int type);
	inline cv::Mat highPassFilter(const cv::Mat &spectrum, double cutoffFreq);
	inline cv::Mat lowPassFilter(const cv::Mat &spectrum, double cutoffFreq);
	cv::Mat getSpectrum(const cv::Mat &image);
	cv::Mat getImage(const cv::Mat &spectrum);
	cv::Mat getSpectrumImage(const cv::Mat &image);

	cv::Mat* ImageLeft_;
	cv::Mat* ImageRight_;
	cv::Mat* ImageMixed_;
};