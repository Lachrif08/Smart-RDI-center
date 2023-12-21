/********************************************************************************
** Form generated from reading UI file 'pdf.ui'
**
** Created by: Qt User Interface Compiler version 5.9.9
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PDF_H
#define UI_PDF_H

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

class Ui_pdf
{
public:
    QLineEdit *le_pdf_cin;
    QLabel *lab_c;
    QPushButton *pushButton_7;

    void setupUi(QWidget *pdf)
    {
        if (pdf->objectName().isEmpty())
            pdf->setObjectName(QStringLiteral("pdf"));
        pdf->resize(957, 270);
        pdf->setStyleSheet(QStringLiteral("background-color: rgb(255, 255, 255);"));
        le_pdf_cin = new QLineEdit(pdf);
        le_pdf_cin->setObjectName(QStringLiteral("le_pdf_cin"));
        le_pdf_cin->setGeometry(QRect(250, 90, 501, 51));
        QFont font;
        font.setFamily(QStringLiteral("Yu Gothic UI Light"));
        font.setPointSize(12);
        le_pdf_cin->setFont(font);
        le_pdf_cin->setStyleSheet(QLatin1String("border-radius: 10px;\n"
"background: #F5F5F5;\n"
"border: 1px solid #000000;\n"
"padding-bottom:7px;"));
        lab_c = new QLabel(pdf);
        lab_c->setObjectName(QStringLiteral("lab_c"));
        lab_c->setGeometry(QRect(160, 80, 61, 61));
        QFont font1;
        font1.setFamily(QStringLiteral("Yu Gothic UI Semibold"));
        font1.setPointSize(20);
        font1.setBold(true);
        font1.setWeight(75);
        lab_c->setFont(font1);
        lab_c->setStyleSheet(QStringLiteral("text-align:center;"));
        pushButton_7 = new QPushButton(pdf);
        pushButton_7->setObjectName(QStringLiteral("pushButton_7"));
        pushButton_7->setGeometry(QRect(790, 90, 51, 51));
        QFont font2;
        font2.setFamily(QStringLiteral("Yu Gothic UI Semibold"));
        font2.setPointSize(12);
        font2.setBold(true);
        font2.setWeight(75);
        pushButton_7->setFont(font2);
        pushButton_7->setCursor(QCursor(Qt::PointingHandCursor));
        pushButton_7->setStyleSheet(QLatin1String("QPushButton {\n"
"background-color: rgb(0, 213, 24);\n"
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
        pushButton_7->setIcon(icon);
        pushButton_7->setIconSize(QSize(30, 30));
        pushButton_7->setFlat(true);

        retranslateUi(pdf);

        QMetaObject::connectSlotsByName(pdf);
    } // setupUi

    void retranslateUi(QWidget *pdf)
    {
        pdf->setWindowTitle(QApplication::translate("pdf", "Form", Q_NULLPTR));
        lab_c->setText(QApplication::translate("pdf", "CIN", Q_NULLPTR));
        pushButton_7->setText(QString());
    } // retranslateUi

};

namespace Ui {
    class pdf: public Ui_pdf {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PDF_H
