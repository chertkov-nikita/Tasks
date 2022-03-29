#ifndef CONTROL_H
#define CONTROL_H

#include <QDialog>
#include "transmitter.h"

namespace Ui {
class Control;
}

class Control : public QDialog
{
    Q_OBJECT

    TTransmitter *general_class;

public:
    explicit Control(QWidget *parent = nullptr);
    explicit Control(TTransmitter*, QWidget *parent = nullptr);
    ~Control();

private slots:
    void on_pushButton_clicked();
    void on_pushButton_3_clicked();

private:
    Ui::Control *ui;
};

#endif // CONTROL_H
