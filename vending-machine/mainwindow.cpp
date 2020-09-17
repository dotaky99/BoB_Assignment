#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->pbCoffee->setEnabled(true);
    ui->pbCoffee->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbMilk->setEnabled(false);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::changeMoney(int diff)
{
    money += diff;

    if(money >= 100)
        ui->pbCoffee->setEnabled(true);
    if(money >= 150)
        ui->pbTea->setEnabled(true);
    if(money >= 200)
        ui->pbMilk->setEnabled(true);

    ui->lcdNumber->display(money);
}

void MainWindow::on_pb10_clicked()
{
    changeMoney(10);

}

void MainWindow::on_pb50_clicked()
{
    changeMoney(50);

}

void MainWindow::on_pb100_clicked()
{
    changeMoney(100);
}

void MainWindow::on_pb500_clicked()
{
    changeMoney(500);
}

void MainWindow::on_pbCoffee_clicked()
{
    money -= 100;
    if(money < 100)
        ui->pbCoffee->setEnabled(false);
    if(money < 150)
        ui->pbTea->setEnabled(false);
    if(money < 200)
        ui->pbMilk->setEnabled(false);
    ui->lcdNumber->display(money);
}

void MainWindow::on_pbTea_clicked()
{
    money -= 150;
    if(money < 100)
        ui->pbCoffee->setEnabled(false);
    if(money < 150)
        ui->pbTea->setEnabled(false);
    if(money < 200)
        ui->pbMilk->setEnabled(false);
    ui->lcdNumber->display(money);
}

void MainWindow::on_pbMilk_clicked()
{
    money -= 200;
    if(money < 100)
        ui->pbCoffee->setEnabled(false);
    if(money < 150)
        ui->pbTea->setEnabled(false);
    if(money < 200)
        ui->pbMilk->setEnabled(false);
    ui->lcdNumber->display(money);
}

void MainWindow::on_pbReset_clicked()
{
    QMessageBox m;
    char s1[10];
    sprintf(s1, "%d", money);
    m.information(nullptr, "Take your extra coin", s1);
    money = 0;
    ui->lcdNumber->display(money);
}
