#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QTimer>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>
#include "dialog.h"
#include <QMediaPlayer>
#include <QVideoWidget>
#include <equipements.h>

QT_CHARTS_USE_NAMESPACE


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_pb_add_p_clicked();

    void on_pushButton_7_clicked();

    void on_pb_modifier_clicked();

    void on_tb_refresh_clicked();

    void on_rb_salaire_asc_clicked();

    void on_rb_nom_asc_clicked();

    void on_rb_salaire_dsc_clicked();

    void on_rb_nom_dsc_clicked();

    void on_pb_supprimer_clicked();
    void clearStatusLabel();

    void on_pb_login_clicked();

    void on_tb_log_out_clicked();

    void on_pushButton_8_clicked();

    void on_pushButton_9_clicked();

    void on_pushButton_11_clicked();

    void on_pushButton_12_clicked();

    void on_pushButton_13_clicked();

    void  Stat_emp();

    void Stat_salaire();


    void on_pushButton_14_clicked();

    void on_tb_log_out_2_clicked();

    void on_tb_log_out_3_clicked();

    void on_tb_log_out_4_clicked();

    void on_tb_log_out_5_clicked();

    void on_pb_password_clicked();

    void on_tb_menu_emp_clicked();

    void on_tb_menu_t_clicked();

    void on_tb_menu_p_clicked();

    void on_tb_menu_e_clicked();

    void on_tb_menu_c_clicked();

    void on_pb_add_pM_clicked();

    void on_tb_from_txt_clicked();

    void on_tb_pdf_clicked();

    void on_tb_from_csv_clicked();



    void on_tb_emp_clicked();

    void on_tb_taches_clicked();

    void on_tb_equi_clicked();

    void on_tb_pro_clicked();

    void on_tb_cli_clicked();


    void on_tb_emp_2_clicked();

    void on_tb_taches_2_clicked();

    void on_tb_equi_2_clicked();

    void on_tb_pro_2_clicked();

    void on_tb_cli_2_clicked();






    void on_tb_emp_3_clicked();

    void on_tb_taches_3_clicked();

    void on_tb_equi_3_clicked();

    void on_tb_pro_3_clicked();

    void on_tb_cli_3_clicked();



    void on_tb_emp_4_clicked();

    void on_tb_taches_4_clicked();

    void on_tb_equi_4_clicked();

    void on_tb_pro_4_clicked();

    void on_tb_cli_4_clicked();




    void on_tb_help_clicked();


    void on_pb_ajouter_equi_clicked();

    void on_pb_modifier_equi_clicked();

    void on_toolButton_recherche_equi_clicked();

    void on_toolButton_refresh_equi_clicked();

    void on_pb_supprimer_equi_clicked();

    void on_pb_pdf_equi_clicked();

    void on_rb_quantite_equi_asc_2_toggled(bool checked);

    void on_rb_quantite_equi_dsc_2_toggled(bool checked);

    void on_rb_nom_equi_asc_2_toggled(bool checked);

    void on_rb_nom_equi_dsc_2_toggled(bool checked);

private:
    Ui::MainWindow *ui;
     Dialog *d;
     QTimer *timer;
     QMediaPlayer *player;
     QVideoWidget *videoWidget;
      Equipements Etmp;

};
#endif // MAINWINDOW_H
