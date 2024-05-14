#include "configwidget.h"
#include <QLayout>
#include <QFrame>
#include<QMessageBox>
#include<QDebug>

ConfigWidget::ConfigWidget(MainWindow *parent)
    :m_parent(parent)
{
    m_mysql = new MySQLWidget;
    QHBoxLayout *hmainlayot = new QHBoxLayout;
    m_stactWidget = new QStackedWidget;
    m_stactWidget->addWidget(createLoggionWidget());
    m_stactWidget->addWidget(createRegisterWidget());
    hmainlayot->addWidget(m_stactWidget);
    m_stactWidget->setCurrentIndex(0);

    setLayout(hmainlayot);

}

QWidget* ConfigWidget::createLoggionWidget()
{
    QFrame *logionwidget =new QFrame;

//    QGridLayout* grp = new QGridLayout;
    QHBoxLayout *hlayot = new QHBoxLayout;
    m_la[0].setText("用户名");
    m_li[0].setFixedSize(200,30);
    hlayot->addWidget(&m_la[0],Qt::AlignLeft);
    hlayot->addWidget(&m_li[0],Qt::AlignLeft);

    QHBoxLayout *hlayot1 = new QHBoxLayout;

    m_la[1].setText("密码");
    m_li[1].setFixedSize(200,30);
    hlayot1->addWidget(&m_la[1],Qt::AlignLeft);
    hlayot1->addWidget(&m_li[1],Qt::AlignLeft);

    QHBoxLayout *hlayot2 = new QHBoxLayout;
    m_btn[0].setText("登录");
    m_btn[1].setText("注册");
    hlayot2->addWidget(&m_btn[0],Qt::AlignLeft);
    hlayot2->addWidget(&m_btn[1],Qt::AlignLeft);

    QVBoxLayout *vlayout = new QVBoxLayout;
    vlayout->addLayout(hlayot);
    vlayout->addLayout(hlayot1);
    vlayout->addLayout(hlayot2);
    logionwidget->setLayout(vlayout);
    connect(&m_btn[0],SIGNAL(clicked()),this,SLOT(on_btn0cClicked()));
    connect(&m_btn[1],SIGNAL(clicked()),this,SLOT(on_btn1cClicked()));
    return logionwidget;
}

void ConfigWidget::on_btn0cClicked()
{
    qDebug()<<"ConfigWidget::on_btn0cClicked()";
    if(m_stactWidget->currentIndex()==0)//登录
    {
        if(m_li[0].text().isEmpty()||m_li[1].text().isEmpty())
        {
             QMessageBox::warning(this,tr("提示"),tr("<span style='color: rgb(0, 0, 0); font-size: 20px;'>用户名和密码不能为空！</span>"),QMessageBox::Yes);
             return;
        }
        QString username,password;
        username = m_li[0].text();
        password = m_li[1].text();
        bool rect = m_mysql->loginUser(username,password);

        if(!rect)
            QMessageBox::warning(this,tr("提示"),tr("<span style='color: rgb(0, 0, 0); font-size: 20px;'>密码错位或用户不存在哈！</span>"),QMessageBox::Yes);
        else
            emit sendlogion();
    }else//注册
    {
        if(m_li[2].text().isEmpty()||m_li[3].text().isEmpty()||m_li[4].text().isEmpty())
        {
         QMessageBox::warning(this,tr("提示"),tr("<span style='color: rgb(0, 0, 0); font-size: 20px;'>用户名和密码不能为空哈！</span>"),QMessageBox::Yes);
         return;
        }

        QString username,password;
        username = m_li[2].text();
        password = m_li[3].text();

        qDebug()<<"username:"<<m_li[2].text();
        bool rect = m_mysql->registerUser(username,password);
        if(rect)
        {
            QMessageBox::warning(this,tr("提示"),tr("<span style='color: rgb(0, 0, 0); font-size: 20px;'>注册成功啦！欢迎使用！</span>"),QMessageBox::Yes);
        }else
            QMessageBox::warning(this,tr("提示"),tr("<span style='color: rgb(0, 0, 0); font-size: 20px;'>注册失败！</span>"),QMessageBox::Yes);
    }

}

void ConfigWidget::on_btn1cClicked()
{
m_stactWidget->setCurrentIndex(!m_stactWidget->currentIndex());
}
void ConfigWidget::on_btn2cClicked()
{

}

QWidget* ConfigWidget::createRegisterWidget()
{
    QFrame *registerwidget =new QFrame;

//    QGridLayout* grp = new QGridLayout;
    QHBoxLayout *hlayot = new QHBoxLayout;
    m_la[2].setText("用户名");
    m_li[2].setFixedSize(200,30);
    hlayot->addWidget(&m_la[2],Qt::AlignLeft);
    hlayot->addWidget(&m_li[2],Qt::AlignLeft);

    QHBoxLayout *hlayot1 = new QHBoxLayout;

    m_la[3].setText("密码");
    m_li[3].setFixedSize(200,30);
    hlayot1->addWidget(&m_la[3],Qt::AlignLeft);
    hlayot1->addWidget(&m_li[3],Qt::AlignLeft);


    QHBoxLayout *hlayot3 = new QHBoxLayout;
    m_la[4].setText("再次输入密码");
    m_li[4].setFixedSize(200,30);
    hlayot3->addWidget(&m_la[4],Qt::AlignLeft);
    hlayot3->addWidget(&m_li[4],Qt::AlignLeft);

    QHBoxLayout *hlayot2 = new QHBoxLayout;
    m_btn[2].setText("注册");
    m_btn[3].setText("去登录");
    hlayot2->addWidget(&m_btn[2],Qt::AlignLeft);
    hlayot2->addWidget(&m_btn[3],Qt::AlignLeft);

    QVBoxLayout *vlayout = new QVBoxLayout;
    vlayout->addLayout(hlayot);
    vlayout->addLayout(hlayot1);
    vlayout->addLayout(hlayot3);
    vlayout->addLayout(hlayot2);

    registerwidget->setLayout(vlayout);
    connect(&m_btn[2],SIGNAL(clicked()),this,SLOT(on_btn0cClicked()));
    connect(&m_btn[3],SIGNAL(clicked()),this,SLOT(on_btn1cClicked()));

    return registerwidget;
}
