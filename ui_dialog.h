/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>

QT_BEGIN_NAMESPACE

class Ui_Dialog
{
public:
    QLabel *label;
    QLineEdit *le_pdf_cin;
    QPushButton *pushButton;
    QLabel *lab_dn;

    void setupUi(QDialog *Dialog)
    {
        if (Dialog->objectName().isEmpty())
            Dialog->setObjectName(QStringLiteral("Dialog"));
        Dialog->resize(590, 316);
        label = new QLabel(Dialog);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(140, 150, 51, 21));
        QFont font;
        font.setFamily(QStringLiteral("Yu Gothic UI Semibold"));
        font.setPointSize(16);
        font.setBold(true);
        font.setWeight(75);
        label->setFont(font);
        le_pdf_cin = new QLineEdit(Dialog);
        le_pdf_cin->setObjectName(QStringLiteral("le_pdf_cin"));
        le_pdf_cin->setGeometry(QRect(200, 140, 181, 41));
        le_pdf_cin->setStyleSheet(QLatin1String("border-radius: 10px;\n"
"background: #F5F5F5;\n"
"border: 1px solid #000000;\n"
"padding-bottom:7px;"));
        pushButton = new QPushButton(Dialog);
        pushButton->setObjectName(QStringLiteral("pushButton"));
        pushButton->setGeometry(QRect(410, 130, 51, 51));
        pushButton->setStyleSheet(QLatin1String("QPushButton {\n"
"background:rgb(11, 229, 0);\n"
"color:white;\n"
"border-radius: 25px;\n"
"}\n"
"\n"
"QPushButton::hover\n"
"{\n"
"background:rgb(31, 147, 0);\n"
"color:white;\n"
"border-radius: 25px;\n"
"\n"
"}"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icon/icons/icons8-ok-64.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton->setIcon(icon);
        pushButton->setIconSize(QSize(50, 50));
        pushButton->setFlat(true);
        lab_dn = new QLabel(Dialog);
        lab_dn->setObjectName(QStringLiteral("lab_dn"));
        lab_dn->setGeometry(QRect(40, 50, 581, 61));
        QFont font1;
        font1.setFamily(QStringLiteral("Yu Gothic UI Semibold"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        lab_dn->setFont(font1);
        lab_dn->setStyleSheet(QStringLiteral("color: rgb(10, 0, 122);"));

        retranslateUi(Dialog);

        QMetaObject::connectSlotsByName(Dialog);
    } // setupUi

    void retranslateUi(QDialog *Dialog)
    {
        Dialog->setWindowTitle(QApplication::translate("Dialog", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("Dialog", "CIN", Q_NULLPTR));
        pushButton->setText(QString());
        lab_dn->setText(QApplication::translate("Dialog", "Veuillez saisir le CIN de l'employe demandant un attestation de travail:", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Dialog: public Ui_Dialog {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
