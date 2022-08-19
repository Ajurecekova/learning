#include "autoservis.h"
#include <QtWidgets/QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    autoservis w;
    w.show();
    return a.exec();
}
