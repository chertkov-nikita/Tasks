#include "interface.h"
#include "common.h"

TInterface::TInterface(QWidget *parent)
    : QWidget(parent)
{
    setWindowTitle("Работа №4");
    setFixedSize(300,250);

    numerator_a = new QLabel("a=", this);
    numerator_a->setGeometry(50,20,30,25);
    a_num = new QLineEdit("1", this);
    a_num->setGeometry(90,20,30,25);
    denominator_a = new QLabel("/", this);
    denominator_a->setGeometry(150,20,30,25);
    a_den = new QLineEdit("1", this);
    a_den->setGeometry(190,20,30,25);

    numerator_b = new QLabel("b=", this);
    numerator_b->setGeometry(50,50,30,25);
    b_num = new QLineEdit("1", this);
    b_num->setGeometry(90,50,30,25);
    denominator_b = new QLabel("/", this);
    denominator_b->setGeometry(150,50,30,25);
    b_den = new QLineEdit("1", this);
    b_den->setGeometry(190,50,30,25);

    numerator_c = new QLabel("c=", this);
    numerator_c->setGeometry(50,80,30,25);
    c_num = new QLineEdit("1", this);
    c_num->setGeometry(90,80,30,25);
    denominator_c = new QLabel("/", this);
    denominator_c->setGeometry(150,80,30,25);
    c_den = new QLineEdit("1", this);
    c_den->setGeometry(190,80,30,25);

    numerator_x = new QLabel("x=", this);
    numerator_x->setGeometry(50,110,30,25);
    x_num = new QLineEdit("1", this);
    x_num->setGeometry(90,110,30,25);
    denominator_x = new QLabel("/", this);
    denominator_x->setGeometry(150,110,30,25);
    x_den = new QLineEdit("1", this);
    x_den->setGeometry(190,110,30,25);

    value_btn = new QPushButton("знач.", this);
    value_btn->setGeometry(10,150,60,30);
    root_btn = new QPushButton("корни", this);
    root_btn->setGeometry(80,150,60,30);
    print_classic_btn = new QPushButton("класс.", this);
    print_classic_btn->setGeometry(160,150,60,30);
    print_canonic_btn = new QPushButton("канон.", this);
    print_canonic_btn->setGeometry(230,150,60,30);

    output = new QLabel(this);
    output->setGeometry(10,200,280,25);

    connect(value_btn, SIGNAL(pressed()), this, SLOT(formRequest()));
    connect(root_btn, SIGNAL(pressed()), this, SLOT(formRequest()));
    connect(print_classic_btn, SIGNAL(pressed()), this, SLOT(formRequest()));
    connect(print_canonic_btn, SIGNAL(pressed()), this, SLOT(formRequest()));
}

TInterface::~TInterface()
{
    delete numerator_a;
    delete denominator_a;
    delete a_num;
    delete a_den;

    delete numerator_b;
    delete denominator_b;
    delete b_num;
    delete b_den;

    delete numerator_c;
    delete denominator_c;
    delete c_num;
    delete c_den;

    delete numerator_x;
    delete denominator_x;
    delete x_num;
    delete x_den;

    delete value_btn;
    delete root_btn;
    delete print_canonic_btn;
    delete print_classic_btn;

    delete output;
}

void TInterface::formRequest()
{
    QString msg;
    msg << a_num->text() << a_den->text();
    msg << b_num->text() << b_den->text();
    msg << c_num->text() << c_den->text();
    QPushButton *btn = (QPushButton*)sender();
    if (btn == value_btn)
    {
        msg << QString().setNum(VALUE_REQUEST);
        msg << x_num->text() << x_den->text();
    }
    if (btn == root_btn)
    {
        msg << QString().setNum(ROOTS_REQUEST);
    }
    if (btn == print_classic_btn)
        msg << QString().setNum(PRINT_CLASSIC_REQUEST);
    if (btn == print_canonic_btn)
        msg << QString().setNum(PRINT_CANONIC_REQUEST);
    emit request(msg);
}

void TInterface::answer(QString msg)
{
    QString text;
    int p = msg.indexOf(separator);
    int t = msg.left(p).toInt();
    msg = msg.mid(p+1,msg.length()-p-2);
    switch (t)
    {
        case VALUE_ANSWER:
            text = "p";
            p = msg.indexOf(separator);
            text += msg.left(p);
            text += " = ";
            text += msg.right(msg.length()-p-1);
            output->setText(text);
            break;
        case ROOTS_ANSWER:
            text = "roots: ";
            p = msg.indexOf(separator);
            text += msg.left(p);
            text += "  ";
            text += msg.right(msg.length()-p-1);
            output->setText(text);
            break;
        case PRINT_ANSWER:
            text = "p(x) = ";
            text += msg;
            output->setText(text);
            break;
        default: break;
    }
}
