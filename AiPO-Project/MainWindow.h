#pragma once

#include <opencv2/core.hpp>
#include "ui_MainWindow.h"
#include "HybridImage.h"


class MainWindow : public QMainWindow {
	Q_OBJECT

public:
	MainWindow(QWidget *parent = Q_NULLPTR);
	~MainWindow();

private slots: 
	void AddLeftImageHandler();
	void AddRightImageHandler();
	void RemoveLeftImageHandler();
	void RemoveRightImageHandler();

private:
	cv::Mat* loadImage();
	void setImage(cv::Mat* image, QLabel* label);
	void fitImageToLabel(cv::Mat* image, QLabel* label);
	void loadImageFromButton(QPushButton* button);
	void resizeEvent(QResizeEvent *event);
	void createMixedImage();
	double getSliderValue();

	Ui::MainWindowClass ui;
	cv::Mat* ImageLeft_;
	cv::Mat* ImageRight_;
	HybridImage* ImageMixed_;
};
