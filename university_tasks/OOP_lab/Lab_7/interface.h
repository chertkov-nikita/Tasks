#ifndef INTERFACE_H
#define INTERFACE_H

#include <QWidget>

QT_BEGIN_NAMESPACE
namespace Ui { class interface; }
QT_END_NAMESPACE

class interface : public QWidget
{
    Q_OBJECT

public:
    interface(QWidget *parent = nullptr);
    ~interface();

QString fileName = "";
bool checkFile();
QString sMatrix;
public slots:
void on_loadFileButton_clicked();
void on_paintButton_clicked();
private:
    Ui::interface *ui;
};
#endif // INTERFACE_H
