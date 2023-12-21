#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QFontDatabase>
#include <QMessageBox>
#include <QFileDialog>
#include "employe.h"
#include <QLabel>
#include <QTimer>
#include <connection.h>
#include <QtCharts>
#include<QtCharts>
#include<QChartView>
#include<QPieSeries>
#include<QPieSlice>
#include <QTcpSocket>
#include <QTextStream>
#include <QtNetwork/QNetworkAccessManager>
#include <QtNetwork/QNetworkRequest>
#include <QtNetwork/QNetworkReply>
#include "dialog.h"
#include <QDesktopServices>
#include <QUrl>
#include <QPalette>
#include <equipements.h>
#include<QSqlRecord>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/
//preparation des font
    int fontId = QFontDatabase::addApplicationFont(":/fonts/fonts/TT-Wellingtons-Trial-Medium.otf");
    QString fontName = QFontDatabase::applicationFontFamilies(fontId).at(0);
    QFont myFont(fontName,12);
    ui->tb_emp->setFont(myFont);
    ui->tb_taches->setFont(myFont);
    ui->tb_pro->setFont(myFont);
    ui->tb_log_out->setFont(myFont);
    ui->tb_equi->setFont(myFont);
    ui->tb_cli->setFont(myFont);

    int fontId2 = QFontDatabase::addApplicationFont(":/fonts/fonts/TT Chocolates Trial Bold.otf");
    QString fontName2 = QFontDatabase::applicationFontFamilies(fontId2).at(0);
    QFont myFont2(fontName2,25);
    ui->label_vs->setFont(myFont2);
    ui->label_vs_2->setFont(myFont2);
    ui->label_vs_3->setFont(myFont2);/*ui->tb_taches->setFont(myFont);
    ui->tb_pro->setFont(myFont);
    ui->tb_log_out->setFont(myFont);
    ui->tb_equi->setFont(myFont);
    ui->tb_cli->setFont(myFont);*/


    //stats

    //chatbox
   QTcpSocket *nSocket =new QTcpSocket(this);
    connect(nSocket,&QTcpSocket::readyRead,[&](){
        QTextStream T(nSocket);
        auto text=T.readAll();
        //ui->Perso_text_Chatbox->append(text);
    });

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/

   // timer des erreurs
    timer = new QTimer(this);
     connect(timer, &QTimer::timeout, this, &MainWindow::clearStatusLabel);

   //progress bar
    ui->progressBar->setVisible(false);
    ui->progressBar->setRange(0, 100);
    ui->progressBar->setValue(0);
    ui->frame_31->setVisible(false);

    //botton
    ui->tb_emp->setEnabled(false);
    ui->tb_taches->setEnabled(false);
    ui->tb_equi->setEnabled(false);
    ui->tb_pro->setEnabled(false);
    ui->tb_cli->setEnabled(false);
    //
    ui->tb_emp_2->setEnabled(false);
    ui->tb_taches_2->setEnabled(false);
    ui->tb_equi_2->setEnabled(false);
    ui->tb_pro_2->setEnabled(false);
    ui->tb_cli_2->setEnabled(false);
    //
    ui->tb_emp_3->setEnabled(false);
    ui->tb_taches_3->setEnabled(false);
    ui->tb_equi_3->setEnabled(false);
    ui->tb_pro_3->setEnabled(false);
    ui->tb_cli_3->setEnabled(false);
    //
    ui->tb_emp_4->setEnabled(false);
    ui->tb_taches_4->setEnabled(false);
    ui->tb_equi_4->setEnabled(false);
    ui->tb_pro_4->setEnabled(false);
    ui->tb_cli_4->setEnabled(false);
   // video

    ui->tableView_equi->setModel(Etmp.afficher("",""));
/*------------------------------------------------------------------- Verification de la conncetion a la base --------------------------------------------------------------------------------------------------*/
    Connection c;
     bool test=c.createconnect();
     if(test)
     {
         ui->label_8->setText("Conncetion a la base reussie");

      }

     else
        { ui->label_8->setText("Conncetion a la base echoue");}

/*-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------*/



/*---------------------------------*/

}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::on_pb_add_p_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("choose"),"",tr(""));
    if(QString::compare(filename,QString())!=0)
    {
        QImage image;
        bool valid=image.load(filename);
        if(valid)
        {
            ui->le_nomphoto->setText(filename);
            image=image.scaledToWidth(ui->profilePictureLabel->width(),Qt::SmoothTransformation);
            ui->profilePictureLabel->setPixmap(QPixmap::fromImage(image));
        }
        else
        {
            QMessageBox::information(this, tr("ERROR"), QString(tr("Not Valid!")));
        }
    }
}

void MainWindow::on_pushButton_7_clicked()
{
    int     cin=ui->le_cin->text().toInt();
    QString nom=ui->le_nom->text();
    QString prenom=ui->le_prenom->text();
    QString date_emb=ui->le_emb->text();
    QString date_n=ui->le_dn->text();
    float salaire = ui->le_salaire->text().toFloat();
    QString email=ui->le_email->text();
    QString mdp= ui->le_mdp->text();
    QString adresse=ui->le_adresse->text();
    int idP=ui->le_id_p->text().toInt();
     QString role=ui->le_role->text();
     QString genre = ui->cb_genre->currentText();
     QString img = ui->le_nomphoto->text();




    employe e(cin,nom,prenom,date_emb,date_n,salaire,email,mdp,adresse,role,idP,genre,img);

    if (nom.isEmpty() || prenom.isEmpty()  ||cin==0||salaire==0||date_emb.isEmpty() || date_n.isEmpty()  ||email.isEmpty()||mdp.isEmpty()||adresse.isEmpty()||role.isEmpty())
        {
            QMessageBox::critical(0,qApp->tr("erreur"),qApp->tr("Veuillez remplir les champs vides Pour continuez."),QMessageBox::Cancel);
           } else {


    bool test;

    test=e.ajouter();
    QMessageBox msgBox;
    if(test)
    {/*
        ui->tableView->setModel(e.afficher());*/
        msgBox.setText("ajout avec succes");

        this->Stat_emp();
        this->Stat_salaire();
        ui->t_affichage->setModel(e.afficher());

     ui->le_cin->clear();
     ui->le_nom->clear();
     ui->le_prenom->clear();
     ui->le_dn->clear();
     ui->le_salaire->clear();
     ui->le_role->clear();
     ui->le_emb->clear();
     ui->le_mdp->clear();
     ui->le_adresse->clear();
     ui->le_id_p->clear();
     ui->profilePictureLabel->clear();


    }
    else msgBox.setText("Echec d'ajout");
    msgBox.exec();
}
}

void MainWindow::on_pb_modifier_clicked()
{
    int    cin = ui->le_cinM->text().toInt();
    QString nom=ui->le_nomM->text();
    QString prenom=ui->le_prenomM->text();
    QString date_emb=ui->le_embM->text();
    QString date_n=ui->le_dnM->text();
    float salaire = ui->le_salaireM->text().toFloat();
    QString email=ui->le_emailM->text();
    QString mdp=ui->le_mdpM->text();
    QString adresse= ui->le_adresseM->text();
    QString  role=ui->le_roleM->text();
    int idP=ui->le_id_pM->text().toInt();
    QString genre =ui->cb_genre_2->currentText();
    QString img = ui->le_nomphoto_2->text();


    employe e(cin,nom,prenom,date_emb,date_n,salaire,email,mdp,adresse,role,idP,genre,img);
    if (cin==0)
        {
            QMessageBox::critical(0,qApp->tr("erreur"),qApp->tr("Veuillez saisir le CIN de l'employe Pour continuez."),QMessageBox::Cancel);
           } else {

        if(!nom.isEmpty())
        {
            bool test= e.modifier_nom(cin);
            if (!test)
            {
            ui->t_affichage->setModel(e.afficher());

            ui->fr_supprimer_2->setStyleSheet("background-color: background-color: rgb(255, 172, 172);border: 2px solid rgb(255, 69, 69);");
            ui->fr_supprimer_2->setVisible(true);
            ui->lab_error_2->setStyleSheet("color: red;");
            ui->lab_error_2->setText(" ERREUR: Supression non effectue echec");
            timer->start(5000);
            }
            else{  ui->t_affichage->setModel(e.afficher());
                ui->fr_supprimer_2->setStyleSheet("background-color: rgb(205, 231, 255); border: 2px solid rgb(34, 152, 255);");
                ui->fr_supprimer_2->setVisible(true);
                ui->lab_error_2->setStyleSheet("color: blue;background:none");
                ui->lab_error_2->setText(" Modification avec succes");
                timer->start(5000);}

        }

        if(!prenom.isEmpty())
        {
            bool test= e.modifier_prenom(cin);
            ui->t_affichage->setModel(e.afficher());
            if (!test)
            {
            ui->t_affichage->setModel(e.afficher());

            ui->fr_supprimer_2->setStyleSheet("background-color: background-color: rgb(255, 172, 172);border: 2px solid rgb(255, 69, 69);");
            ui->fr_supprimer_2->setVisible(true);
            ui->lab_error_2->setStyleSheet("color: red;");
            ui->lab_error_2->setText(" ERREUR: Modification non effectue echec");
            timer->start(5000);
            }
            else{  ui->t_affichage->setModel(e.afficher());
                ui->fr_supprimer_2->setStyleSheet("background-color: rgb(205, 231, 255); border: 2px solid rgb(34, 152, 255);");
                ui->fr_supprimer_2->setVisible(true);
                ui->lab_error_2->setStyleSheet("color: blue;background:none");
                ui->lab_error_2->setText(" Modification avec succes");
                timer->start(5000);}

        }
        if(salaire!=0)
        {
            bool test= e.modifier_salaire(cin);
            ui->t_affichage->setModel(e.afficher());
            if (!test)
            {
            ui->t_affichage->setModel(e.afficher());

            ui->fr_supprimer_2->setStyleSheet("background-color: background-color: rgb(255, 172, 172);border: 2px solid rgb(255, 69, 69);");
            ui->fr_supprimer_2->setVisible(true);
            ui->lab_error_2->setStyleSheet("color: red;");
            ui->lab_error_2->setText(" ERREUR: Modification non effectue echec");
            timer->start(5000);
            }
            else{  ui->t_affichage->setModel(e.afficher());
                ui->fr_supprimer_2->setStyleSheet("background-color: rgb(205, 231, 255); border: 2px solid rgb(34, 152, 255);");
                ui->fr_supprimer_2->setVisible(true);
                ui->lab_error_2->setStyleSheet("color: blue;background:none");
                ui->lab_error_2->setText(" Modification avec succes");
                timer->start(5000);}
        }
        if(!date_emb.isEmpty())
        {
             bool test=e.modifier_demb(cin);
            ui->t_affichage->setModel(e.afficher());
            if (!test)
            {
            ui->t_affichage->setModel(e.afficher());

            ui->fr_supprimer_2->setStyleSheet("background-color: background-color: rgb(255, 172, 172);border: 2px solid rgb(255, 69, 69);");
            ui->fr_supprimer_2->setVisible(true);
            ui->lab_error_2->setStyleSheet("color: red;");
            ui->lab_error_2->setText(" ERREUR: Modification non effectue echec");
            timer->start(5000);
            }
            else{  ui->t_affichage->setModel(e.afficher());
                ui->fr_supprimer_2->setStyleSheet("background-color: rgb(205, 231, 255); border: 2px solid rgb(34, 152, 255);");
                ui->fr_supprimer_2->setVisible(true);
                ui->lab_error_2->setStyleSheet("color: blue;background:none");
                ui->lab_error_2->setText(" Modification avec succes");
                timer->start(5000);}
        }
        if(!date_n.isEmpty())
        {
             bool test=e.modifier_dn(cin);
            ui->t_affichage->setModel(e.afficher());
            if (!test)
            {
            ui->t_affichage->setModel(e.afficher());

            ui->fr_supprimer_2->setStyleSheet("background-color: background-color: rgb(255, 172, 172);border: 2px solid rgb(255, 69, 69);");
            ui->fr_supprimer_2->setVisible(true);
            ui->lab_error_2->setStyleSheet("color: red;");
            ui->lab_error_2->setText(" ERREUR: Modification non effectue echec");
            timer->start(5000);
            }
            else{  ui->t_affichage->setModel(e.afficher());
                ui->fr_supprimer_2->setStyleSheet("background-color: rgb(205, 231, 255); border: 2px solid rgb(34, 152, 255);");
                ui->fr_supprimer_2->setVisible(true);
                ui->lab_error_2->setStyleSheet("color: blue;background:none");
                ui->lab_error_2->setText(" Modification avec succes");
                timer->start(5000);}
        }

        if(!email.isEmpty())
        {
             bool test=e.modifier_email(cin);
            ui->t_affichage->setModel(e.afficher());
            if (!test)
            {
            ui->t_affichage->setModel(e.afficher());

            ui->fr_supprimer_2->setStyleSheet("background-color: background-color: rgb(255, 172, 172);border: 2px solid rgb(255, 69, 69);");
            ui->fr_supprimer_2->setVisible(true);
            ui->lab_error_2->setStyleSheet("color: red;");
            ui->lab_error_2->setText(" ERREUR: Modification non effectue echec");
            timer->start(5000);
            }
            else{  ui->t_affichage->setModel(e.afficher());
                ui->fr_supprimer_2->setStyleSheet("background-color: rgb(205, 231, 255); border: 2px solid rgb(34, 152, 255);");
                ui->fr_supprimer_2->setVisible(true);
                ui->lab_error_2->setStyleSheet("color: blue;background:none");
                ui->lab_error_2->setText(" Modification avec succes");
                timer->start(5000);}
        }

        if(!mdp.isEmpty())
        {
             bool test=e.modifier_mdp(cin);
            ui->t_affichage->setModel(e.afficher());
            if (!test)
            {
            ui->t_affichage->setModel(e.afficher());

            ui->fr_supprimer_2->setStyleSheet("background-color: background-color: rgb(255, 172, 172);border: 2px solid rgb(255, 69, 69);");
            ui->fr_supprimer_2->setVisible(true);
            ui->lab_error_2->setStyleSheet("color: red;");
            ui->lab_error_2->setText(" ERREUR: Modification non effectue echec");
            timer->start(5000);
            }
            else{  ui->t_affichage->setModel(e.afficher());
                ui->fr_supprimer_2->setStyleSheet("background-color: rgb(205, 231, 255); border: 2px solid rgb(34, 152, 255);");
                ui->fr_supprimer_2->setVisible(true);
                ui->lab_error_2->setStyleSheet("color: blue;background:none");
                ui->lab_error_2->setText(" Modification avec succes");
                timer->start(5000);}
        }

        if(!nom.isEmpty())
        {
            bool test= e.modifier_nom(cin);
            ui->t_affichage->setModel(e.afficher());
            if (!test)
            {
            ui->t_affichage->setModel(e.afficher());

            ui->fr_supprimer_2->setStyleSheet("background-color: background-color: rgb(255, 172, 172);border: 2px solid rgb(255, 69, 69);");
            ui->fr_supprimer_2->setVisible(true);
            ui->lab_error_2->setStyleSheet("color: red;");
            ui->lab_error_2->setText(" ERREUR: Modification non effectue echec");
            timer->start(5000);
            }
            else{  ui->t_affichage->setModel(e.afficher());
                ui->fr_supprimer_2->setStyleSheet("background-color: rgb(205, 231, 255); border: 2px solid rgb(34, 152, 255);");
                ui->fr_supprimer_2->setVisible(true);
                ui->lab_error_2->setStyleSheet("color: blue;background:none");
                ui->lab_error_2->setText(" Modification avec succes");
                timer->start(5000);}
        }

        if(!adresse.isEmpty())
        {
            bool test= e.modifier_adresse(cin);
            ui->t_affichage->setModel(e.afficher());
            if (!test)
            {
            ui->t_affichage->setModel(e.afficher());

            ui->fr_supprimer_2->setStyleSheet("background-color: background-color: rgb(255, 172, 172);border: 2px solid rgb(255, 69, 69);");
            ui->fr_supprimer_2->setVisible(true);
            ui->lab_error_2->setStyleSheet("color: red;");
            ui->lab_error_2->setText(" ERREUR: Modification non effectue echec");
            timer->start(5000);
            }
            else{  ui->t_affichage->setModel(e.afficher());
                ui->fr_supprimer_2->setStyleSheet("background-color: rgb(205, 231, 255); border: 2px solid rgb(34, 152, 255);");
                ui->fr_supprimer_2->setVisible(true);
                ui->lab_error_2->setStyleSheet("color: blue;background:none");
                ui->lab_error_2->setText(" Modification avec succes");
                timer->start(5000);}
        }

        if(!role.isEmpty())
        {
             bool test=e.modifier_role(cin);
            ui->t_affichage->setModel(e.afficher());
            if (!test)
            {
            ui->t_affichage->setModel(e.afficher());

            ui->fr_supprimer_2->setStyleSheet("background-color: background-color: rgb(255, 172, 172);border: 2px solid rgb(255, 69, 69);");
            ui->fr_supprimer_2->setVisible(true);
            ui->lab_error_2->setStyleSheet("color: red;");
            ui->lab_error_2->setText(" ERREUR: Modification non effectue echec");
            timer->start(5000);
            }
            else{  ui->t_affichage->setModel(e.afficher());
                ui->fr_supprimer_2->setStyleSheet("background-color: rgb(205, 231, 255); border: 2px solid rgb(34, 152, 255);");
                ui->fr_supprimer_2->setVisible(true);
                ui->lab_error_2->setStyleSheet("color: blue;background:none");
                ui->lab_error_2->setText(" Supression avec succes");
                timer->start(5000);}
        }

        if(!genre.isEmpty())
        {
            bool test=e.modifier_genre(cin);
            ui->t_affichage->setModel(e.afficher());
            if (!test)
            {
            ui->t_affichage->setModel(e.afficher());

            ui->fr_supprimer_2->setStyleSheet("background-color: background-color: rgb(255, 172, 172);border: 2px solid rgb(255, 69, 69);");
            ui->fr_supprimer_2->setVisible(true);
            ui->lab_error_2->setStyleSheet("color: red;");
            ui->lab_error_2->setText(" ERREUR: Modification non effectue echec");
            timer->start(5000);
            }
            else{  ui->t_affichage->setModel(e.afficher());
                ui->fr_supprimer_2->setStyleSheet("background-color: rgb(205, 231, 255); border: 2px solid rgb(34, 152, 255);");
                ui->fr_supprimer_2->setVisible(true);
                ui->lab_error_2->setStyleSheet("color: blue;background:none");
                ui->lab_error_2->setText(" Supression avec succes");
                timer->start(5000);}
        }

        if(!img.isEmpty())
        {
            bool test=e.modifier_img(cin);
            ui->t_affichage->setModel(e.afficher());
            if (!test)
            {
            ui->t_affichage->setModel(e.afficher());

            ui->fr_supprimer_2->setStyleSheet("background-color: background-color: rgb(255, 172, 172);border: 2px solid rgb(255, 69, 69);");
            ui->fr_supprimer_2->setVisible(true);
            ui->lab_error_2->setStyleSheet("color: red;");
            ui->lab_error_2->setText(" ERREUR: Modification non effectue echec");
            timer->start(5000);
            }
            else{  ui->t_affichage->setModel(e.afficher());
                ui->fr_supprimer_2->setStyleSheet("background-color: rgb(205, 231, 255); border: 2px solid rgb(34, 152, 255);");
                ui->fr_supprimer_2->setVisible(true);
                ui->lab_error_2->setStyleSheet("color: blue;background:none");
                ui->lab_error_2->setText(" Supression avec succes");
                timer->start(5000);}
        }







        if(!nom.isEmpty() && ! prenom.isEmpty()  &&cin!=0 && salaire!=0 && !date_emb.isEmpty() && !date_n.isEmpty()  && !email.isEmpty() && !mdp.isEmpty()  && !adresse.isEmpty() && !role.isEmpty())
    {bool test=e.modifier(cin);
        if(test)
        {
            ui->t_affichage->setModel(e.afficher());

            QMessageBox::information(nullptr, QObject::tr("ok"),QObject::tr("Modification avec succes.\n" "Click Close to exit."), QMessageBox::Close);
    }else
            QMessageBox::critical(nullptr, QObject::tr("not ok"),QObject::tr("Modification echoue.\n" "Click Close to exit."), QMessageBox::Close);
}
}

}


void MainWindow::on_tb_refresh_clicked()
{   employe e;
    ui->t_affichage->setModel(e.afficher());
}

void MainWindow::on_rb_salaire_asc_clicked()
{
    employe e;
    ui->t_affichage->setModel(e.afficherSalaireASC());

}

void MainWindow::on_rb_nom_asc_clicked()
{
    employe e;
    ui->t_affichage->setModel(e.afficherNomASC());
}

void MainWindow::on_rb_salaire_dsc_clicked()
{
    employe e;
    ui->t_affichage->setModel(e.afficherSalaireDSC());
}

void MainWindow::on_rb_nom_dsc_clicked()
{
    employe e;
    ui->t_affichage->setModel(e.afficherNomDSC());
}

void MainWindow::on_pb_supprimer_clicked()
{
    int    cin = ui->le_supprimer->text().toInt();
    employe e;
    e.Setcin(cin);

 bool test_E=e.rowExists(cin);



 QMessageBox::StandardButton reply;
     reply = QMessageBox::question(this, "Confirmation", "Are you sure you want to proceed?",
                                   QMessageBox::Yes|QMessageBox::No);
     if (reply == QMessageBox::Yes) {
         if(cin==0)

            {
                QMessageBox::critical(0,qApp->tr("erreur"),qApp->tr("Veuillez remplir le champ vide Pour continuez."),QMessageBox::Cancel);
            }
    else if(test_E==false)
    {
        ui->fr_supprimer->setStyleSheet("background-color:  rgb(255, 172, 172);border: 2px solid rgb(255, 69, 69);");
        ui->fr_supprimer->setVisible(true);
        ui->lab_error->setText(" ERREUR: Ce CIN n'existe pas dans la base de donnes");
        timer->start(5000);
    }

    else
      {
        bool test = e.supprimer(cin);

        if (test)
        {
            ui->t_affichage->setModel(e.afficher());
            ui->fr_supprimer->setStyleSheet("background-color: rgb(205, 231, 255); border: 2px solid rgb(34, 152, 255);");
            ui->fr_supprimer->setVisible(true);
            ui->lab_error->setStyleSheet("color: blue;background:none");
            ui->lab_error->setText(" Supression avec succes");
            timer->start(5000);
        }
        else {

            ui->fr_supprimer->setStyleSheet("background-color: background-color: rgb(255, 172, 172);border: 2px solid rgb(255, 69, 69);");
            ui->fr_supprimer->setVisible(true);
            ui->lab_error->setStyleSheet("color: red;");
            ui->lab_error->setText(" ERREUR: Supression non effectue echec");
            timer->start(5000);
        }
}

}else {
         return;
     }

}



void MainWindow::clearStatusLabel()
{
    // Clear the text of the statusLabel and stop the timer
    //ui->fr_supprimer->setStyleSheet("");
    ui->fr_supprimer->setVisible(false);
    ui->lab_error->clear();
    ui->lab_error->setStyleSheet("");
    timer->stop();
}

void MainWindow::on_pb_login_clicked()
{
    QString email=ui->le_emailL->text();
    QString mdp=ui->le_mdp_L->text();




    if (email.isEmpty() || mdp.isEmpty())
        {/*
        ui->frame_12->setStyleSheet("background-color:  rgb(255, 172, 172);border: 2px solid rgb(255, 69, 69);");
        ui->frame_12->setVisible(true);
        ui->lab_erreur_login->setText(" veuillez saisir votre E-mail et votre  Mot de passe");
        timer->start(5000);*/
        QMessageBox::critical(0,qApp->tr("erreur"),qApp->tr("Veuillez saisir votre e-mail et votre mot de passe."),QMessageBox::Cancel);
           }

    employe e;


    e.Setemail(email);
    e.Setmdp(mdp);
    QString role = e.login_redirect();
    e.Setrole(role);
    QString img=e.Getimg();
    //afficher
    ui->t_affichage->setModel(e.afficher());
    //statistique
    this->Stat_emp();
    this->Stat_salaire();

    QImage image;
    bool valid=image.load(img);
    if(valid)
    {

        image=image.scaledToWidth(ui->profilePictureLabel->width(),Qt::SmoothTransformation);
        ui->lab_img_user->setPixmap(QPixmap::fromImage(image));
    }



    if(role=="admin")
    {
       ui->stackedWidget->setCurrentIndex(1);
       ui->lab_nom_user->setText(e.Getnom());
       ui->lab_nom_user_2->setText(e.Getprenom());
       ui->lab_role_user->setText(role);
       ui->tb_emp->setStyleSheet("QToolButton{color: rgb(234, 243, 255);background-color: rgb(178, 209, 255);border-left: 4px solid rgb(64, 211, 255);}");

       ui->tb_emp->setEnabled(true);
       ui->tb_taches->setEnabled(true);
       ui->tb_equi->setEnabled(true);
       ui->tb_pro->setEnabled(true);
       ui->tb_cli->setEnabled(true);
       //
       ui->tb_emp_2->setEnabled(true);
       ui->tb_taches_2->setEnabled(true);
       ui->tb_equi_2->setEnabled(true);
       ui->tb_pro_2->setEnabled(true);
       ui->tb_cli_2->setEnabled(true);
       //
       ui->tb_emp_3->setEnabled(true);
       ui->tb_taches_3->setEnabled(true);
       ui->tb_equi_3->setEnabled(true);
       ui->tb_pro_3->setEnabled(true);
       ui->tb_cli_3->setEnabled(true);
       //
       ui->tb_emp_4->setEnabled(true);
       ui->tb_taches_4->setEnabled(true);
       ui->tb_equi_4->setEnabled(true);
       ui->tb_pro_4->setEnabled(true);
       ui->tb_cli_4->setEnabled(true);


    }
    if(role=="Gestion Employe")
    {
       ui->stackedWidget->setCurrentIndex(2);
       ui->lab_nom_user->setText(e.Getnom());
       ui->lab_nom_user_2->setText(e.Getprenom());
       ui->lab_role_user->setText(role);
       ui->tb_emp->setStyleSheet("");
       ui->tb_emp->setStyleSheet("QToolButton{color: rgb(234, 243, 255);background-color: rgb(178, 209, 255);border-left: 8px solid rgb(64, 211, 255);}");



    }
    if(role=="Gestion Taches"||role=="Employe")
    {
       ui->stackedWidget->setCurrentIndex(3);
       ui->frame_30->setStyleSheet("background-color: white;border-radius:25px;border-color: rgb(255, 255, 255);border: 2px solid rgb(216, 216, 216)");
       ui->tb_taches_2->setStyleSheet("QToolButton{color: rgb(234, 243, 255);background-color: rgb(178, 209, 255);border-left: 8px solid rgb(64, 211, 255);}");


    }
    if(role=="Gestion projets")
    {
       ui->stackedWidget->setCurrentIndex(4);
       ui->frame_30->setStyleSheet("background-color: white;border-radius:25px;border-color: rgb(255, 255, 255);border: 2px solid rgb(216, 216, 216)");
       ui->tb_pro_3->setStyleSheet("QToolButton{color: rgb(234, 243, 255);background-color: rgb(178, 209, 255);border-left: 8px solid rgb(64, 211, 255);}");


    }
    if(role=="Gestion Equipements")
    {
       ui->stackedWidget->setCurrentIndex(5);
       ui->frame_30->setStyleSheet("background-color: white;border-radius:25px;border-color: rgb(255, 255, 255);border: 2px solid rgb(216, 216, 216)");
       ui->tb_equi_4->setStyleSheet("QToolButton{color: rgb(234, 243, 255);background-color: rgb(178, 209, 255);border-left: 8px solid rgb(64, 211, 255);}");

    }
    if(role=="Gestion Clients")
    {
       ui->stackedWidget->setCurrentIndex(6);
       ui->frame_30->setStyleSheet("background-color: white;border-radius:25px;border-color: rgb(255, 255, 255);border: 2px solid rgb(216, 216, 216)");
       ui->tb_cli_5->setStyleSheet("QToolButton{color: rgb(234, 243, 255);background-color: rgb(178, 209, 255);border-left: 8px solid rgb(64, 211, 255);}");

    }
    else
    {
        ui->frame_12->setStyleSheet("background-color:  rgb(255, 172, 172);border: 2px solid rgb(255, 69, 69);");
        ui->frame_12->setVisible(true);
        ui->lab_erreur_login->setText(" E-mail ou Mot de passe eronne");
        timer->start(5000);
    }
}
/*---------------------------------------------------------log out---------------------------------------------------------*/
void MainWindow::on_tb_log_out_clicked()
{
    ui->lab_nom_user->clear();
    ui->lab_nom_user_2->clear();
    ui->lab_role_user->clear();
   ui->stackedWidget->setCurrentIndex(0);
   ui->lab_img_user->clear();


}

void MainWindow::on_tb_log_out_2_clicked()
{
    ui->lab_nom_user->clear();
    ui->lab_nom_user_2->clear();
    ui->lab_role_user->clear();
    ui->lab_nom_img->clear();
   ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_tb_log_out_3_clicked()
{
    ui->lab_nom_user->clear();
    ui->lab_nom_user_2->clear();
    ui->lab_role_user->clear();
   ui->stackedWidget->setCurrentIndex(0);
}

void MainWindow::on_tb_log_out_4_clicked()
{
    ui->lab_nom_user->clear();
    ui->lab_nom_user_2->clear();
    ui->lab_role_user->clear();
   ui->stackedWidget->setCurrentIndex(0);
}


void MainWindow::on_tb_log_out_5_clicked()
{
    ui->lab_nom_user->clear();
    ui->lab_nom_user_2->clear();
    ui->lab_role_user->clear();
   ui->stackedWidget->setCurrentIndex(0);
}


/*--------------------------------------------------------------------------------------------------------------------------*/
//bouton concernat chaqu tab

void MainWindow::on_tb_emp_2_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_tb_taches_2_clicked()
{ui->stackedWidget->setCurrentIndex(3);}

void MainWindow::on_tb_equi_2_clicked()
{ui->stackedWidget->setCurrentIndex(4);}

void MainWindow::on_tb_pro_2_clicked()
{ui->stackedWidget->setCurrentIndex(5);}

void MainWindow::on_tb_cli_2_clicked()
{ui->stackedWidget->setCurrentIndex(6);}






void MainWindow::on_tb_emp_3_clicked()
{ui->stackedWidget->setCurrentIndex(2);}

void MainWindow::on_tb_taches_3_clicked()
{ui->stackedWidget->setCurrentIndex(3);}

void MainWindow::on_tb_equi_3_clicked()
{ui->stackedWidget->setCurrentIndex(4);}
void MainWindow::on_tb_pro_3_clicked()
{ui->stackedWidget->setCurrentIndex(5);}
void MainWindow::on_tb_cli_3_clicked()
{ui->stackedWidget->setCurrentIndex(6);}


void MainWindow::on_tb_emp_4_clicked()
{ui->stackedWidget->setCurrentIndex(2);}
void MainWindow::on_tb_taches_4_clicked()
{ui->stackedWidget->setCurrentIndex(3);}
void MainWindow::on_tb_equi_4_clicked()
{ui->stackedWidget->setCurrentIndex(4);}
void MainWindow::on_tb_pro_4_clicked()
{ui->stackedWidget->setCurrentIndex(5);}
void MainWindow::on_tb_cli_4_clicked()
{ui->stackedWidget->setCurrentIndex(6);}
/*-------------------------------------------------------------------------------------------------------------------------*/
//menu
void MainWindow::on_pushButton_8_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_pushButton_9_clicked()
{
     ui->stackedWidget->setCurrentIndex(3);
     ui->tb_taches_2->setStyleSheet("QToolButton{color: rgb(234, 243, 255);background-color: rgb(178, 209, 255);border-left: 8px solid rgb(64, 211, 255);}");
}

void MainWindow::on_pushButton_11_clicked()
{
     ui->stackedWidget->setCurrentIndex(4);
      ui->tb_pro_3->setStyleSheet("QToolButton{color: rgb(234, 243, 255);background-color: rgb(178, 209, 255);border-left: 8px solid rgb(64, 211, 255);}");
}

void MainWindow::on_pushButton_12_clicked()
{
     ui->stackedWidget->setCurrentIndex(5);
      ui->tb_equi_4->setStyleSheet("QToolButton{color: rgb(234, 243, 255);background-color: rgb(178, 209, 255);border-left: 8px solid rgb(64, 211, 255);}");
}

void MainWindow::on_pushButton_13_clicked()
{
     ui->stackedWidget->setCurrentIndex(6);
     ui->tb_cli_5->setStyleSheet("QToolButton{color: rgb(234, 243, 255);background-color: rgb(178, 209, 255);border-left: 8px solid rgb(64, 211, 255);}");

}
/*-------------------------------------------------------------------------------------------------------------------------*/
void MainWindow::Stat_emp()
{
   // QChartView *chartView ;
    QSqlQuery q1,q2,q3,q4;
    qreal tot=0,c1=0,c2=0;

    int fontId2 = QFontDatabase::addApplicationFont(":/fonts/fonts/TT-Wellingtons-Trial-Medium.otf");
    QString fontName2 = QFontDatabase::applicationFontFamilies(fontId2).at(0);
    QFont myFont2(fontName2,18);

    q1.prepare("SELECT * FROM EMPLOYE");
    q1.exec();
    q2.prepare("SELECT * FROM EMPLOYE WHERE GENRE='Homme'");
    q2.exec();
    q3.prepare("SELECT * FROM EMPLOYE WHERE GENRE='Femme'");
    q3.exec();

    while (q1.next()){tot++;}
    while (q2.next()){c1++;}
    while (q3.next()){c2++;}

    c1=c1/tot; c2=c2/tot;
    QPieSeries *series = new QPieSeries();
        series->setHoleSize(0.35);




        QPieSlice *slicef = series->append("Femme", c2);
        slicef->setExploded();
        slicef->setLabelFont(myFont2);
        slicef->setLabelBrush(QBrush(Qt::white));
        slicef->setLabelVisible();
        QPieSlice *sliceh = series->append("Homme", c1);
        sliceh->setExploded();
        sliceh->setLabelFont(myFont2);
        sliceh->setLabelBrush(QBrush(Qt::white));
        sliceh->setLabelVisible();





        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setAnimationOptions(QChart::SeriesAnimations);
        chart->setTitle("Nombre d'employés par genre");
        chart->setTheme(QChart::ChartThemeLight);
         chart->setTitleFont(myFont2);

         series->setLabelsVisible();
         series->setLabelsPosition(QPieSlice::LabelInsideHorizontal);

         for(auto slice : series->slices())
             slice->setLabel(QString("%1%").arg(100*slice->percentage(), 0, 'f', 1));


        QChartView *chartview = new QChartView(chart,ui->lab_chart_pie);
        chartview->setRenderHint(QPainter::Antialiasing);
        chartview->setMinimumSize(600,600);
        chartview->show();

        ;
    /*QPieSeries *series = new QPieSeries();
    series->append("Homme",c1);
    series->append("Femme",c2);

    QChart *chart = new QChart();
    chart->addSeries(series);
    chart->legend()->show();
    chart->setAnimationOptions(QChart::AllAnimations);
    chart->setTheme(QChart::ChartThemeQt);
    chartView = new QChartView(chart,ui->lab_chart_pie);
    chartView->setRenderHint(QPainter::Antialiasing);
    chartView->setMinimumSize(570,570);
    chartView->show();*/
}

void MainWindow::Stat_salaire()
{

   QSqlQuery qs_rf,qs_tf,qs_pf,qs_ef,qs_cf;
   QSqlQuery qs_rh,qs_th,qs_ph,qs_eh,qs_ch;

   int rh_f{0},t_f{0},p_f{0},e_f{0},c_f{0};
   int rh_h{0},t_h{0},p_h{0},e_h{0},c_h{0};

   int fontId2 = QFontDatabase::addApplicationFont(":/fonts/fonts/TT-Wellingtons-Trial-Medium.otf");
   QString fontName2 = QFontDatabase::applicationFontFamilies(fontId2).at(0);
   QFont myFont2(fontName2,11);

   int fontId3 = QFontDatabase::addApplicationFont(":/fonts/fonts/TT-Wellingtons-Trial-Medium.otf");
   QString fontName3 = QFontDatabase::applicationFontFamilies(fontId3).at(0);
   QFont myFont3(fontName3,18);


        employe e;
        // Assign names to the set of bars used

        qs_rf.prepare("SELECT SUM(SALAIRE) FROM EMPLOYE WHERE GENRE='Femme'  AND ROLE='Gestion Employe' ");
        qs_rf.exec();
        qs_tf.prepare("SELECT SUM(SALAIRE) FROM EMPLOYE WHERE GENRE='Femme'  AND ROLE='Gestion Taches' ");
        qs_tf.exec();
        qs_pf.prepare("SELECT SUM(SALAIRE)  FROM EMPLOYE WHERE GENRE='Femme' AND ROLE='Gestion Projets' ");
        qs_pf.exec();
        qs_ef.prepare("SELECT SUM(SALAIRE)  FROM EMPLOYE WHERE GENRE='Femme' AND ROLE='Gestion Equipements'");
        qs_ef.exec();
        qs_cf.prepare("SELECT SUM(SALAIRE)  FROM EMPLOYE WHERE GENRE='Femme' AND ROLE='Gestion Clients' ");
        qs_cf.exec();

        qs_rh.prepare("SELECT SUM(SALAIRE)  FROM EMPLOYE WHERE GENRE='Homme' AND ROLE='Gestion Employe' ");
        qs_rh.exec();
        qs_th.prepare("SELECT SUM(SALAIRE)  FROM EMPLOYE WHERE GENRE='Homme' AND ROLE='Gestion Taches' ");
        qs_th.exec();
        qs_ph.prepare("SELECT SUM(SALAIRE)  FROM EMPLOYE WHERE GENRE='Homme' AND ROLE='Gestion Projets' ");
        qs_ph.exec();
        qs_eh.prepare("SELECT SUM(SALAIRE)  FROM EMPLOYE WHERE GENRE='Homme' AND ROLE='Gestion Equipements'");
        qs_eh.exec();
        qs_ch.prepare("SELECT SUM(SALAIRE)  FROM EMPLOYE WHERE GENRE='Homme' AND ROLE='Gestion Clients' ");
        qs_ch.exec();





        while (qs_rf.next())
        {
            rh_f = qs_rf.value(0).toInt();
        }
        while (qs_tf.next())
        {
            t_f=qs_tf.value(0).toInt();
        }

        while (qs_pf.next())
        {
            p_f= qs_pf.value(0).toInt();
        }
        while (qs_ef.next())
        {
            e_f= qs_ef.value(0).toInt();
        }

        while (qs_cf.next())
        {
            c_f= qs_cf.value(0).toInt();
        }



        while (qs_rh.next())
        {
            rh_h= qs_rh.value(0).toInt();
        }
        while (qs_th.next())
        {
            t_h= qs_th.value(0).toInt();
        }

        while (qs_ph.next())
        {
            p_h= qs_ph.value(0).toInt();
        }
        while (qs_eh.next())
        {
            e_h= qs_eh.value(0).toInt();
        }


        while (qs_ch.next())
        {
            c_h= qs_ch.value(0).toInt();
        }



        QBarSet *set0 = new QBarSet("Homme");
        QBarSet *set1 = new QBarSet("Femme");
        *set0 << rh_h << t_h << p_h << e_h << c_h ;
        *set1 << rh_f << t_f << p_f << e_f << c_f ;

        QBarSeries *series = new QBarSeries();
        series->append(set0);
        series->append(set1);

        QChart *chart = new QChart();
        chart->addSeries(series);
        chart->setTitle(" Salaire selon role et genre ");
        chart->setAnimationOptions(QChart::SeriesAnimations);


       QStringList categories;
       categories << "Employe" << "Taches" << "Projet" << "Equipement" << "Client" ;
       QBarCategoryAxis *axisX = new QBarCategoryAxis();
       axisX->append(categories);
       chart->addAxis(axisX, Qt::AlignBottom);
       series->attachAxis(axisX);
       axisX->setLabelsFont(myFont2);
       axisX->setGridLineVisible(true);



        QChartView *chartView = new QChartView(chart,ui->lab_chart_bar);
        chartView->setMinimumSize(600,600);
        chartView->show();
        chart->setTitleFont(myFont3);




}


void MainWindow::on_pushButton_14_clicked()
{
     this->Stat_emp();
    this->Stat_salaire();
}



int mdp=1;
void MainWindow::on_pb_password_clicked()
{
    QIcon hide(":/icon/icons/hide.png");
    QIcon show(":/icon/icons/show.png");


  if(mdp==1)
  {
      ui->le_mdp_L->setEchoMode(QLineEdit::Password);
      ui->pb_password->setIcon(hide);
     mdp=0;
  }
  else{
      ui->le_mdp_L->setEchoMode(QLineEdit::Normal);
      ui->pb_password->setIcon(show);
      mdp=1;
  }
}

void MainWindow::on_tb_menu_emp_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);

}

void MainWindow::on_tb_menu_t_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);

}

void MainWindow::on_tb_menu_p_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);

}

void MainWindow::on_tb_menu_e_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);

}

void MainWindow::on_tb_menu_c_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);

}

void MainWindow::on_pb_add_pM_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this,tr("choose"),"",tr(""));
    if(QString::compare(filename,QString())!=0)
    {
        QImage image;
        bool valid=image.load(filename);
        if(valid)
        {
            ui->le_nomphoto_2->setText(filename);
            image=image.scaledToWidth(ui->profilePictureLabel_2->width(),Qt::SmoothTransformation);
            ui->profilePictureLabel->setPixmap(QPixmap::fromImage(image));
        }
        else
        {
            QMessageBox::information(this, tr("ERROR"), QString(tr("Not Valid!")));
        }
    }
}

void MainWindow::on_tb_from_txt_clicked()
{
    QString fileName = QFileDialog::getOpenFileName(this, tr("Select Text File"), "/", tr("Text Files (*.txt)"));
    int i{0};
    // open the text file for reading
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, tr("Error"), tr("Unable to open file: ") + file.errorString());
        return;
    }

    QTextStream in(&file);
    QString AllText = in.readAll();
    int toatalLine= AllText.count("\n");
    file.seek(0);

    // read the data from the text file

    while (!in.atEnd()) {

        i++;
        QString line = in.readLine();
        QStringList fields = line.split(',');


        int progress = static_cast<int>(100.0 * i / toatalLine);
        ui->progressBar->setVisible(true);
        ui->progressBar->setValue(progress);

        // assuming that the text file contains employee data in the format:
        // "name,age,salary,designation"
       if(fields.count()==13)
       {
        int     cin=fields[0].toInt();
        QString nom=fields[1];
        QString prenom=fields[2];
        QString date_emb=fields[3];
        QString date_n=fields[4];
        float salaire = fields[5].toInt();
        QString email=fields[6];
        QString mdp= fields[7];
        QString adresse=fields[8];
        int idP=fields[9].toFloat();
         QString role=fields[10];
         QString genre =fields[11];
         QString img = fields[12];






         employe e(cin,nom,prenom,date_emb,date_n,salaire,email,mdp,adresse,role,idP,genre,img);

        bool test;

         test=e.ajouter();
         QMessageBox msgBox;
         if(test)
         {
             ui->t_affichage->setModel(e.afficher());
              ui->frame_31->setVisible(true);
              ui->label_27->setText("succees ligne  "+ QString::number(i));
              ui->frame_31->setVisible(true);



          ui->le_cin->clear();
          ui->le_nom->clear();
          ui->le_prenom->clear();
          ui->le_dn->clear();
          ui->le_salaire->clear();
          ui->le_role->clear();
          ui->le_emb->clear();
          ui->le_mdp->clear();
          ui->le_adresse->clear();
          ui->le_id_p->clear();


         }
         else
         {
             ui->frame_31->setVisible(true);
             ui->progressBar->setVisible(true);
             ui->label_27->setText("Erreur a la ligne "+ QString::number(i));
             break;

         }

     }




    }
    file.close();
}

void MainWindow::on_tb_pdf_clicked()
{
   d = new Dialog(this);
   d->show();
}

void MainWindow::on_tb_from_csv_clicked()
{
   QString fileName = QFileDialog::getOpenFileName(this, tr("Select CSV File"), "/", tr("CSV Files (*.csv)"));
    int i{0};
    // open the text file for reading
    QFile file(fileName);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        QMessageBox::critical(this, tr("Error"), tr("Unable to open file: ") + file.errorString());
        return;
    }

    QTextStream in(&file);
    QString AllText = in.readAll();
    int toatalLine= AllText.count("\n");
    file.seek(0);

    // read the data from the text file

    while (!in.atEnd()) {

        i++;
       QString line = in.readLine().trimmed();
        QStringList fields = line.split(',');


        int progress = static_cast<int>(100.0 * i / toatalLine);
        ui->progressBar->setVisible(true);
        ui->progressBar->setValue(progress);

        // assuming that the text file contains employee data in the format:
        // "name,age,salary,designation"
       if(fields.count()==13)
       {
        int     cin=fields[0].toInt();
        QString nom=fields[1];
        QString prenom=fields[2];
        QString date_emb=fields[3];
        QString date_n=fields[4];
        float salaire = fields[5].toInt();
        QString email=fields[6];
        QString mdp= fields[7];
        QString adresse=fields[8];
        int idP=fields[9].toFloat();
         QString role=fields[10];
         QString genre =fields[11];
         QString img = fields[12];






         employe e(cin,nom,prenom,date_emb,date_n,salaire,email,mdp,adresse,role,idP,genre,img);

        bool test;

         test=e.ajouter();
         QMessageBox msgBox;
         if(test)
         {
             ui->t_affichage->setModel(e.afficher());
              ui->frame_31->setVisible(true);
              ui->label_27->setText("succees ligne  "+ QString::number(i));
              ui->frame_31->setVisible(true);



          ui->le_cin->clear();
          ui->le_nom->clear();
          ui->le_prenom->clear();
          ui->le_dn->clear();
          ui->le_salaire->clear();
          ui->le_role->clear();
          ui->le_emb->clear();
          ui->le_mdp->clear();
          ui->le_adresse->clear();
          ui->le_id_p->clear();


         }
         else
         {
             ui->frame_31->setVisible(true);
             ui->progressBar->setVisible(true);
             ui->label_27->setText("Erreur a la ligne "+ QString::number(i));
             break;

         }

     }




    }
    file.close();
}

void MainWindow::on_tb_emp_clicked()
{
    ui->stackedWidget->setCurrentIndex(2);
}

void MainWindow::on_tb_taches_clicked()
{
    ui->stackedWidget->setCurrentIndex(3);
}

void MainWindow::on_tb_equi_clicked()
{
    ui->stackedWidget->setCurrentIndex(4);
}

void MainWindow::on_tb_pro_clicked()
{
    ui->stackedWidget->setCurrentIndex(5);
}

void MainWindow::on_tb_cli_clicked()
{
    ui->stackedWidget->setCurrentIndex(6);

}

/***-------------------*/


/*video*/
void MainWindow::on_tb_help_clicked()
{
/*
    // Create a new window to display the video
       QMainWindow *videoWindow = new QMainWindow(this);
       QVideoWidget *videoWidget = new QVideoWidget(videoWindow);
       videoWindow->setCentralWidget(videoWidget);

       // Create a media player to control the video playback
       QMediaPlayer *player = new QMediaPlayer(videoWindow);

       // Set the video output to the video widget
       player->setVideoOutput(videoWidget);

       // Set the media source to the video file you want to play
       QString filename = "C:/Users/Hassen/Desktop/Nouveau dossier/untitled2/Evolve tutorial";
       player->setMedia(QUrl::fromLocalFile(filename));

       // Play the video
       videoWindow->setGeometry(100,100,300,400);
       videoWindow->show();
       player->play();


       // Show the video window
*/

    QString filename = "C:/Users/Hassen/Desktop/TD/Nouveau dossier/untitled2/Evolve tutorial.mp4";
    QDesktopServices::openUrl(QUrl::fromLocalFile(filename));


}

/*night mode */
/*--------------------------------------------------------equipement-----------------------------------------------------------------------------------------*/
void MainWindow::on_pb_ajouter_equi_clicked()
{
    int id_equipement=ui->le_id_2e->text().toInt();
    int qantite=ui->le_quantite_2e->text().toInt();
    QString nom=ui->le_nom_2e->text();
    QString marque=ui->le_marque_2e->text();
 Equipements E(id_equipement,qantite,nom,marque);
bool test=E.ajouter();
if(test)
{

    ui->tableView_equi->setModel(E.afficher("",""));
    QMessageBox::information(nullptr,QObject::tr("ok"),
                             QObject::tr("ajout effectué.\n"
                                         "click cancel to exit."),QMessageBox::Cancel);

}
else
    QMessageBox::critical(nullptr,QObject::tr("not ok"),
                          QObject::tr("ajout non effectué .\n"
                                      "Click cancel to exit."), QMessageBox::Cancel);

}

void MainWindow::on_pb_modifier_equi_clicked()
{
    int id = ui->le_id_3e->text().toInt();
    int quantite = ui->le_quantite_3e->text().toInt();
    QString nom=ui->le_nom_3e->text();
    QString marque =ui->le_marque_3e->text();



    Equipements e(id,quantite,nom,marque);

    bool test=e.modifier(id);
        if(test)
        {


            QMessageBox::information(nullptr, QObject::tr("ok"),QObject::tr("Modification avec succes.\n" "Click Close to exit."), QMessageBox::Close);
    }else
            QMessageBox::critical(nullptr, QObject::tr("not ok"),QObject::tr("Modification echoue.\n" "Click Close to exit."), QMessageBox::Close);
}

QStringList getEquipementData(int ID)
{
    QStringList result;
    QSqlQuery query;
    query.prepare("SELECT * FROM EQUIPEMENT WHERE ID_EQUIPEMENT= ?");
    query.addBindValue(ID);
    query.exec();
    if (query.next()) {
        for (int i = 0; i < query.record().count(); i++) {
            result.append(query.value(i).toString());
        }
    }

    return result;
}


QString getDataFromList(QStringList list, int index)
{
    QString result;

    if (index >= 0 && index < list.size()) {
        result = list.at(index);
    }

    return result;
}

void MainWindow::on_toolButton_recherche_equi_clicked()
{
    int ID = ui->le_recherche_e->text().toInt();
       Equipements E(ID);
       if (E.existance())

       {
           QStringList list = getEquipementData(ID);
           ui->le_id_3e->setText(getDataFromList(list,0));
           ui->le_quantite_3e->setText(getDataFromList(list,1));
           ui->le_nom_3e->setText(getDataFromList(list,2));
           ui->le_marque_3e->setText(getDataFromList(list,3));

       }
       else
           QMessageBox::critical(nullptr, "Not OK", "ID does not exist !");

}

void MainWindow::on_toolButton_refresh_equi_clicked()
{
     ui->tableView_equi->setModel(Etmp.afficher("",""));
}

void MainWindow::on_pb_supprimer_equi_clicked()
{
    QItemSelectionModel *select = ui->tableView_equi->selectionModel();
        int ID = select->selectedRows(0).value(0).data().toInt();
        if (ID)
        {
            Equipements E(ID);

            if (E.existance())
            {
            bool test = E.supprimer(ID);
            if(test)
            {
                ui->tableView_equi->setModel(Etmp.afficher("",""));
                QMessageBox::information(nullptr, QObject::tr("OK"),
                            QObject::tr("Suppression effectué.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);

            }
            else
                QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                            QObject::tr("Suppression non effectué.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
            }
            else
            {
                QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                            QObject::tr("Client n'existe pas.\n"
                                        "Click Cancel to exit."), QMessageBox::Cancel);
            }
        }
        else
        {
            QMessageBox::critical(nullptr, QObject::tr("Not OK"),
                        QObject::tr("Veuillez selectionné un client.\n"
                                    "Click Cancel to exit."), QMessageBox::Cancel);
        }
}

void MainWindow::on_pb_pdf_equi_clicked()
{
    QString fileName = QFileDialog::getSaveFileName(this, "Export to PDF", "", "PDF files (*.pdf)");
    if (!fileName.isEmpty()) {
       exportToPdf(ui->tableView_equi, fileName);
    }
}

void MainWindow::on_rb_quantite_equi_asc_2_toggled(bool checked)
{
    if (checked)
        ui->tableView_equi->setModel(Etmp.afficher("QANTITE","ASC"));
}

void MainWindow::on_rb_quantite_equi_dsc_2_toggled(bool checked)
{
    if (checked)
        ui->tableView_equi->setModel(Etmp.afficher("QANTITE","DESC"));
}

void MainWindow::on_rb_nom_equi_asc_2_toggled(bool checked)
{
    if (checked)
            ui->tableView_equi->setModel(Etmp.afficher("NOM","ASC"));
}

void MainWindow::on_rb_nom_equi_dsc_2_toggled(bool checked)
{
    if (checked)
            ui->tableView_equi->setModel(Etmp.afficher("NOM","DESC"));
}
