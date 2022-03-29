/********************************************************************************
** Form generated from reading UI file 'interface.ui'
**
** Created by: Qt User Interface Compiler version 6.0.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_INTERFACE_H
#define UI_INTERFACE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_interface
{
public:
    QPushButton *loadFileButton;
    QPushButton *paintButton;
    QLabel *namefile;
    QSpinBox *spinBox;
    QLabel *label;

    void setupUi(QWidget *interface)
    {
        if (interface->objectName().isEmpty())
            interface->setObjectName(QString::fromUtf8("interface"));
        interface->setEnabled(true);
        interface->resize(442, 242);
        loadFileButton = new QPushButton(interface);
        loadFileButton->setObjectName(QString::fromUtf8("loadFileButton"));
        loadFileButton->setGeometry(QRect(50, 80, 261, 41));
        paintButton = new QPushButton(interface);
        paintButton->setObjectName(QString::fromUtf8("paintButton"));
        paintButton->setGeometry(QRect(50, 140, 261, 41));
        namefile = new QLabel(interface);
        namefile->setObjectName(QString::fromUtf8("namefile"));
        namefile->setGeometry(QRect(10, 30, 401, 21));
        spinBox = new QSpinBox(interface);
        spinBox->setObjectName(QString::fromUtf8("spinBox"));
        spinBox->setGeometry(QRect(240, 190, 71, 21));
        spinBox->setMinimum(1);
        spinBox->setStepType(QAbstractSpinBox::DefaultStepType);
        spinBox->setValue(1);
        label = new QLabel(interface);
        label->setObjectName(QString::fromUtf8("label"));
        label->setGeometry(QRect(170, 190, 61, 20));

        retranslateUi(interface);

        QMetaObject::connectSlotsByName(interface);
    } // setupUi

    void retranslateUi(QWidget *interface)
    {
        interface->setWindowTitle(QCoreApplication::translate("interface", "\320\240\320\260\320\261\320\276\321\202\320\260#7", nullptr));
        loadFileButton->setText(QCoreApplication::translate("interface", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \321\204\320\260\320\271\320\273", nullptr));
        paintButton->setText(QCoreApplication::translate("interface", "\320\236\321\202\321\200\320\270\321\201\320\276\320\262\320\260\321\202\321\214 \320\263\321\200\320\260\321\204", nullptr));
        namefile->setText(QCoreApplication::translate("interface", "TextLabel", nullptr));
        label->setText(QCoreApplication::translate("interface", "active top", nullptr));
    } // retranslateUi

};

namespace Ui {
    class interface: public Ui_interface {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_INTERFACE_H
