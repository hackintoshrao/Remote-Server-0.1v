#include <QtGui/QApplication>
#include "driver.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Driver w;
    w.show();
    
    return a.exec();
}
