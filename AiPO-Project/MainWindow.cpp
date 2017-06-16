#include <QFileDialog> 
#include <opencv2/opencv.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include "MainWindow.h"

using namespace cv;

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent), ImageLeft_{nullptr}, ImageRigth_{nullptr}, ImageMixed_{nullptr} {

	ui.setupUi(this);
	connect(ui.AddLeft_Button, SIGNAL(released()), this, SLOT(AddLeftImageHandler()));
	connect(ui.AddRight_Button, SIGNAL(released()), this, SLOT(AddRightImageHandler())); 
	connect(ui.RemoveLeft_Button, SIGNAL(released()), this, SLOT(RemoveLeftImageHandler()));
	connect(ui.RemoveRigth_Button, SIGNAL(released()), this, SLOT(RemoveRightImageHandler()));
	ui.LeftImage_Label->setScaledContents(true);
	ui.RightImage_Label->setScaledContents(true);
}

MainWindow::~MainWindow() {
	if (ImageLeft_ != nullptr) 
		delete ImageLeft_;

	if (ImageRigth_ != nullptr) 
		delete ImageRigth_;

	if (ImageMixed_ != nullptr) 
		delete ImageMixed_;
}

void MainWindow::AddLeftImageHandler() {
	loadImageFromButton(ui.AddLeft_Button);
}

void MainWindow::AddRightImageHandler() {
	loadImageFromButton(ui.AddRight_Button);
}

void MainWindow::RemoveLeftImageHandler() { 
	loadImageFromButton(ui.RemoveLeft_Button);
}

void MainWindow::RemoveRightImageHandler() {
	loadImageFromButton(ui.RemoveRigth_Button);
}

Mat* MainWindow::loadImage() {
	Mat image;

	QString fileName = QFileDialog::getOpenFileName(this,
		tr("Wczytaj obraz po lewej stronie"), "",
		tr("JPEG (*.jpeg *.jpg *.jpe);;JPEG 2000 (*.jp2);;PNG (*.png);;BMP (*.bmp *.dib);;TIFF (*.tiff *.tif);;Wszystkie pliki (*)"));

	if (!fileName.isEmpty()) {
		image = imread(fileName.toStdString());
		cvtColor(image, image, CV_BGR2RGB);
	}

	return new Mat(image);
}

void MainWindow::setImage(Mat* image, QLabel* label) {
	if (image != nullptr && label != nullptr) {
		QPixmap qpixmap = QPixmap::fromImage(QImage(image->data, image->cols, image->rows, image->step, QImage::Format_RGB888));
		if (label == ui.LeftImage_Label) {
			ImageLeft_ = image;
		} else if (label == ui.RightImage_Label) {
			ImageRigth_ = image;
		}
		label->setPixmap(qpixmap.scaled(label->width(), label->height(), Qt::KeepAspectRatio));
	} else if (image == nullptr && label != nullptr) {
		label->clear();
		if (label == ui.LeftImage_Label && ImageLeft_ != nullptr) {
			delete ImageLeft_;
		} else if (label == ui.RightImage_Label && ImageRigth_ != nullptr) {
			delete ImageRigth_;
		}
	}
}

void MainWindow::loadImageFromButton(QPushButton* button) {
	if (button == ui.AddLeft_Button || button == ui.AddRight_Button) {
		Mat* image = loadImage();
		if (button == ui.AddLeft_Button) {
			setImage(image, ui.LeftImage_Label);
		} else if (button == ui.AddRight_Button) {
			setImage(image, ui.RightImage_Label);
		}
	} else if (button == ui.RemoveLeft_Button) {
		setImage(nullptr, ui.LeftImage_Label);
	} else if (button == ui.RemoveRigth_Button) {
		setImage(nullptr, ui.RightImage_Label);
	}
}