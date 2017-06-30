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
	void SaveImageHandler();
	void SaveAnimationHandler();
	void MixedImageHandler();

private:
	cv::Mat* loadImage();
	void saveImage();
	void saveMovie();
	void setImage(cv::Mat* image, QLabel* label);
	void fitImageToLabel(cv::Mat* image, QLabel* label) const;
	void loadImageFromButton(QPushButton* button);
	void resizeEvent(QResizeEvent *event) override;
	void createMixedImage();
	double getSliderValue() const;

	Ui::MainWindowClass ui;
	cv::Mat* ImageLeft_;
	cv::Mat* ImageRight_;
	HybridImage* ImageMixed_;
};
