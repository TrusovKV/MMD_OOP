#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#pragma once
#include <QPen>
#include <QWidget>
#include <QPainter>
#include <QFrame>
#include <QVector>
#include <QSharedPointer>
#include <QMainWindow>
#include "hub.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(Hub *hb, QWidget *parent = nullptr);
    ~MainWindow();
    Hub *hb;
    void drawAxes();
    void drawGraphs();
    QVector<QPointF> pointsP;
        QVector<QPointF> pointsT;
            QVector<QPointF> pointsU;
                QVector<QPointF> pointsR;
                double numberDivisions;



private:
    Ui::MainWindow *ui;

    QVector<QPointF> graphPoints;

private:
    QString label;
    int number_divisions;
    bool valid;


    void setGraphPoints(    QVector<QPointF> const & pointsP,
    QVector<QPointF> const & pointsT,
        QVector<QPointF> const & pointsU,
            QVector<QPointF> const & pointsR);
};
#endif // MAINWINDOW_H
