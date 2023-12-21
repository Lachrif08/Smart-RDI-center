#include "equipements.h"
#include<QString>
#include<QSqlQuery>
#include<QDebug>
#include<QTableView>
#include<QtPrintSupport/QPrinter>
#include<QPainter>
#include<QRect>
#include<QPrinter>

Equipements::Equipements()
{
    id_equipement=0; qantite=0; nom=""; marque="";
}

Equipements::Equipements(int id_equipement, int qantite, QString nom, QString marque)
{
    this->id_equipement=id_equipement;
    this->qantite=qantite;
    this->nom=nom;
    this->marque=marque;
}
Equipements::Equipements(int ID)
{
    this->id_equipement=ID;

   }
int Equipements::getID(){return id_equipement;}
int Equipements::getQantite(){return qantite;}
QString Equipements::getNom(){return nom;}
QString Equipements::getMarque(){return marque;}

void Equipements::setNom(QString n){nom=n;}
void Equipements::setMarque(QString m){marque=m;}
void Equipements::setID(int id_equipement){this->id_equipement=id_equipement;}
void Equipements::setQantite(int qantite){this->qantite=qantite;}

bool Equipements::ajouter()
{
    QSqlQuery query;
    QString id_qan= QString::number(id_equipement);
    query.prepare("INSERT INTO EQUIPEMENT (ID_EQUIPEMENT,QANTITE,NOM,MARQUE)" "VALUES (:id_equipement,:qantite,:nom,:marque)");
    query.bindValue(":id_equipement",id_equipement);
    query.bindValue(":qantite",qantite);
    query.bindValue(":nom",nom);
    query.bindValue(":marque",marque);
    return query.exec();
}


bool Equipements::supprimer(int id_equipement)
{
    QSqlQuery query;
    QString id_eq= QString::number(id_equipement);
    query.prepare("DELETE FROM EQUIPEMENT WHERE id_equipement= :id_equipement");
    query.bindValue(":id_equipement",id_eq);
    return query.exec();
}

bool Equipements::modifier(int id)
{
    QSqlQuery query;
         QString id_string= QString::number(id);
         QString quanitte_string= QString::number(qantite);

        //requette sqls
        query.prepare("UPDATE EQUIPEMENT set ID_EQUIPEMENT=:id_e,QANTITE=:q,NOM=:n,MARQUE=:m WHERE ID_EQUIPEMENT=:id_e");

        //saisir de donnee
        query.bindValue(":id_e",id_string);
        query.bindValue(":q",quanitte_string);
        query.bindValue(":n",nom);
        query.bindValue(":m",marque);



        //execution de la requette
        return query.exec();
}
bool Equipements::existance()
{
    bool alreadyExist = false;
    {
    QSqlQuery query;
    query.prepare("SELECT * FROM EQUIPEMENT WHERE id_equipement= :id_equipement");
    query.bindValue(":id_equipement",id_equipement);
    if(!query.exec()){
    }
    alreadyExist = query.next();
    }
    return alreadyExist;
}
void exportToPdf(QTableView *tableView, const QString& fileName)
{
    QPrinter printer(QPrinter::PrinterResolution);
    printer.setOutputFormat(QPrinter::PdfFormat);
    printer.setOutputFileName(fileName);

    QPainter painter;
    if (!painter.begin(&printer)) {
        return;
    }

    // Set up the table
    int rowHeight = 30;
    int headerHeight = 50;
    int columnWidth = 90;
    int margin = 30;
    int numRows = tableView->model()->rowCount();
    int numCols = tableView->model()->columnCount();
    QRect tableRect(margin, margin + headerHeight, columnWidth * numCols, rowHeight * numRows);


    // Draw the header row
    painter.setFont(QFont("Arial", 10, QFont::Bold));
    painter.drawText(QRectF(margin, margin, columnWidth, headerHeight), Qt::AlignCenter, "ID_EQUIPEMENT");
    painter.drawText(QRectF(margin + columnWidth, margin, columnWidth, headerHeight), Qt::AlignCenter, "QANTITE");
    painter.drawText(QRectF(margin + 2 * columnWidth, margin, columnWidth, headerHeight), Qt::AlignCenter, "NOM");
    painter.drawText(QRectF(margin + 3 * columnWidth, margin, columnWidth, headerHeight), Qt::AlignCenter, "MARQUE");


    // Draw the table cells
    painter.setFont(QFont("Arial", 6));
       for (int row = 0; row < numRows; ++row) {
           for (int col = 0; col < numCols; ++col) {
               QRectF cellRect(margin + col * columnWidth, margin + headerHeight + row * rowHeight, columnWidth, rowHeight);
               painter.drawRect(cellRect);
               painter.drawText(cellRect, Qt::AlignCenter, tableView->model()->data(tableView->model()->index(row, col)).toString());
           }
    }

    painter.end();
}
QSqlQueryModel * Equipements::afficher(QString elm,QString sc)
{ Equipements E;
    QString queryText = "SELECT * FROM EQUIPEMENT";
    QSqlQueryModel * model = new QSqlQueryModel();
    if ((elm != "") and (sc != ""))
    queryText = "SELECT * FROM EQUIPEMENT ORDER BY "+elm+" "+ sc;
    model->setQuery(queryText);

    model->setHeaderData(0,Qt::Horizontal,QObject::tr("ID_EQUIPEMENT"));
    model->setHeaderData(1,Qt::Horizontal,QObject::tr("QANTITE"));
    model->setHeaderData(2,Qt::Horizontal,QObject::tr("NOM"));
    model->setHeaderData(3,Qt::Horizontal,QObject::tr("MARQUE"));
    return model;
}

