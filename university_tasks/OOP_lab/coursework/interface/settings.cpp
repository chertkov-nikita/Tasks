#include "settings.h"
#include "ui_settings.h"

Settings::Settings(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
}

Settings::Settings(TTransmitter *interface, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Settings)
{
    general_class = interface;
    ui->setupUi(this);
}

Settings::~Settings()
{
    delete ui;
}

void Settings::on_buttonBox_accepted()
{
    general_class->formRequest("CH SETT", QString().setNum(ui->spinBox->value()));
}
