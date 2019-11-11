#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDesktopWidget>
#include "calculate.h"
#include "String"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QDesktopWidget * desktop = QApplication::desktop();
    move((desktop->width() - this->width())/2,(desktop->height() - this->height())/2);
    ui->setupUi(this);
    ui->lineEdit->setEnabled(false);//设置linEdit不可以编辑
    ui->lineEdit->setAlignment(Qt::AlignRight);//设置显示居右
    ui->lineEdit->setStyleSheet("font-size:15px");//设置字体大小为18px
    ui->lineEdit->setText("0");//设置初试文本为0
    start();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::start()
{
    complete=true;
}
void MainWindow::digitBtn(char ch)
{
    QString s = ui->lineEdit->text();
    qDebug()<<s;
    if(!complete)
    {
        if(s=='0'&&ch!='0'){
            ui->lineEdit->setText(""+ch);
       }
       /*else if (s=='0'&&ch=='0')
        {
            ;
        }*/
        else {
            ui->lineEdit->setText(s+ch);
        }

    }

    else
    {
        ui->lineEdit->setText(QString(ch));
        complete = false;
    }
}


void MainWindow::on_pushButton_0_clicked()
{
    digitBtn('0');
}
void MainWindow::on_pushButton_1_clicked()
{
    digitBtn('1');
}
void MainWindow::on_pushButton_2_clicked()
{
    digitBtn('2');
}

void MainWindow::on_pushButton_3_clicked()
{
    digitBtn('3');
}

void MainWindow::on_pushButton_4_clicked()
{
    digitBtn('4');
}

void MainWindow::on_pushButton_5_clicked()
{
    digitBtn('5');
}

void MainWindow::on_pushButton_6_clicked()
{
    digitBtn('6');
}

void MainWindow::on_pushButton_7_clicked()
{
    digitBtn('7');
}

void MainWindow::on_pushButton_8_clicked()
{
    digitBtn('8');
}

void MainWindow::on_pushButton_9_clicked()
{
    digitBtn('9');
}

void MainWindow::on_pushButton_dot_clicked()
{
    //如果是小数点,那么不能以小数点打头
    QString s = ui->lineEdit->text();
    if(!complete)
        ui->lineEdit->setText(s+".");
}

void MainWindow::on_delepushButton_clicked()
{
    QString s = ui->lineEdit->text();
    s=s.mid(0,s.size()-1);
    ui->lineEdit->setText(s);
}

void MainWindow::on_pushButton_add_clicked()
{
    QString s = ui->lineEdit->text();
    QByteArray qByteArray = s.toUtf8();
    char* cStr = qByteArray.data();
    if((cStr[s.length()-1]>='0'&&cStr[s.length()-1]<='9')||cStr[s.length()-1]==')')
        ui->lineEdit->setText(s+"+");
}

void MainWindow::on_pushButton_less_clicked()
{
    QString s = ui->lineEdit->text();
    QByteArray qByteArray = s.toUtf8();
    char* cStr = qByteArray.data();
    if((cStr[s.length()-1]>='0'&&cStr[s.length()-1]<='9')||cStr[s.length()-1]==')')
        ui->lineEdit->setText(s+"-");
}

void MainWindow::on_pushButton_mul_clicked()
{
    QString s = ui->lineEdit->text();
    QByteArray qByteArray = s.toUtf8();
    char* cStr = qByteArray.data();
    if((cStr[s.length()-1]>='0'&&cStr[s.length()-1]<='9')||cStr[s.length()-1]==')')
        ui->lineEdit->setText(s+"*");
}

void MainWindow::on_pushButton_exc_clicked()
{
    QString s = ui->lineEdit->text();
    QByteArray qByteArray = s.toUtf8();
    char* cStr = qByteArray.data();
    if((cStr[s.length()-1]>='0'&&cStr[s.length()-1]<='9')||cStr[s.length()-1]==')')
        ui->lineEdit->setText(s+"/");
}

void MainWindow::on_pushButton_res_clicked()
{
    QString s = ui->lineEdit->text();
    QByteArray qByteArray = s.toUtf8();
    char* cStr = qByteArray.data();
    if((cStr[s.length()-1]>='0'&&cStr[s.length()-1]<='9')||cStr[s.length()-1]==')')
        ui->lineEdit->setText(s+"%");
}

void MainWindow::on_pushButton_pow_clicked()
{
    QString s = ui->lineEdit->text();
    QByteArray qByteArray = s.toUtf8();
    char* cStr = qByteArray.data();
    if((cStr[s.length()-1]>='0'&&cStr[s.length()-1]<='9')||cStr[s.length()-1]==')')
        ui->lineEdit->setText(s+"^");
}

void MainWindow::on_pushButton_left_clicked()
{
    QString s = ui->lineEdit->text();
    QByteArray qByteArray = s.toUtf8();
    char* cStr = qByteArray.data();
    if(cStr[s.length()-1]=='+'||cStr[s.length()-1]=='-'||cStr[s.length()-1]=='*'||cStr[s.length()-1]=='/'||cStr[s.length()-1]=='%'||cStr[s.length()-1]=='^')
        ui->lineEdit->setText(s+"(");
    else if (s==""||(s.length()==1&&cStr[0]=='0')) {
         ui->lineEdit->setText("(");
    }
}

void MainWindow::on_pushButton_right_clicked()
{
    QString s = ui->lineEdit->text();
    QByteArray qByteArray = s.toUtf8();
    char* cStr = qByteArray.data();
    if(cStr[s.length()-1]>='0'&&cStr[s.length()-1]<='9')
        ui->lineEdit->setText(s+")");
}
void MainWindow::evaluation()
{
    QString temp=ui->lineEdit->text();
    double  outcome;
    outcome=result(temp.toStdString());
    ui->lineEdit->setText(QString::number(outcome ));
}

void MainWindow::on_pushButton_equal_clicked()
{
    evaluation();
    //start();
}

void MainWindow::on_pushButton_clicked()
{
    start();
    ui->lineEdit->setText("");
}
