#ifndef SETTINGS_H
#define SETTINGS_H

#include <QDialog>
#include "transmitter.h"

namespace Ui {
class Settings;
}

class Settings : public QDialog
{
    Q_OBJECT

    TTransmitter *general_class;

public:
    explicit Settings(QWidget *parent = nullptr);
    explicit Settings(TTransmitter*, QWidget *parent = nullptr);
    ~Settings();

private slots:
    void on_buttonBox_accepted();

private:
    Ui::Settings *ui;
};

#endif // SETTINGS_H
