#include "employe.h"


employe::employe()
{

}

employe::employe(int cin_p,QString nom_p,QString prenom_p,QString date_emb_p,QString date_n_p,float salaire_p,QString email_p,QString mdp_p, QString adresse_p,QString role_p,int idP_p,QString genre_p,QString img_p )
{
    cin=cin_p;
    nom=nom_p;
    prenom=prenom_p;
    date_emb=date_emb_p;
    date_n=date_n_p;
    salaire=salaire_p;
    email=email_p;
    mdp=mdp_p;
    adresse=adresse_p;
    role=role_p;
    idP=idP_p;
    genre=genre_p;
    img= img_p;


}

bool employe::ajouter()
{

    QSqlQuery query;
    QString cin_string=QString::number(cin);
    QString salaire_string=QString::number(salaire);
    QString idP_string=QString::number(idP);

          query.prepare("INSERT INTO EMPLOYE (CIN,NOM,PRENOM,DATE_EMB,DATE_N,SALAIRE,EMAIL,MDP,ADRESSE,ROLE,ID_P_E,GENRE,IMAGE_U) "
                        "VALUES (:cin,:nom,:prenom,:date_emb,:date_n,:salaire,:email,:mdp,:adresse,:role,:ID_p_e,:genre,:img)");

          query.bindValue(":cin", cin_string);
          query.bindValue(":nom", nom);
          query.bindValue(":prenom", prenom);
          query.bindValue(":date_emb",date_emb);
          query.bindValue(":date_n",date_n);
          query.bindValue(":salaire", salaire_string);
          query.bindValue(":email", email);
          query.bindValue(":mdp",mdp);
          query.bindValue(":adresse",adresse);
          query.bindValue(":role",role);
          query.bindValue(":ID_p_e",idP_string);
          query.bindValue(":genre",genre);
          query.bindValue(":img",img);






          return query.exec();



}





bool employe::modifier(int cin){
     QSqlQuery query;
     QString cin_string= QString::number(cin);
     QString salaire_string= QString::number(salaire);
     QString idP_string=QString::number(idP);

    //requette sql
    query.prepare("UPDATE EMPLOYE set CIN=:cin,NOM=:nom,PRENOM=:prenom,DATE_EMB=:date_emb,DATE_N=:date_n,SALAIRE=:salaire,EMAIL=:email,MDP=:mdp,ADRESSE=:adresse,ROLE=:role,ID_P_E=:idP,GENRE=:genre,IMAGE_U=:img WHERE CIN=:cin");

    //saisi des donnee
    query.bindValue(":cin",cin_string);
    query.bindValue(":nom",nom);
    query.bindValue(":prenom",prenom);
    query.bindValue(":date_emb",date_emb);
    query.bindValue(":date_n",date_n);
    query.bindValue(":salaire",salaire_string);
    query.bindValue(":email",email);
    query.bindValue(":mdp",mdp);
    query.bindValue(":adresse",adresse);
    query.bindValue(":role",role);
    query.bindValue(":idP",idP_string);
    query.bindValue(":genre",genre);
    query.bindValue(":img",img);



    //execution de la requette
    return query.exec();
}

bool employe::modifier_nom(int cin)
{
    QSqlQuery query;
    QString cin_string= QString::number(cin);
    QString salaire_string= QString::number(salaire);
    QString idP_string=QString::number(idP);

   //requette sql
   query.prepare("UPDATE EMPLOYE set NOM=:nom WHERE CIN=:cin");

   //saisi des donnee
   query.bindValue(":cin",cin_string);
   query.bindValue(":nom",nom);

   //execution de la requette
   return query.exec();

}

bool employe::modifier_prenom(int cin)
{QSqlQuery query;
    QString cin_string= QString::number(cin);
    QString salaire_string= QString::number(salaire);
    QString idP_string=QString::number(idP);

   //requette sql
   query.prepare("UPDATE EMPLOYE set PRENOM=:prenom WHERE CIN=:cin");

   //saisi des donnee
   query.bindValue(":cin",cin_string);
   query.bindValue(":prenom",prenom);

   //execution de la requette
   return query.exec();}


bool employe::modifier_dn(int cin)
{
    QSqlQuery query;
    QString cin_string= QString::number(cin);
    QString salaire_string= QString::number(salaire);
    QString idP_string=QString::number(idP);

   //requette sql
   query.prepare("UPDATE EMPLOYE set DATE_N=:dn WHERE CIN=:cin");

   //saisi des donnee
   query.bindValue(":cin",cin_string);
   query.bindValue(":dn",date_n);

   //execution de la requette
   return query.exec();
}


bool employe::modifier_demb(int cin)
{
    QSqlQuery query;
    QString cin_string= QString::number(cin);
    QString salaire_string= QString::number(salaire);
    QString idP_string=QString::number(idP);

   //requette sql
   query.prepare("UPDATE EMPLOYE set DATE_EMB=:d_emb WHERE CIN=:cin");

   //saisi des donnee
   query.bindValue(":cin",cin_string);
   query.bindValue(":d_emb",date_emb);

   //execution de la requette
   return query.exec();
}


bool employe::modifier_adresse(int cin)
{
    QSqlQuery query;
    QString cin_string= QString::number(cin);
    QString salaire_string= QString::number(salaire);
    QString idP_string=QString::number(idP);

   //requette sql
   query.prepare("UPDATE EMPLOYE set ADRESSE=:adresse WHERE CIN=:cin");

   //saisi des donnee
   query.bindValue(":cin",cin_string);
   query.bindValue(":nom",adresse);

   //execution de la requette
   return query.exec();
}

bool employe::modifier_salaire(int cin)
{
    QSqlQuery query;
    QString cin_string= QString::number(cin);
    QString salaire_string= QString::number(salaire);
    QString idP_string=QString::number(idP);

   //requette sql
   query.prepare("UPDATE EMPLOYE set SALAIRE=:sal WHERE CIN=:cin");

   //saisi des donnee
   query.bindValue(":cin",cin_string);
   query.bindValue(":sal",salaire_string);

   //execution de la requette
   return query.exec();
}


bool employe::modifier_idProjet(int cin)
{
    QSqlQuery query;
    QString cin_string= QString::number(cin);
    QString salaire_string= QString::number(salaire);
    QString idP_string=QString::number(idP);

   //requette sql
   query.prepare("UPDATE EMPLOYE set ID_P_E=:idP WHERE CIN=:cin");

   //saisi des donnee
   query.bindValue(":cin",cin_string);
   query.bindValue(":idP",idP_string);

   //execution de la requette
   return query.exec();
}

bool employe::modifier_role(int cin)
{
    QSqlQuery query;
    QString cin_string= QString::number(cin);
    QString salaire_string= QString::number(salaire);
    QString idP_string=QString::number(idP);

   //requette sql
   query.prepare("UPDATE EMPLOYE set ROLE=:role WHERE CIN=:cin");

   //saisi des donnee
   query.bindValue(":cin",cin_string);
   query.bindValue(":role",role);

   //execution de la requette
   return query.exec();
}

bool employe::modifier_mdp(int cin)
{
    QSqlQuery query;
    QString cin_string= QString::number(cin);
    QString salaire_string= QString::number(salaire);
    QString idP_string=QString::number(idP);

   //requette sql
   query.prepare("UPDATE EMPLOYE set MDP=:mdp WHERE CIN=:cin");

   //saisi des donnee
   query.bindValue(":cin",cin_string);
   query.bindValue(":mdp",mdp);

   //execution de la requette
   return query.exec();
}

bool employe::modifier_email(int cin)
{
    QSqlQuery query;
    QString cin_string= QString::number(cin);
    QString salaire_string= QString::number(salaire);
    QString idP_string=QString::number(idP);

   //requette sql
   query.prepare("UPDATE EMPLOYE set EMAIL=:email WHERE CIN=:cin");

   //saisi des donnee
   query.bindValue(":cin",cin_string);
   query.bindValue(":email",email);

   //execution de la requette
   return query.exec();
}

bool employe::modifier_genre(int cin)
{
    QSqlQuery query;
    QString cin_string= QString::number(cin);
    QString salaire_string= QString::number(salaire);
    QString idP_string=QString::number(idP);

   //requette sql
   query.prepare("UPDATE EMPLOYE set GENRE=:genre WHERE CIN=:cin");

   //saisi des donnee
   query.bindValue(":cin",cin_string);
   query.bindValue(":genre",genre);

   //execution de la requette
   return query.exec();

}
bool employe::modifier_img(int cin){
    QSqlQuery query;
    QString cin_string= QString::number(cin);
    QString salaire_string= QString::number(salaire);
    QString idP_string=QString::number(idP);

   //requette sql
   query.prepare("UPDATE EMPLOYE set IMAGE_U=:img WHERE CIN=:cin");

   //saisi des donnee
   query.bindValue(":cin",cin_string);
   query.bindValue(":img",img);

   //execution de la requette
   return query.exec();

}

QSqlQueryModel* employe::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT* FROM EMPLOYE");
          model->setHeaderData(0, Qt::Horizontal,QObject::tr("Cin"));
          model->setHeaderData(1, Qt::Horizontal,QObject::tr("nom"));
          model->setHeaderData(2, Qt::Horizontal,QObject::tr("prenom"));
          model->setHeaderData(3, Qt::Horizontal,QObject::tr("date_emb"));
          model->setHeaderData(4, Qt::Horizontal,QObject::tr("date_n"));
          model->setHeaderData(5, Qt::Horizontal,QObject::tr("salaire"));
          model->setHeaderData(6, Qt::Horizontal,QObject::tr("email"));
          model->setHeaderData(7, Qt::Horizontal,QObject::tr("Mot de passe"));
          model->setHeaderData(8, Qt::Horizontal,QObject::tr("Adresse"));
          model->setHeaderData(9, Qt::Horizontal,QObject::tr("Role"));
          model->setHeaderData(10, Qt::Horizontal,QObject::tr("ID Projet"));

    return model;




}


QSqlQueryModel* employe::afficherSalaireASC()
{
    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT* FROM EMPLOYE ORDER BY SALAIRE ASC");
          model->setHeaderData(0, Qt::Horizontal,QObject::tr("Cin"));
          model->setHeaderData(1, Qt::Horizontal,QObject::tr("nom"));
          model->setHeaderData(2, Qt::Horizontal,QObject::tr("prenom"));
          model->setHeaderData(3, Qt::Horizontal,QObject::tr("date_emb"));
          model->setHeaderData(4, Qt::Horizontal,QObject::tr("date_n"));
          model->setHeaderData(5, Qt::Horizontal,QObject::tr("salaire"));
          model->setHeaderData(6, Qt::Horizontal,QObject::tr("email"));
          model->setHeaderData(7, Qt::Horizontal,QObject::tr("Mot de passe"));
          model->setHeaderData(8, Qt::Horizontal,QObject::tr("Adresse"));
          model->setHeaderData(9, Qt::Horizontal,QObject::tr("Role"));
          model->setHeaderData(10, Qt::Horizontal,QObject::tr("ID Projet"));

    return model;
}



QSqlQueryModel* employe::afficherNomASC()
{
    QSqlQueryModel* model=new QSqlQueryModel();

          model->setQuery("SELECT* FROM EMPLOYE ORDER BY NOM ASC");
          model->setHeaderData(0, Qt::Horizontal,QObject::tr("Cin"));
          model->setHeaderData(1, Qt::Horizontal,QObject::tr("nom"));
          model->setHeaderData(2, Qt::Horizontal,QObject::tr("prenom"));
          model->setHeaderData(3, Qt::Horizontal,QObject::tr("date_emb"));
          model->setHeaderData(4, Qt::Horizontal,QObject::tr("date_n"));
          model->setHeaderData(5, Qt::Horizontal,QObject::tr("salaire"));
          model->setHeaderData(6, Qt::Horizontal,QObject::tr("email"));
          model->setHeaderData(7, Qt::Horizontal,QObject::tr("Mot de passe"));
          model->setHeaderData(8, Qt::Horizontal,QObject::tr("Adresse"));
          model->setHeaderData(9, Qt::Horizontal,QObject::tr("Role"));
          model->setHeaderData(10, Qt::Horizontal,QObject::tr("ID Projet"));

    return model;

}


QSqlQueryModel* employe::afficherSalaireDSC()
{ QSqlQueryModel* model=new QSqlQueryModel();

    model->setQuery("SELECT* FROM EMPLOYE ORDER BY SALAIRE DESC");
    model->setHeaderData(0, Qt::Horizontal,QObject::tr("Cin"));
    model->setHeaderData(1, Qt::Horizontal,QObject::tr("nom"));
    model->setHeaderData(2, Qt::Horizontal,QObject::tr("prenom"));
    model->setHeaderData(3, Qt::Horizontal,QObject::tr("date_emb"));
    model->setHeaderData(4, Qt::Horizontal,QObject::tr("date_n"));
    model->setHeaderData(5, Qt::Horizontal,QObject::tr("salaire"));
    model->setHeaderData(6, Qt::Horizontal,QObject::tr("email"));
    model->setHeaderData(7, Qt::Horizontal,QObject::tr("Mot de passe"));
    model->setHeaderData(8, Qt::Horizontal,QObject::tr("Adresse"));
    model->setHeaderData(9, Qt::Horizontal,QObject::tr("Role"));
    model->setHeaderData(10, Qt::Horizontal,QObject::tr("ID Projet"));

return model;
}


 QSqlQueryModel* employe::afficherNomDSC()
 {QSqlQueryModel* model=new QSqlQueryModel();

     model->setQuery("SELECT* FROM EMPLOYE ORDER BY NOM DESC");
     model->setHeaderData(0, Qt::Horizontal,QObject::tr("Cin"));
     model->setHeaderData(1, Qt::Horizontal,QObject::tr("nom"));
     model->setHeaderData(2, Qt::Horizontal,QObject::tr("prenom"));
     model->setHeaderData(3, Qt::Horizontal,QObject::tr("date_emb"));
     model->setHeaderData(4, Qt::Horizontal,QObject::tr("date_n"));
     model->setHeaderData(5, Qt::Horizontal,QObject::tr("salaire"));
     model->setHeaderData(6, Qt::Horizontal,QObject::tr("email"));
     model->setHeaderData(7, Qt::Horizontal,QObject::tr("Mot de passe"));
     model->setHeaderData(8, Qt::Horizontal,QObject::tr("Adresse"));
     model->setHeaderData(9, Qt::Horizontal,QObject::tr("Role"));
     model->setHeaderData(10, Qt::Horizontal,QObject::tr("ID Projet"));

return model;
}


bool employe::verifier(int cin)
{
    QSqlQuery query;
    QString cin_string= QString::number(cin);


   //requette sql
   query.prepare("SELECT * FROM EMPLOYE WHERE CIN=:cin");

   //saisi des donnee
   query.bindValue(":cin",cin_string);


   //execution de la requette
   return query.exec();
}


bool employe::supprimer(int cin )
{

    if(this->verifier(cin)){

        QSqlQuery query;

             QString cin_string= QString::number(cin);
             query.prepare("DELETE FROM EMPLOYE WHERE CIN=:cin");
             query.bindValue(":cin",cin_string);
            return  query.exec();

    }
    else {return false;}

}



bool employe::rowExists( int cin)
{
    // Assume you have a valid database connection called 'db'
    QSqlQuery query;

    // Build the SQL query
    QString sql = QString("SELECT COUNT(*) FROM EMPLOYE WHERE CIN = :cin");

    // Prepare the query
    if (!query.prepare(sql)) {
        qDebug() << "Failed to prepare query:" << query.lastError().text();
        return false;
    }

    // Bind the value to the query
    query.bindValue(":cin",cin);

    // Execute the query
    if (!query.exec()) {
        qDebug() << "Failed to execute query:" << query.lastError().text();
        return false;
    }

    // Retrieve the result of the query
    if (query.next()) {
        int count = query.value(0).toInt();
        return count > 0;
    } else {
        qDebug() << "Failed to retrieve result of query:" << query.lastError().text();
        return false;
    }
}

int employe::value_count(QString  role,QString genre)
{
   QSqlQuery query;

   query.prepare("SELECT SUM SALAIRE FROM EMPLOYE WHERE GENRE = :genre AND ROLE = :role");
   query.bindValue(":genre",genre);
   query.bindValue(":role",role);
   query.exec();
   if (query.next()) {
       int TotSalaire = query.value(0).toInt();
       return TotSalaire;
   }
   else {
           qDebug() << "Failed to retrieve result of query:" << query.lastError().text();
           return 0;
       }

}
QString employe::login_redirect()
{//on aurait pu faire une fonction void au lieud e retourner QString et cela en utilsant les Set sur notre objet e dans le fichiers mainwindow.cpp onutilisera les les attribut de la classe this->role this->nom this->mdp

    QSqlQuery query;
        query.prepare("SELECT PRENOM,NOM,ROLE,IMAGE_U FROM EMPLOYE WHERE EMAIL = :username AND MDP = :password");
        query.bindValue(":username", email);
        query.bindValue(":password", mdp);

        if (!query.exec()) {
            QMessageBox::critical(nullptr, "Error", "Failed to query database: " + query.lastError().text());
            return "";
        }

        if (query.next()) {
            QString prenom = query.value(0).toString();
            QString nom = query.value(1).toString();
            QString role = query.value(2).toString();
            QString img =query.value(3).toString();

            this->Setprenom(prenom);
            this->Setnom(nom);
            this->Setrole(role);
            this->Setimg(img);

           return role ;
        }else{
            QMessageBox::critical(nullptr, "Error", "Invalid username or password");
            return "";
        }



}









