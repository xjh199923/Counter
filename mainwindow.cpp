#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QDesktopWidget>
#include "calculate.h"
#include "String"
#include <math.h>
#include<QTimer>
#include<QDateTime>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    QDesktopWidget * desktop = QApplication::desktop();
    move((desktop->width() - this->width())/2,(desktop->height() - this->height())/2);
    ui->setupUi(this);
    ui->lineEdit->setEnabled(false);//设置linEdit不可以编辑
    ui->lineEdit->setAlignment(Qt::AlignRight);//设置显示居右
    ui->lineEdit->setText("0");//设置初试文本为0

    QTimer *timer = new QTimer(this);//新建定时器
        connect(timer,SIGNAL(timeout()),this,SLOT(timerUpdate()));//关联定时器计满信号和相应的槽函数
        timer->start(1000);//定时器开始计时，其中1000表示1000ms即1秒

    QStatusBar* bar = ui->statusBar;
        statusLabel1 = new QLabel;
        statusLabel1->setMinimumSize(200,15);
        statusLabel1->setFrameShape(QFrame::Box);
        statusLabel1->setFrameShadow(QFrame::Sunken);

        statusLabel2 = new QLabel;
        statusLabel2->setMinimumSize(200,15);
        statusLabel2->setFrameShape(QFrame::Box);
        statusLabel2->setFrameShadow(QFrame::Sunken);

        bar->addWidget(statusLabel1);
        bar->addWidget(statusLabel2);

        statusLabel1->setText(tr("made by 向君鸿,杨林翰"));
        statusLabel2->setText(tr("0000-00-00 00:00::00 星期 "));
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
    if(!complete)
    {
        if(s=='0'&&ch!='0'){
            ui->lineEdit->setText(""+ch);
       }
        else if (s=='sin(') {
            ui->lineEdit->setText("sin("+ch);
        }
        else if (s=='cos(') {
            ui->lineEdit->setText("cos("+ch);
        }
        else if (s=='tan(') {
            ui->lineEdit->setText("tan("+ch);
        }
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
    //isresult();
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
     //isresult();
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
   if(s=="0")
   {
       ui->lineEdit->setText(s);
   }
   else {
       s=s.mid(0,s.size()-1);
       ui->lineEdit->setText(s);
   }
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
    QString tmp;
    QString count=temp.mid(4,temp.length()-1);
    if(temp.mid(0,3)=="sin")
    {
        double  outcome;
        outcome=result(count.toStdString());
        outcome=sin(outcome);
        tmp=QString::number(outcome);
        ui->lineEdit->setText(temp+")="+tmp);
    }
   else if(temp.mid(0,3)=="cos")
    {
        double  outcome;
        outcome=result(count.toStdString());
        outcome=cos(outcome);
        tmp=QString::number(outcome);
        ui->lineEdit->setText(temp+")="+tmp);

    }
    else if(temp.mid(0,3)=="tan")
     {
         double  outcome;
         outcome=result(count.toStdString());
         outcome=tan(outcome);
         tmp=QString::number(outcome);
         ui->lineEdit->setText(temp+")="+tmp);
     }
    else {
        double  outcome;
        outcome=result(temp.toStdString());
        ui->lineEdit->setText(QString::number(outcome ));
    }

}

void MainWindow::on_pushButton_equal_clicked()
{
    evaluation();
    start();
}

void MainWindow::on_pushButton_clicked()
{
    start();
    ui->lineEdit->setText("0");
}
//时间更新槽函数
void MainWindow::timerUpdate()
{
    QDateTime time = QDateTime::currentDateTime();
    QString str = time.toString("yyyy-MM-dd hh:mm:ss dddd");
    statusLabel2->setText(str);
}

void MainWindow::on_pushButton_sin_clicked()
{
    digitBtn('sin');
    ui->lineEdit->setText("sin(");

}

void MainWindow::on_pushButton_cos_clicked()
{
    digitBtn('cos');
    ui->lineEdit->setText("cos(");
}

void MainWindow::on_pushButton_tan_clicked()
{
    digitBtn('tan');
    ui->lineEdit->setText("tan(");
}
