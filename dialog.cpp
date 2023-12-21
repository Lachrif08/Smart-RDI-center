#include "dialog.h"
#include "ui_dialog.h"

#include "ui_pdf.h"
#include <QTextStream>
#include <QDir>
#include <QPainter>
#include <QPdfWriter>
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlRecord>
#include <QStandardPaths>
#include <QDate>
Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);
}

Dialog::~Dialog()
{
    delete ui;
}



void Dialog::on_pushButton_clicked()
{

    QSqlQuery query;

    QDate currentDate = QDate::currentDate();
       QString dateString = currentDate.toString("dd/MM/yyyy");
    // Get path to user's Documents folder
       QString documentsDir = QStandardPaths::writableLocation(QStandardPaths::DocumentsLocation);

       // Create directory if it doesn't already exist
       QDir dir(documentsDir);
       if (!dir.exists("Evolve_app")) {
           dir.mkdir("Evolve_app");
       }

      int cin = ui->le_pdf_cin->text().toInt();

          query.prepare("SELECT NOM,PRENOM FROM EMPLOYE WHERE CIN = :cin");
          query.bindValue(":cin", cin);
          query.exec();
          query.next();
          QString name = query.value(0).toString();
          QString prenom = query.value(1).toString();
           QString cin_s = QString::number(cin);

          // Create PDF file
           QString fileName = QString("%1/Atestation_%2.pdf").arg(documentsDir + "/Evolve_app", QString::number(cin));
           QPdfWriter writer(fileName);
           writer.setPageSize(QPageSize(QPageSize::A4));
           QPainter painter(&writer);

          // Draw logo
          QImage logo(":/images/images/Capture3.PNG");
          painter.drawImage(QRect(250, 150, 2999, 788), logo);

          // Draw text
          QFont font("Helvetica", 12);
          painter.setFont(font);
          painter.drawText(QRect(1500, 3500, 8000, 5000), Qt::AlignLeft | Qt::AlignVCenter,
                           QString("Evolve atteste officiellement que l'employe travail avec nous a Rue Evolve.\nIl a donc le droit de recoivr tout les avanteges se rapportant a son poste  \nle %1 \n").arg(dateString));

          // Draw user name
          painter.drawText(QRect(1800, 8000, 1200, 1200), Qt::AlignLeft | Qt::AlignVCenter,
                           QString("Cin: %1").arg(cin));

          painter.end();
}
