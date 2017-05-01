#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets/QMainWindow>

#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>

MainWindow::MainWindow(QWidget *parent) :
	QMainWindow(parent),
	ui(*(new Ui::MainWindowClass)) {
	ui.setupUi(this);

	// read an image
	cv::Mat image = cv::imread("textures//sample.png", 1);
	// create image window named "My Image"
	cv::namedWindow("My Image");
	// show the image on window
	cv::imshow("My Image", image);
}