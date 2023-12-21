#ifndef EMPLOYE_H
#define EMPLOYE_H

#include <QString>
#include <QSqlQuery>
#include<QSqlQueryModel>
#include <QTableView>
#include <QString>
#include <QSqlQuery>
#include <QSqlQueryModel>
#include <QDoubleValidator>
#include <QtDebug>
#include <QObject>
#include <QMainWindow>
#include <QDateTime>
#include <QFile>
#include <QMessageBox>
#include <QDate>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>


class employe
{
    public:
        employe();
        employe(int cin_p,QString nom_p,QString prenom_p,QString date_emb_p,QString date_n_p,float salaire_p,QString email_p,QString mdp_p, QString adresse_p,QString role_p,int idP,QString genre_p,QString img_p);


        //cin
        int Getcin() { return cin; }
        void Setcin(int val) { cin = val; }
        //nom
        QString Getnom() { return nom; }
        void Setnom(QString val) { nom = val; }
        //prenom
        QString Getprenom() { return prenom; }
        void Setprenom(QString val) { prenom = val; }
        //date_emb
        QString Getdate_emb() { return date_emb; }
        void Setdate_emb(QString val) { date_emb = val; }
        //date_n
        QString Getdate_n() { return date_n; }
        void Setdate_n(QString val) { date_n = val; }//
        //salaire
        float Getsalaire() { return salaire; }
        void Setsalaire(float val) { salaire = val; }
        //email
        QString Getemail() { return email; }
        void Setemail(QString val) { email = val; }
        //mdp
        QString Getmdp() { return mdp; }
        void Setmdp(QString val) { mdp = val; }
        //adresse
        QString Getadresse() { return adresse; }
        void Setadresse(QString val) { adresse = val; }
        //role
        QString Getrole() { return role; }
        void Setrole(QString val) { val = role; }
        //id_p
        int Getid_p() { return idP; }
        void Setid_p(int val) { idP=val; }

        QString Getimg(){ return img; }
        void Setimg(QString val) { img=val; }


        bool ajouter();
        bool modifier(int cin);

        bool modifier_nom(int cin);
        bool modifier_prenom(int cin);
        bool modifier_dn(int cin);
        bool modifier_demb(int cin);
        bool modifier_adresse(int cin);
        bool modifier_salaire(int cin);
        bool modifier_idProjet(int cin);
        bool modifier_role(int cin);
        bool modifier_mdp(int cin);
        bool modifier_email(int cin);
        bool modifier_genre(int cin);
        bool modifier_img(int cin);



        QSqlQueryModel* afficher();

        QSqlQueryModel* afficherSalaireASC();
        QSqlQueryModel* afficherSalaireDSC();

        QSqlQueryModel* afficherNomASC();
         QSqlQueryModel* afficherNomDSC();

         bool rowExists( int cin);

         bool verifier(int cin);
        bool supprimer(int id );

       int value_count(QString  role,QString genre);


        QString login_redirect();


    protected:

    private:
        int cin;
        int idP;
        QString nom;
        QString prenom;
        QString date_emb;
        QString date_n;
        float salaire;
        QString email;
        QString mdp;
        QString adresse;
        QString role;
        QString genre;
        QString img;

};

#endif // EMPLOYE_H
