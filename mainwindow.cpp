#include <QCoreApplication>
#include <QProcess>
#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "Gra.cpp"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->zagrajPonownieButton->setVisible(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::czyjaWygrana()
{
    if (czyjaKolej==1 &&((tablica[0][0] != 0 && tablica[0][0] == tablica[0][1] && tablica[0][0] == tablica[0][2]) ||
        (tablica[1][0] != 0 && tablica[1][0] == tablica[1][1] && tablica[1][0] == tablica[1][2]) ||
        (tablica[2][0] != 0 && tablica[2][0] == tablica[2][1] && tablica[2][0] == tablica[2][2]) ||
        (tablica[0][0] != 0 && tablica[0][0] == tablica[1][0] && tablica[0][0] == tablica[2][0]) ||
        (tablica[0][1] != 0 && tablica[0][1] == tablica[1][1] && tablica[0][1] == tablica[2][1]) ||
        (tablica[0][2] != 0 && tablica[0][2] == tablica[1][2] && tablica[0][2] == tablica[2][2]) ||
        (tablica[0][0] != 0 && tablica[0][0] == tablica[1][1] && tablica[0][0] == tablica[2][2]) ||
        (tablica[2][0] != 0 && tablica[2][0] == tablica[1][1] && tablica[2][0] == tablica[0][2])))
    {
        ui->WinLabel->setText("KONIEC GRY! WYGRANA KÓŁKA");
        ui->pushButton_1->setEnabled(false);
        ui->pushButton_2->setEnabled(false);
        ui->pushButton_3->setEnabled(false);
        ui->pushButton_4->setEnabled(false);
        ui->pushButton_5->setEnabled(false);
        ui->pushButton_6->setEnabled(false);
        ui->pushButton_7->setEnabled(false);
        ui->pushButton_8->setEnabled(false);
        ui->pushButton_9->setEnabled(false);
        ui->turaLabel->setVisible(false);
        ui->xoLabel->setVisible(false);
        ui->zagrajPonownieButton->setVisible(true);
    }
    else if(czyjaKolej==2 &&((tablica[0][0] != 0 && tablica[0][0] == tablica[0][1] && tablica[0][0] == tablica[0][2]) ||
        (tablica[1][0] != 0 && tablica[1][0] == tablica[1][1] && tablica[1][0] == tablica[1][2]) ||
        (tablica[2][0] != 0 && tablica[2][0] == tablica[2][1] && tablica[2][0] == tablica[2][2]) ||
        (tablica[0][0] != 0 && tablica[0][0] == tablica[1][0] && tablica[0][0] == tablica[2][0]) ||
        (tablica[0][1] != 0 && tablica[0][1] == tablica[1][1] && tablica[0][1] == tablica[2][1]) ||
        (tablica[0][2] != 0 && tablica[0][2] == tablica[1][2] && tablica[0][2] == tablica[2][2]) ||
        (tablica[0][0] != 0 && tablica[0][0] == tablica[1][1] && tablica[0][0] == tablica[2][2]) ||
        (tablica[2][0] != 0 && tablica[2][0] == tablica[1][1] && tablica[2][0] == tablica[0][2])))
    {
        ui->WinLabel->setText("KONIEC GRY! WYGRANA KRZYŻYKA");
        ui->pushButton_1->setEnabled(false);
        ui->pushButton_2->setEnabled(false);
        ui->pushButton_3->setEnabled(false);
        ui->pushButton_4->setEnabled(false);
        ui->pushButton_5->setEnabled(false);
        ui->pushButton_6->setEnabled(false);
        ui->pushButton_7->setEnabled(false);
        ui->pushButton_8->setEnabled(false);
        ui->pushButton_9->setEnabled(false);
        ui->turaLabel->setVisible(false);
        ui->xoLabel->setVisible(false);
        ui->zagrajPonownieButton->setVisible(true);
    }
    else if(numerTury==9)
    {
        ui->WinLabel->setText("KONIEC GRY! REMIS");
        ui->pushButton_1->setEnabled(false);
        ui->pushButton_2->setEnabled(false);
        ui->pushButton_3->setEnabled(false);
        ui->pushButton_4->setEnabled(false);
        ui->pushButton_5->setEnabled(false);
        ui->pushButton_6->setEnabled(false);
        ui->pushButton_7->setEnabled(false);
        ui->pushButton_8->setEnabled(false);
        ui->pushButton_9->setEnabled(false);
        ui->turaLabel->setVisible(false);
        ui->xoLabel->setVisible(false);
        ui->zagrajPonownieButton->setVisible(true);
    }
}


void MainWindow::on_pushButton_1_clicked()
{
    QFont font = ui->pushButton_1->font();
    font.setPointSize(50);
    ui->pushButton_1->setFont(font);

    if(czyjaKolej==1)
    {
        ui->xoLabel->setText("O");
        ui->pushButton_1->setText("X");
        czyjaKolej=2;
        tablica[0][0]=1;
        ui->pushButton_1->setEnabled(false);
    }
    else
    {
        ui->xoLabel->setText("X");
        ui->pushButton_1->setText("O");
        czyjaKolej=1;
        tablica[0][0]=2;
        ui->pushButton_1->setEnabled(false);
    }
        czyjaWygrana();
    numerTury+=1;
}


void MainWindow::on_pushButton_2_clicked()
{
    QFont font = ui->pushButton_2->font();
    font.setPointSize(50);
    ui->pushButton_2->setFont(font);

    if(czyjaKolej==1)
    {
        ui->xoLabel->setText("O");
        ui->pushButton_2->setText("X");
        czyjaKolej=2;
        tablica[0][1]=1;
        ui->pushButton_2->setEnabled(false);
    }
    else
    {
        ui->xoLabel->setText("X");
        ui->pushButton_2->setText("O");
        czyjaKolej=1;
        tablica[0][2]=2;
        ui->pushButton_2->setEnabled(false);
    }
        czyjaWygrana();
    numerTury+=1;
}


void MainWindow::on_pushButton_3_clicked()
{
    QFont font = ui->pushButton_3->font();
    font.setPointSize(50);
    ui->pushButton_3->setFont(font);

    if(czyjaKolej==1)
    {
        ui->xoLabel->setText("O");
        ui->pushButton_3->setText("X");
        czyjaKolej=2;
        tablica[0][2]=1;
        ui->pushButton_3->setEnabled(false);
    }
    else
    {
        ui->xoLabel->setText("X");
        ui->pushButton_3->setText("O");
        czyjaKolej=1;
        tablica[0][2]=2;
        ui->pushButton_3->setEnabled(false);
    }
        czyjaWygrana();
    numerTury+=1;
}


void MainWindow::on_pushButton_4_clicked()
{
    QFont font = ui->pushButton_4->font();
    font.setPointSize(50);
    ui->pushButton_4->setFont(font);

    if(czyjaKolej==1)
    {
        ui->xoLabel->setText("O");
        ui->pushButton_4->setText("X");
        czyjaKolej=2;
        tablica[1][0]=1;
        ui->pushButton_4->setEnabled(false);
    }
    else
    {
        ui->xoLabel->setText("X");
        ui->pushButton_4->setText("O");
        czyjaKolej=1;
        tablica[1][0]=2;
        ui->pushButton_4->setEnabled(false);
    }
        czyjaWygrana();
    numerTury+=1;
}


void MainWindow::on_pushButton_5_clicked()
{
    QFont font = ui->pushButton_5->font();
    font.setPointSize(50);
    ui->pushButton_5->setFont(font);

    if(czyjaKolej==1)
    {
        ui->xoLabel->setText("O");
        ui->pushButton_5->setText("X");
        czyjaKolej=2;
        tablica[1][1]=1;
        ui->pushButton_5->setEnabled(false);
    }
    else
    {
        ui->xoLabel->setText("X");
        ui->pushButton_5->setText("O");
        czyjaKolej=1;
        tablica[1][1]=2;
        ui->pushButton_5->setEnabled(false);
    }
        czyjaWygrana();
    numerTury+=1;
}


void MainWindow::on_pushButton_6_clicked()
{
    QFont font = ui->pushButton_6->font();
    font.setPointSize(50);
    ui->pushButton_6->setFont(font);

    if  (czyjaKolej==1)
    {
        ui->xoLabel->setText("O");
        ui->pushButton_6->setText("X");
        czyjaKolej=2;
        tablica[1][2]=1;
        ui->pushButton_6->setEnabled(false);
    }
    else
    {
        ui->xoLabel->setText("X");
        ui->pushButton_6->setText("O");
        czyjaKolej=1;
        tablica[1][2]=2;
        ui->pushButton_6->setEnabled(false);
    }
        czyjaWygrana();
    numerTury+=1;
}


void MainWindow::on_pushButton_7_clicked()
{
    QFont font = ui->pushButton_7->font();
    font.setPointSize(50);
    ui->pushButton_7->setFont(font);

    if  (czyjaKolej==1)
    {
        ui->xoLabel->setText("O");
        ui->pushButton_7->setText("X");
        czyjaKolej=2;
        tablica[2][0]=1;
        ui->pushButton_7->setEnabled(false);
    }
    else
    {
        ui->xoLabel->setText("X");
        ui->pushButton_7->setText("O");
        czyjaKolej=1;
        tablica[2][0]=2;
        ui->pushButton_7->setEnabled(false);
    }
        czyjaWygrana();
    numerTury+=1;
}


void MainWindow::on_pushButton_8_clicked()
{
    QFont font = ui->pushButton_8->font();
    font.setPointSize(50);
    ui->pushButton_8->setFont(font);

    if  (czyjaKolej==1)
    {
        ui->xoLabel->setText("O");
        ui->pushButton_8->setText("X");
        czyjaKolej=2;
        tablica[2][1]=1;
        ui->pushButton_8->setEnabled(false);
    }
    else
    {
        ui->xoLabel->setText("X");
        ui->pushButton_8->setText("O");
        czyjaKolej=1;
        tablica[2][1]=2;
        ui->pushButton_8->setEnabled(false);
    }
        czyjaWygrana();
    numerTury+=1;
}


void MainWindow::on_pushButton_9_clicked()
{
    QFont font = ui->pushButton_9->font();
    font.setPointSize(50);
    ui->pushButton_9->setFont(font);

    if  (czyjaKolej==1)
    {
        ui->xoLabel->setText("O");
        ui->pushButton_9->setText("X");
        czyjaKolej=2;
        tablica[2][2]=1;
        ui->pushButton_9->setEnabled(false);
    }
    else
    {
        ui->xoLabel->setText("X");
        ui->pushButton_9->setText("O");
        czyjaKolej=1;
        tablica[2][2]=2;
        ui->pushButton_9->setEnabled(false);
    }
        czyjaWygrana();
    numerTury+=1;
}


void MainWindow::on_zagrajPonownieButton_clicked()
{
    QCoreApplication::quit();
    QProcess::startDetached(QCoreApplication::applicationFilePath());
}

