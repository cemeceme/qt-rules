
#include <QtWidgets/QApplication>

#include <iostream>

#include "qtHeader.h"

using namespace std;

int main(int argc, char** argv)
{
	cout << "Test1 " << endl;
	QApplication app(argc, argv);

	cout << "Test2 " << endl;
	testWindow window;
	window.setWindowTitle("TestWindow");
	cout << "Test3 " << endl;
	window.show();
	return(app.exec());
}