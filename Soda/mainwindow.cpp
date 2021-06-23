#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <cmath>
#include <QDebug>
#include <iostream>
#include <vector>
using namespace std;


MainWindow::MainWindow(Hub *Control, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->Contr = Control;
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::drawGraph(QVector<double> &data, QVector<double> &data2, QVector<double> &data1, QVector<double> &data3, double leftX, double rightX, double N)
{
    int pictHeight = 300;
    int pictWidth = 300;

    double rightY = 1.5;
    double leftY = -0.5;
    double step = fabs(rightX - leftX) / N;

    double onePixelX = double(pictWidth)/(rightX-leftX);
    double onePixelY = double(pictHeight)/(rightY-leftY);
    double Ox = fabs(leftX);
    double Oy = rightY;

    QPixmap graph(pictWidth,pictHeight);
    QPixmap graph1(pictWidth,pictHeight);
    QPixmap graph2(pictWidth,pictHeight);
    QPixmap graph3(pictWidth,pictHeight);
    QPainter paint, paint1, paint2, paint3;
    paint.begin(&graph);
    paint.eraseRect(0,0,pictWidth,pictHeight);
    paint.drawLine(Ox*onePixelX,0,Ox*onePixelX,pictHeight);
    paint.drawLine(0,Oy*onePixelY,pictWidth,Oy*onePixelY);

    paint1.begin(&graph1);
    paint1.eraseRect(0,0,pictWidth,pictHeight);
    paint1.drawLine(Ox*onePixelX,0,Ox*onePixelX,pictHeight);
    paint1.drawLine(0,Oy*onePixelY,pictWidth,Oy*onePixelY);

    paint2.begin(&graph2);
    paint2.eraseRect(0,0,pictWidth,pictHeight);
    paint2.drawLine(Ox*onePixelX,0,Ox*onePixelX,pictHeight);
    paint2.drawLine(0,Oy*onePixelY,pictWidth,Oy*onePixelY);

    paint3.begin(&graph3);
    paint3.eraseRect(0,0,pictWidth,pictHeight);
    paint3.drawLine(Ox*onePixelX,0,Ox*onePixelX,pictHeight);
    paint3.drawLine(0,Oy*onePixelY,pictWidth,Oy*onePixelY);

    paint.setPen(QPen(Qt::black,3));
    paint1.setPen(QPen(Qt::black,3));
    paint2.setPen(QPen(Qt::black,3));
    paint3.setPen(QPen(Qt::black,3));
    for(double i = leftX; i <= rightX; i += (fabs(rightX - leftX) / 10)) {
        paint.drawPoint((i + fabs(leftX)) * onePixelX, Oy * onePixelY);
        paint1.drawPoint((i + fabs(leftX)) * onePixelX, Oy * onePixelY);
        paint2.drawPoint((i + fabs(leftX)) * onePixelX, Oy * onePixelY);
        paint3.drawPoint((i + fabs(leftX)) * onePixelX, Oy * onePixelY);
    }
    for(double i = leftY; i <= rightY; i += (fabs(rightY - leftY) / 10)) {
        paint.drawPoint(Ox*onePixelX, (i + fabs(leftY)) * onePixelY);
        paint1.drawPoint(Ox*onePixelX, (i + fabs(leftY)) * onePixelY);
        paint2.drawPoint(Ox*onePixelX, (i + fabs(leftY)) * onePixelY);
        paint3.drawPoint(Ox*onePixelX, (i + fabs(leftY)) * onePixelY);
    }


//    paint.end();
//    paint1.end();
//    paint2.end();
//    paint3.end();

    ui->outputGraph->setPixmap(graph);
    ui->outputGraph1->setPixmap(graph1);
    ui->outputGraph2->setPixmap(graph2);
    ui->outputGraph3->setPixmap(graph3);

    paint.setPen(QPen(Qt::green,1,Qt::SolidLine));
    paint.setRenderHint(QPainter::Antialiasing, true);
    QPainterPath path, path1, path2, path3;
    bool first = true;
    bool first1 = true;
    bool first2 = true;
    bool first3 = true;

    paint1.setPen(QPen(Qt::green,1,Qt::SolidLine));
    paint1.setRenderHint(QPainter::Antialiasing, true);

    paint2.setPen(QPen(Qt::green,1,Qt::SolidLine));
    paint2.setRenderHint(QPainter::Antialiasing, true);

    paint3.setPen(QPen(Qt::green,1,Qt::SolidLine));
    paint3.setRenderHint(QPainter::Antialiasing, true);

    for (int i = 0; leftX + step * i < rightX; i++) {
        double x = leftX + step * i;
        if (!isnan(data[i])) {
            if (first) {
                path.moveTo((x + Ox) * onePixelX, (-data[i] + Oy) * onePixelY);
                first = false;
            }
            else {
                path.lineTo((x + Ox) * onePixelX, (-data[i] + Oy) * onePixelY);
            }
        }
        if (!isnan(data1[i])) {
            if (first1) {
                path1.moveTo((x + Ox) * onePixelX, (-data1[i] + Oy) * onePixelY);
                first1 = false;
            }
            else {
                path1.lineTo((x + Ox) * onePixelX, (-data1[i] + Oy) * onePixelY);
            }
        }
        if (!isnan(data2[i])) {
            if (first1) {
                path2.moveTo((x + Ox) * onePixelX, (-data2[i] + Oy) * onePixelY);
                first2 = false;
            }
            else {
                path2.lineTo((x + Ox) * onePixelX, (-data2[i] + Oy) * onePixelY);
            }
        }
        if (!isnan(data3[i])) {
            if (first1) {
                path3.moveTo((x + Ox) * onePixelX, (-data3[i] + Oy) * onePixelY);
                first3 = false;
            }
            else {
                path3.lineTo((x + Ox) * onePixelX, (-data3[i] + Oy) * onePixelY);
            }
        }
    }

    paint.setPen(QPen(Qt::blue,1,Qt::SolidLine));
    paint.drawPath(path);
    paint.end();
    ui->outputGraph->setPixmap(graph);

    paint1.setPen(QPen(Qt::blue,1,Qt::SolidLine));
    paint1.drawPath(path1);
    paint1.end();
    ui->outputGraph1->setPixmap(graph1);

    paint2.setPen(QPen(Qt::blue,1,Qt::SolidLine));
    paint2.drawPath(path2);
    paint2.end();
    ui->outputGraph2->setPixmap(graph2);

    paint3.setPen(QPen(Qt::blue,1,Qt::SolidLine));
    paint3.drawPath(path3);
    paint3.end();
    ui->outputGraph3->setPixmap(graph3);
    return;
}

void MainWindow::onPlotclicked()
{
    double leftX = ui->From_text->text().toDouble();
    double rightX = ui->To_text->text().toDouble();
    double gamma = ui->Adibatic_text->text().toDouble();
    double tmax = ui->Time_text->text().toDouble();
    double N = ui->N_text->text().toInt();

    Contr->wasClicked(leftX, rightX, gamma, tmax, N);
}


