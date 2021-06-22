#include "mainwindow.h"
#include "solver.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Solver parasol;
    Hub hb;
    MainWindow w;
    w.show();
    return a.exec();
}
