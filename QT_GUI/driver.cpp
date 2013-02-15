#include "driver.h"
#include "ui_driver.h"

Driver::Driver(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Driver)
{
    ui->setupUi(this);
    setWindowTitle("REMOTE Driver(v0.1)");



}

Driver::~Driver()
{
    delete ui;
}



void Driver::on_pushButton_clicked()
{
    if(ui->radioButton->isChecked())
    {
        pid=fork();
        if(pid==0)
        {
            execv("/home/karthic/mydata/codes/project/remoteserver/gui_client/execs/exec3",0);
        }
        ui->pushButton->setDisabled(1);
        sleep(3);
        ui->pushButton->setEnabled(1);
    }
    if(ui->radioButton_2->isChecked())
    {
        pid=fork();
        if(pid==0)
        {
            execv("/home/karthic/mydata/codes/project/remoteserver/gui_client/execs/exec4",0);
        }
        ui->pushButton->setDisabled(1);
        sleep(3);
        ui->pushButton->setEnabled(1);
    }
}
