#include "mainwindow.h"
#include "solver.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Solver parasol;
    Hub hb(&parasol);
    MainWindow w(&hb);
    parasol.subscribtion(&w);
    w.show();
    return a.exec();
}
