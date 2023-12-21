/********************************************************************************
** Form generated from reading UI file 'form.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_FORM_H
#define UI_FORM_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Form
{
public:
    QLineEdit *le_dn;
    QLabel *lab_c;
    QPushButton *pushButton_7;
    QLabel *label_vs;

    void setupUi(QWidget *Form)
    {
        if (Form->objectName().isEmpty())
            Form->setObjectName(QStringLiteral("Form"));
        Form->resize(799, 321);
        Form->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        le_dn = new QLineEdit(Form);
        le_dn->setObjectName(QStringLiteral("le_dn"));
        le_dn->setGeometry(QRect(190, 120, 481, 61));
        le_dn->setStyleSheet(QLatin1String("border-radius: 10px;\n"
"background: #F5F5F5;\n"
"border: 1px solid #000000;\n"
"padding-bottom:7px;"));
        lab_c = new QLabel(Form);
        lab_c->setObjectName(QStringLiteral("lab_c"));
        lab_c->setGeometry(QRect(110, 110, 61, 61));
        QFont font;
        font.setFamily(QStringLiteral("Yu Gothic UI Semibold"));
        font.setPointSize(20);
        font.setBold(true);
        font.setWeight(75);
        lab_c->setFont(font);
        pushButton_7 = new QPushButton(Form);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(700, 120, 61, 61));
        QFont font1;
        font1.setFamily(QStringLiteral("Yu Gothic UI Semibold"));
        font1.setPointSize(12);
        font1.setBold(true);
        font1.setWeight(75);
        pushButton_7->setFont(font1);
        pushButton_7->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_7->setStyleSheet(QLatin1String("QPushButton {\n"
"background:rgb(11, 229, 0);\n"
"color:white;\n"
"border-radius: 30px;\n"
"}\n"
"\n"
"QPushButton::hover\n"
"{\n"
"background:rgb(31, 147, 0);\n"
"color:white;\n"
"border-radius: 30px;\n"
"\n"
"}"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/icon/icons/icons8-ok-64.png"), QSize(), QIcon::Normal, QIcon::Off);
        pushButton_7->setIcon(icon);
        pushButton_7->setIconSize(QSize(50, 50));
        label_vs = new QLabel(Form);
        label_vs->setObjectName(QStringLiteral("label_vs"));
        label_vs->setGeometry(QRect(20, 50, 591, 31));
        QFont font2;
        font2.setPointSize(18);
        label_vs->setFont(font2);
        label_vs->setStyleSheet(QLatin1String("\n"
"color: rgb(0, 18, 122);"));

        retranslateUi(Form);

        QMetaObject::connectSlotsByName(Form);
    } // setupUi

    void retranslateUi(QWidget *Form)
    {
        Form->setWindowTitle(QApplication::translate("Form", "Form", Q_NULLPTR));
        lab_c->setText(QApplication::translate("Form", "CIN", Q_NULLPTR));
        pushButton_7->setText(QString());
        label_vs->setText(QApplication::translate("Form", "Veuillez saisr le CIN de l'mploye", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Form: public Ui_Form {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_FORM_H
