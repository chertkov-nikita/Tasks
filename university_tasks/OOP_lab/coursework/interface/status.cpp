#include "status.h"
#include "ui_status.h"

Status::Status(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Status)
{
    ui->setupUi(this);
}

Status::Status(TTransmitter *interface, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Status)
{
    general_class = interface;
    ui->setupUi(this);

    general_class->formRequest("GET DATA");
}

Status::~Status()
{
    delete ui;
}

void Status::on_pushButton_clicked()
{
    general_class->formRequest("GET DATA");
}

void Status::on_pushButton_2_clicked()
{
    ui->textBrowser->clear();
    QString str;
    QStringList data = general_class->get_response().split(';');

    for (int i = 1; i <= data[0].toInt(); i++)
    {
        str = "Касса №"; str += QString().setNum(i); str += "  Очередь в кассу "; str += data[i]; str += " чел.\n";
        ui->textBrowser->append(str);
    }
}
