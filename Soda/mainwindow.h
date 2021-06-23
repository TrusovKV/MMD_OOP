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
    class Axis
    {
    public:
        Axis() :
            valid(false)
        {}
        Axis(QString const& label_, int nd_ = 10) :
            label(label_),
            number_divisions(nd_),
            valid(true)
        {}
        Axis(Axis const& r) :
            label(r.label),
            number_divisions(r.number_divisions),
            valid(r.valid)
        {}
        Axis(Axis&& r) :
            label(std::move(r.label))
        {
            std::swap(number_divisions, r.number_divisions);
            std::swap(valid, r.valid);
        }
        Axis& operator=(Axis const& r)
        {
            label = r.label;
            number_divisions = r.number_divisions;
            valid = r.valid;

            return *this;
        }
        Axis& operator=(Axis&& r)
        {
            label = std::move(r.label);
            std::swap(number_divisions, r.number_divisions);
            std::swap(valid, r.valid);

            return *this;
        }
        ~Axis() {}
        QString getLabel() { return label; }
        qreal getNumberDivisions() { return number_divisions; }

        bool isValid() { return valid; }

private:
    QString label;
    int number_divisions;
    bool valid;


};
    void setAxes(Axis const& x, Axis const& y);
    void setGraphPoints(QVector<QPointF> const& points);
private:
    Ui::MainWindow *ui;
    Axis axis_x;
    Axis axis_y;
    QVector<QPointF> graphPoints;
};
#endif // MAINWINDOW_H
