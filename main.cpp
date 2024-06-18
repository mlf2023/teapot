#include <QApplication>
#include <QMainWindow>
#include "myglwidget.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QMainWindow w;

    MyGLWidget *glWidget = new MyGLWidget();
    w.setCentralWidget(glWidget);
    w.resize(800,600);
    w.show();
    return a.exec();
}
