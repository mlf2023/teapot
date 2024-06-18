#include "myglwidget.h"
#include <GL/glut.h>

MyGLWidget::MyGLWidget(QWidget *parent)
    : QOpenGLWidget(parent)
{
}

MyGLWidget::~MyGLWidget()
{
}

void MyGLWidget::initializeGL()
{
    initializeOpenGLFunctions();
    glEnable(GL_DEPTH_TEST);
    glClearColor(0.0f, 0.0f, 0.0f, 1.0f);

    // 初始化GLUT
    int argc = 0;
    char *argv[] = { (char*)"" };
    glutInit(&argc, argv);
}

void MyGLWidget::resizeGL(int w, int h)
{
    glViewport(0, 0, w, h);
    projection.setToIdentity();
    projection.perspective(45.0f, GLfloat(w) / h, 0.01f, 100.0f);
}

void MyGLWidget::paintGL()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    glLoadMatrixf(projection.data());

    glTranslatef(0.0f, 0.0f, -5.0f);
    glRotatef(30, 1.0f, 0.0f, 0.0f);
    glRotatef(30, 0.0f, 1.0f, 0.0f);

    renderTeapot();
}

void MyGLWidget::renderTeapot()
{
    glColor3f(1.0f, 1.0f, 1.0f); // 设置茶壶颜色为白色
    glutSolidTeapot(1.0); // 绘制一个半径为1.0的茶壶
}
