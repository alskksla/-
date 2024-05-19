#include "configwidget2.h"
#include "ui_configwidget2.h"

#include <QMessageBox>//消息提示框

configwidget2::configwidget2(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::configwidget2)
{
    ui->setupUi(this);
}

configwidget2::~configwidget2()
{
    delete ui;
}

void configwidget2::on_loginButton_clicked()
{
    qDebug()<<"ConfigWidget::on_btn0cClicked()";
    if(ui->stackedWidget->currentIndex()==0)//登录
    {
        if(ui->id->text().isEmpty()||ui->passward->text().isEmpty())
        {
            QMessageBox::warning(this,tr("提示"),tr("<span style='color: rgb(0, 0, 0); font-size: 20px;'>用户名和密码不能为空！</span>"),QMessageBox::Yes);
            return;
        }
        QString username,password;
        username = ui->id->text();
        password = ui->passward->text();
        bool rect = m_mysql->loginUser(username,password);

        if(!rect)
            QMessageBox::warning(this,tr("提示"),tr("<span style='color: rgb(0, 0, 0); font-size: 20px;'>密码错位或用户不存在！</span>"),QMessageBox::Yes);
        else
            emit sendlogion();
    }else//注册
    {
        if(ui->regitid->text().isEmpty()||ui->regitpassward->text().isEmpty()||ui->aginpassward->text().isEmpty())
        {
            QMessageBox::warning(this,tr("提示"),tr("<span style='color: rgb(0, 0, 0); font-size: 20px;'>用户名和密码不能为空！</span>"),QMessageBox::Yes);
            return;
        }
        QString username,password;
        username = ui->regitid->text();
        password = ui->regitpassward->text();

        qDebug()<<"username:"<<ui->regitid->text();
        bool rect = m_mysql->registerUser(username,password);
        if(rect)
        {
            QMessageBox::warning(this,tr("提示"),tr("<span style='color: rgb(0, 0, 0); font-size: 20px;'>注册成功！</span>"),QMessageBox::Yes);
        }else
            QMessageBox::warning(this,tr("提示"),tr("<span style='color: rgb(0, 0, 0); font-size: 20px;'>注册成功！</span>"),QMessageBox::Yes);
    }
}


void configwidget2::on_regitButton_clicked()
{
    ui->stackedWidget->setCurrentIndex(!ui->stackedWidget->currentIndex());
}


void configwidget2::on_tologin_clicked()
{
    ui->stackedWidget->setCurrentIndex(!ui->stackedWidget->currentIndex());
}


void configwidget2::on_regit_clicked()
{
    qDebug()<<"ConfigWidget::on_btn0cClicked()";
    if(ui->stackedWidget->currentIndex()==0)//登录
    {
        if(ui->id->text().isEmpty()||ui->passward->text().isEmpty())
        {
            QMessageBox::warning(this,tr("提示"),tr("<span style='color: rgb(0, 0, 0); font-size: 20px;'>用户名和密码不能为空！</span>"),QMessageBox::Yes);
            return;
        }
        QString username,password;
        username = ui->id->text();
        password = ui->passward->text();
        bool rect = m_mysql->loginUser(username,password);

        if(!rect)
            QMessageBox::warning(this,tr("提示"),tr("<span style='color: rgb(0, 0, 0); font-size: 20px;'>密码错位或用户不存在！</span>"),QMessageBox::Yes);
        else
            emit sendlogion();
    }else//注册
    {
        if(ui->regitid->text().isEmpty()||ui->regitpassward->text().isEmpty()||ui->aginpassward->text().isEmpty())
        {
            QMessageBox::warning(this,tr("提示"),tr("<span style='color: rgb(0, 0, 0); font-size: 20px;'>用户名和密码不能为空！</span>"),QMessageBox::Yes);
            return;
        }
        QString username,password;
        username = ui->regitid->text();
        password = ui->regitpassward->text();

        qDebug()<<"username:"<<ui->regitid->text();
        bool rect = m_mysql->registerUser(username,password);
        if(rect)
        {
            QMessageBox::warning(this,tr("提示"),tr("<span style='color: rgb(0, 0, 0); font-size: 20px;'>注册成功！</span>"),QMessageBox::Yes);
        }else
            QMessageBox::warning(this,tr("提示"),tr("<span style='color: rgb(0, 0, 0); font-size: 20px;'>注册失败！</span>"),QMessageBox::Yes);
    }
}

