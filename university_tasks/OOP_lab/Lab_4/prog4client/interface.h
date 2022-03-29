#ifndef INTERFACE_H
#define INTERFACE_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>

class TInterface : public QWidget
{
    Q_OBJECT

    QLabel *numerator_a, *denominator_a;
    QLineEdit *a_num, *a_den;
    QLabel *numerator_b, *denominator_b;
    QLineEdit *b_num, *b_den;
    QLabel *numerator_c, *denominator_c;
    QLineEdit *c_num, *c_den;
    QLabel *numerator_x, *denominator_x;
    QLineEdit *x_num, *x_den;

    QPushButton *value_btn;
    QPushButton *root_btn;
    QPushButton *print_classic_btn;
    QPushButton *print_canonic_btn;

    QLabel *output;

//    friend QString& operator<< (QString&,const QString&);

public:
    TInterface(QWidget *parent = 0);
    ~TInterface();

public slots:
    void answer(QString);

private slots:
    void formRequest();

signals:
    void request(QString);

};

#endif // INTERFACE_H
