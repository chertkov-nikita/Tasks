#ifndef STATUS_H
#define STATUS_H

#include <QDialog>
#include "transmitter.h"

namespace Ui {
class Status;
}

class Status : public QDialog
{
    Q_OBJECT

    TTransmitter *general_class;


public:
    explicit Status(QWidget *parent = nullptr);
    explicit Status(TTransmitter*, QWidget *parent = nullptr);
    ~Status();

private slots:
    void on_pushButton_clicked();

    void on_pushButton_2_clicked();

private:
    Ui::Status *ui;
};

#endif // STATUS_H
