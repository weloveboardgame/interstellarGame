#include "igwindow.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    IGWindow w;
    w.show();
    return a.exec();
}
