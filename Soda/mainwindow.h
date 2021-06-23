#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <hub.h>

#include <QMainWindow>
#include <QtGui>

namespace Ui {
    class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(Hub *Control, QWidget *parent = 0);
    ~MainWindow();
    Hub *Contr;
    void drawGraph(QVector<double> &data, QVector<double> &data2, QVector<double> &data1, QVector<double> &data3, double leftX, double rightX, double N);
private slots:
    void onPlotclicked();
private:
    Ui::MainWindow *ui;
};

#endif // MAINWINDOW_H
