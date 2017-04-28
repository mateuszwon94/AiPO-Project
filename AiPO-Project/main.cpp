#include <QtCore/QCoreApplication>
#include <QPushButton>

int main(int argc, char *argv[]) {
	QCoreApplication a(argc, argv);

	QPushButton button("Hello world !");
	button.show();

	return a.exec();
}
