/********************************************************************************
** Form generated from reading UI file 'Chatboxconnectiondialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CHATBOXCONNECTIONDIALOG_H
#define UI_CHATBOXCONNECTIONDIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QDialogButtonBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QSpinBox>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QDialogButtonBox *buttonBox;
    QLabel *label;
    QSpinBox *port;
    QLineEdit *hostname;
    QLabel *label_2;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(487, 295);
        Dialog->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        buttonBox = new QDialogButtonBox(Dialog);
        buttonBox->setObjectName(QStringLiteral("buttonBox"));
        buttonBox->setGeometry(QRect(270, 230, 151, 51));
        buttonBox->setMinimumSize(QSize(51, 51));
        buttonBox->setStyleSheet(QLatin1String("QDialogButtonBox {\n"
"background:rgb(0, 102, 255);\n"
"color:white;\n"
"\n"
"}\n"
"\n"
"QDialogButtonBox::hover\n"
"{\n"
"background:rgb(0, 51, 162);\n"
"color:white;\n"
"\n"
"\n"
"}"));
        buttonBox->setOrientation(Qt::Horizontal);
        buttonBox->setStandardButtons(QDialogButtonBox::Cancel|QDialogButtonBox::Ok);
        label = new QLabel(Dialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(60, 80, 101, 24));
        QFont font;
        font.setFamily(QStringLiteral("Yu Gothic UI Semibold"));
        font.setPointSize(12);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        port = new QSpinBox(Dialog);
        port->setObjectName(QStringLiteral("port"));
        port->setGeometry(QRect(186, 81, 251, 31));
        port->setStyleSheet(QLatin1String("border-radius: 10px;\n"
"background: #F5F5F5;\n"
"border: 1px solid rgb(19, 113, 255);\n"
"padding-bottom:7px;"));
        port->setMaximum(9999);
        port->setValue(3333);
        hostname = new QLineEdit(Dialog);
        hostname->setObjectName(QStringLiteral("hostname"));
        hostname->setGeometry(QRect(180, 170, 264, 31));
        hostname->setStyleSheet(QLatin1String("border-radius: 10px;\n"
"background: #F5F5F5;\n"
"border: 1px solid rgb(19, 113, 255);\n"
"padding-bottom:7px;"));
        label_2 = new QLabel(Dialog);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(60, 170, 111, 25));
        label_2->setFont(font);

        retranslateUi(Dialog);
        QObject::connect(buttonBox, SIGNAL(accepted()), Dialog, SLOT(accept()));
        QObject::connect(buttonBox, SIGNAL(rejected()), Dialog, SLOT(reject()));

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("Dialog", "Hostname :", Q_NULLPTR));
        hostname->setText(QApplication::translate("Dialog", "localhost", Q_NULLPTR));
        label_2->setText(QApplication::translate("Dialog", "Port :", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CHATBOXCONNECTIONDIALOG_H
