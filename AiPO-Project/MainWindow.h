#pragma once

#include <QtWidgets/QMainWindow>
#include <opencv2/core.hpp>
#include <memory>
#include "ui_MainWindow.h"

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
	void loadImageFromButton(QPushButton* button);

	Ui::MainWindowClass ui;
	cv::Mat* ImageLeft_;
	cv::Mat* ImageRigth_;
	cv::Mat* ImageMixed_;
};
