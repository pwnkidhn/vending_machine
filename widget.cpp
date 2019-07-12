#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QString>


Widget::Widget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Widget)
{
    ui->setupUi(this);
}

Widget::~Widget()
{
    delete ui;
}
void Widget::changeMoney(int n){

    money +=n;
    ui->lcdNumber->display(money);
    if(money<100){
        ui->pbCoffee->setEnabled(false);
        ui->pbTea->setEnabled(false);
        ui->pbCoke->setEnabled(false);
    }else if(100<=money && money<150){
        ui->pbCoffee->setEnabled(true);
        ui->pbTea->setEnabled(false);
        ui->pbCoke->setEnabled(false);
    }else if(150<=money && money<200){
        ui->pbCoffee->setEnabled(true);
        ui->pbTea->setEnabled(true);
        ui->pbCoke->setEnabled(false);
    }else {
        ui->pbCoffee->setEnabled(true);
        ui->pbTea->setEnabled(true);
        ui->pbCoke->setEnabled(true);
    }
}
void Widget::defaultCondition(){
    ui->pbCoffee->setEnabled(false);
    ui->pbTea->setEnabled(false);
    ui->pbCoke->setEnabled(false);
}
QString Widget::Exchange(){
    int a=0,b=0,c=0,d=0;
    QString a1;
    a = money/500;
    b = (money%500)/100;
    c = (money%500%100)/50;
    d = (money%500%100%50)/10;
    a1 = QStringLiteral("500원 = %1\n100원 = %2\n50원 = %3\n10원 = %4\n").arg(a).arg(b).arg(c).arg(d);
    money = 0;
    defaultCondition();
    return a1;
}
void Widget::on_pb10_clicked()
{
    changeMoney(10);
}

void Widget::on_pb50_clicked()
{
    changeMoney(50);
}

void Widget::on_pb100_clicked()
{
    changeMoney(100);
}

void Widget::on_pb500_clicked()
{
    changeMoney(500);
}

void Widget::on_pbCoffee_clicked()
{
    changeMoney(-100);
}

void Widget::on_pbTea_clicked()
{
    changeMoney(-150);
}

void Widget::on_pbCoke_clicked()
{
    changeMoney(-200);
}

void Widget::on_pushButton_clicked()
{
    QMessageBox box;
    QString a1 = Exchange();
    box.information(nullptr,"return",a1);
    ui->lcdNumber->display(money);
}
