#include "control.h"
#include "ui_control.h"


Control::Control(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Control)
{
    ui->setupUi(this);
}

Control::Control(TTransmitter *interface,QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Control)
{
    general_class = interface;
    ui->setupUi(this);
}

Control::~Control()
{
    delete ui;
}


void Control::on_pushButton_clicked()
{
    general_class->formRequest("ADD EMP");
}

void Control::on_pushButton_3_clicked()
{
    general_class->formRequest("DEL EMP");
}
