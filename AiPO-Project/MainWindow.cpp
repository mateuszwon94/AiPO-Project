#include <QFileDialog>
#include <QMessageBox>
#include <QBuffer>
#include <vector>
#include <opencv2/opencv.hpp>
#include "MainWindow.h"

using namespace cv;
using namespace std;

MainWindow::MainWindow(QWidget *parent)
	: QMainWindow(parent), ImageLeft_{nullptr}, ImageRight_{nullptr}, ImageMixed_{nullptr} {

	ui.setupUi(this);
	connect(ui.AddLeft_Button, SIGNAL(released()), this, SLOT(AddLeftImageHandler()));
	connect(ui.AddRight_Button, SIGNAL(released()), this, SLOT(AddRightImageHandler())); 
	connect(ui.RemoveLeft_Button, SIGNAL(released()), this, SLOT(RemoveLeftImageHandler()));
	connect(ui.RemoveRigth_Button, SIGNAL(released()), this, SLOT(RemoveRightImageHandler()));
	connect(ui.Adjust_Slider, SIGNAL(valueChanged(int)), this, SLOT(MixedImageHandler()));
	connect(ui.SaveImage_Button, SIGNAL(released()), this, SLOT(SaveImageHandler()));
	connect(ui.SaveAnimation_Button, SIGNAL(released()), this, SLOT(SaveAnimationHandler()));
}

MainWindow::~MainWindow() {
	if (ImageLeft_ != nullptr)
		delete ImageLeft_;

	if (ImageRight_ != nullptr)
		delete ImageRight_;

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

void MainWindow::SaveImageHandler() {
	saveImage();
}

void MainWindow::SaveAnimationHandler() {
	saveMovie();
}

void MainWindow::MixedImageHandler() {
	createMixedImage();
}

void MainWindow::saveImage() {
	if (ImageMixed_ != nullptr) {
		QString fileName = QFileDialog::getSaveFileName(this, tr("Save file"), "", tr("PNG (*.png);;JPEG (*.jpeg *.jpg *.jpe)"));
		Mat* hybrid_image = ImageMixed_->getHybridImage();
		QImage image = QImage(hybrid_image->data, hybrid_image->cols, hybrid_image->rows, hybrid_image->step, QImage::Format_Grayscale8);
		image.save(fileName);
		QMessageBox::information(this, tr("Hybrid Images"), tr("Zapisano obraz wynikowy."));
	} else
		QMessageBox::warning(this, tr("Hybrid Images"), tr("Nie można zapisać!"));
}

void MainWindow::saveMovie() {
	if (ImageMixed_ != nullptr) {
		int rows = ImageMixed_->getHybridImage()->rows;
		int cols = ImageMixed_->getHybridImage()->cols;
		std::vector<Mat> frames;

		double fps = 25.0;
		int codec = CV_FOURCC('M', 'J', 'P', 'G');
		QString fileName = QFileDialog::getSaveFileName(this, tr("Save file"), "", tr("MJPG (*.avi)"));
		VideoWriter out_capture;
		out_capture.open(fileName.toStdString(), codec, fps, Size(rows, cols), false);

		if (!out_capture.isOpened()) {
			QMessageBox::warning(this, tr("Hybrid Images"), tr("Nie można zapisać!"));
			return;
		}

		Mat frame;
		Mat* hybrid_image = ImageMixed_->getHybridImage();
		for (double k = 1.0; k >= 0.2; k -= 0.005) {
			cv::resize(*hybrid_image, frame, Size(int(rows*k), int(cols*k)));
			copyMakeBorder(frame, frame, int(rows * (1.0 - k) / 2), int(rows * (1.0 - k) / 2), int(cols * (1.0 - k) / 2), int(cols * (1.0 - k) / 2), BORDER_CONSTANT, Scalar::all(0));
			cv::resize(frame, frame, Size(rows, cols));
			frames.push_back(frame);
		}

		for (int i = 0; i < fps; ++i)
			out_capture << frames[0];

		for (int i = 0; i < frames.size(); ++i)
			out_capture << frames[i];

		for (int i = 0; i < fps; ++i)
			out_capture << frames[frames.size() - 1];

		for (int i = frames.size() - 1; i >= 0; --i)
			out_capture << frames[i];
		
		for (int i = 0; i < fps; ++i)
			out_capture << frames[0];

		QMessageBox::information(this, tr("Hybrid Images"), tr("Zapisano animację wynikową."));
		
	} else
		QMessageBox::warning(this, tr("Hybrid Images"), tr("Nie można zapisać!"));
}

Mat* MainWindow::loadImage() {
	Mat image;

	QString fileName = QFileDialog::getOpenFileName(this,
													tr("Wczytaj obraz po lewej stronie"), "",
													tr("JPEG (*.jpeg *.jpg *.jpe);;JPEG 2000 (*.jp2);;BMP (*.bmp *.dib);;TIFF (*.tiff *.tif);;Wszystkie pliki (*)"));
	//PNG (*.png);;
	if ( !fileName.isEmpty() ) {
		image = imread(fileName.toStdString(), CV_LOAD_IMAGE_GRAYSCALE);
		if (!image.data) {
			exit(EXIT_FAILURE);
		}
	}

	return new Mat(image);
}

void MainWindow::setImage(Mat* image, QLabel* label) {
	if ( image != nullptr && label != nullptr ) {
		if ( label == ui.LeftImage_Label ) {
			ImageLeft_ = image;
		} else if ( label == ui.RightImage_Label ) {
			ImageRight_ = image;
		}
		fitImageToLabel(image, label);
	} else if ( image == nullptr && label != nullptr ) {
		label->clear();
		if ( label == ui.LeftImage_Label && ImageLeft_ != nullptr ) {
			delete ImageLeft_;
			ImageLeft_ = nullptr;
		} else if ( label == ui.RightImage_Label && ImageRight_ != nullptr ) {
			delete ImageRight_;
			ImageRight_ = nullptr;
		} else if ( label == ui.MixedImage_Label && ImageMixed_ != nullptr ) {
			delete ImageMixed_;
			ImageMixed_ = nullptr;
		}
	}
}

void MainWindow::fitImageToLabel(Mat* image, QLabel* label) {
	QPixmap qpixmap = QPixmap::fromImage(QImage(image->data, image->cols, image->rows, image->step, QImage::Format_Grayscale8));
	label->setPixmap(qpixmap.scaled(label->width(), label->height(), Qt::KeepAspectRatio));
}

void MainWindow::resizeEvent(QResizeEvent *event) {
	QWidget::resizeEvent(event);
	QPixmap qpixmap;
	if ( ImageLeft_ != nullptr ) {
		fitImageToLabel(ImageLeft_, ui.LeftImage_Label);
	}
	if ( ImageRight_ != nullptr ) {
		fitImageToLabel(ImageRight_, ui.RightImage_Label);
	}
	if ( ImageMixed_ != nullptr ) {
		fitImageToLabel(ImageMixed_->getHybridImage(), ui.MixedImage_Label);
	}
}

void MainWindow::loadImageFromButton(QPushButton* button) {
	if ( button == ui.AddLeft_Button || button == ui.AddRight_Button ) {
		Mat* image = loadImage();
		if ( button == ui.AddLeft_Button ) {
			setImage(image, ui.LeftImage_Label);
		} else if ( button == ui.AddRight_Button ) {
			setImage(image, ui.RightImage_Label);
		}
	} else if ( button == ui.RemoveLeft_Button ) {
		setImage(nullptr, ui.LeftImage_Label);
	} else if ( button == ui.RemoveRigth_Button ) {
		setImage(nullptr, ui.RightImage_Label);
	}
	createMixedImage();
}

void MainWindow::createMixedImage() {
	if ( ImageLeft_ != nullptr && ImageRight_ != nullptr ) {
		if ( ImageMixed_ != nullptr )
			delete ImageMixed_;
		ImageMixed_ = new HybridImage(ImageLeft_, ImageRight_);
		ImageMixed_->calculateHybridImage(getSliderValue());
		setImage(ImageMixed_->getHybridImage(), ui.MixedImage_Label);
	} else {
		setImage(nullptr, ui.MixedImage_Label);
	}
}

double MainWindow::getSliderValue() {
	return ui.Adjust_Slider->value();
}