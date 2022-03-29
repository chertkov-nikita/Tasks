/********************************************************************************
** Form generated from reading UI file 'control.ui'
**
** Created by: Qt User Interface Compiler version 6.0.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONTROL_H
#define UI_CONTROL_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QDialog>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Control
{
public:
    QPushButton *pushButton;
    QPushButton *pushButton_3;

    void setupUi(QDialog *Control)
    {
        if (Control->objectName().isEmpty())
            Control->setObjectName(QString::fromUtf8("Control"));
        Control->resize(501, 245);
        pushButton = new QPushButton(Control);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));
        pushButton->setGeometry(QRect(40, 60, 421, 61));
        pushButton_3 = new QPushButton(Control);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));
        pushButton_3->setGeometry(QRect(40, 130, 421, 61));

        retranslateUi(Control);

        QMetaObject::connectSlotsByName(Control);
    } // setupUi

    void retranslateUi(QDialog *Control)
    {
        Control->setWindowTitle(QCoreApplication::translate("Control", "\320\236\320\272\320\275\320\276 \321\203\320\277\321\200\320\260\320\262\320\273\320\265\320\275\320\270\321\217", nullptr));
        pushButton->setText(QCoreApplication::translate("Control", "\320\224\320\276\320\261\320\260\320\262\320\270\321\202\321\214 \321\201\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272\320\260", nullptr));
        pushButton_3->setText(QCoreApplication::translate("Control", "\320\222\321\213\320\264\320\260\321\202\321\214 \320\267\320\260\321\200\320\277\320\273\320\260\321\202\321\213 \321\201\320\276\321\202\321\200\321\203\320\264\320\275\320\270\320\272\320\260\320\274 \320\275\320\260 \320\272\320\260\321\201\321\201\320\260\321\205", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Control: public Ui_Control {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONTROL_H
