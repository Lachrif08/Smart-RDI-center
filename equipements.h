#ifndef EQUIPEMENTS_H
#define EQUIPEMENTS_H
#include<QtSql/QSqlQuery>
#include<QtSql/QSqlQueryModel>
#include<QString>
#include<QSqlQuery>
#include<QTableView>
 void exportToPdf(QTableView *tableView, const QString& fileName);
class Equipements
{
public:
    Equipements();
    Equipements(int,int,QString,QString);
    Equipements(int);
    QString getNom();
    QString getMarque();
    int getQantite();
    int getID();

    void setNom(QString );
    void setMarque(QString );
    void setID(int);
    void setQantite(int);

    bool ajouter();
    QSqlQueryModel * afficher(QString,QString);
    bool supprimer(int);
    bool modifier(int cin);
    bool existance();

private:

    int id_equipement, qantite;
        QString nom,marque;


};

#endif // EQUIPEMENTS_H
