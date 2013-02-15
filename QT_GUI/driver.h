#ifndef DRIVER_H
#define DRIVER_H

#include <QWidget>
#include<unistd.h>
#include<time.h>

namespace Ui {
class Driver;
}

class Driver : public QWidget
{
    Q_OBJECT
    
public:
    explicit Driver(QWidget *parent = 0);
    ~Driver();
    
private slots:

    void on_pushButton_clicked();

private:
    Ui::Driver *ui;
    pid_t pid;
};

#endif // DRIVER_H
