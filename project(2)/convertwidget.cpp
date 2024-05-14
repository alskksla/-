#include "convertwidget.h"
#include <QDebug>
#include<QHBoxLayout>
#include <QLayout>
#include <QFrame>
#include<QMessageBox>
#include<QDebug>
#include<QVBoxLayout>
#include <QSplitter>
#include <QTextBrowser>
#include <QFileDialog>
#include <QAxObject>
#include <ole2.h>
#include <QObject>
#include <QTime>
#include "mysqlwidget.h"

ConvertWidget::ConvertWidget(MainWindow *parent)
    :count(0)
    ,m_parent(parent)
{
//         m_mysql =new MySQLWidget;
        m_staticWidget = new QStackedWidget;
         m_LogText = new QTextBrowser;
        m_staticWidget->addWidget(setConfigWidget());
        QHBoxLayout *hmainlayot = new QHBoxLayout;
        QSplitter *slMain = new QSplitter(Qt::Vertical,this);
        slMain->addWidget(createTopWidget());
        slMain->addWidget(createTButtomWidget());
        slMain->setStretchFactor(0, 2);
        slMain->setStretchFactor(1, 8);

//        slMain->addWidget(m_staticWidget);

//        m_staticWidget = new QStackedWidget;
//        m_staticWidget->addWidget(createTopWidget());
//        m_staticWidget->addWidget(createTButtomWidget());

        hmainlayot->addWidget(slMain);
        setLayout(hmainlayot);


//        setFixedSize(1000,500);
}

void ConvertWidget::on_OpenPath()
{
     m_openFilePath = QFileDialog::getOpenFileName(nullptr, QObject::tr("打开文件"),
                                               "", QObject::tr("All Files (*.docx)"));
}

void ConvertWidget::on_SavePath()
{
     m_saveFilePath = QFileDialog::getSaveFileName(nullptr, QObject::tr("打开文件"),
                                               "", QObject::tr("All Files (*.pdf)"));

}
void ConvertWidget::on_Start()
{

        count = 0 ;
        addLogText("开始转换",1);
        addLogText(QString("%1%2").arg("打开文档路径: ").arg(m_openFilePath));
        addLogText(QString("%1%2").arg("保存文档路径: ").arg(m_saveFilePath));

    if(m_saveFilePath.isEmpty()||m_saveFilePath.isEmpty())
    {
    QMessageBox::warning(this,tr("提示"),tr("<span style='color: rgb(0, 0, 0); font-size: 20px;'>打开路径或保存路径为空!</span>"),QMessageBox::Yes);
    return;
    }
       //word转pdf
            HRESULT r = OleInitialize(0);//初始化框架
            QAxObject *pWordApplication = new QAxObject("Word.Application",0);
            QAxObject *pWordDocuments = pWordApplication->querySubObject("Documents");
            QString fileName = m_openFilePath;

            QVariant filename(fileName);
            QVariant confirmconversions(false);
            QVariant readonly(true);
            QVariant addtorecentfiles(false);
            QVariant passworddocument("");
            QVariant passwordtemplate("");
            QVariant revert(false);

            QAxObject *doc = pWordDocuments->querySubObject("Open(const QVariant&, const QVariant&,const QVariant&, "
                                                            "const QVariant&, const QVariant&, "
                                                            "const QVariant&,const QVariant&)",
                                                            filename,
                                                            confirmconversions,
                                                            readonly,
                                                            addtorecentfiles,
                                                            passworddocument,
                                                            passwordtemplate,
                                                            revert);

            int j = 0;
            for (int i=1;i<=7;i+=2)
            {
                workThread[j] = new WorkThread(i); //新建多线程 一共创建四个
                workThread[j]->setOpenPath(m_openFilePath);
                workThread[j]->setSavePath(m_saveFilePath);

                connect(workThread[j], SIGNAL(finished()),this,SLOT(on_threadfinish()));
                j++;
            }
            for(int i =0;i<4;i++)                      //依次启动
            {
                workThread[i]->start();
            }

}

void ConvertWidget::on_threadfinish()
{
    count++;
    count*100/4;
    qDebug()<<"on_threadfinish";
    addLogText(QString("%1%2").arg("进度：%").arg(count*100/4));
}

void ConvertWidget::on_clear()
{
    for(int i=0;i<4;i++)
    m_li[i].clear();

    m_LogText->clear();

}

void ConvertWidget::on_deleteUser()
{
    if(m_li[0].text().isEmpty()||m_li[1].text().isEmpty()||m_li[2].text().isEmpty())
    {
        QMessageBox::warning(this,tr("提示"),tr("<span style='color: rgb(0, 0, 0); font-size: 20px;'>账号密码不能为空!</span>"),QMessageBox::Yes);
        return;
    }else if(m_li[1].text()!=m_li[2].text())
    {
       QMessageBox::warning(this,tr("提示"),tr("<span style='color: rgb(0, 0, 0); font-size: 20px;'>密码不一致!</span>"),QMessageBox::Yes);
       return;
     }
    QString username = m_li[0].text();
    QString password = m_li[1].text();
    MySQLWidget m_mysql;
if(m_mysql.loginUser(username,password))
{
    if(m_mysql.deleteUser(username))
    {
         ConvertWidget::m_staticWidget->setHidden(true);
         emit exit();
    }else
    {
        QMessageBox::warning(this,tr("提示"),tr("<span style='color: rgb(0, 0, 0); font-size: 20px;'>删除失败!</span>"),QMessageBox::Yes);
    }
}else
{

   QMessageBox::warning(this,tr("提示"),tr("<span style='color: rgb(0, 0, 0); font-size: 20px;'>账号不存在或者密码不正确!</span>"),QMessageBox::Yes);
   return;
}
}
void ConvertWidget::on_changpassword()
{
    if(m_li[0].text().isEmpty()||m_li[1].text().isEmpty()||m_li[2].text().isEmpty()||m_li[3].text().isEmpty())
    {
    QMessageBox::warning(this,tr("提示"),tr("<span style='color: rgb(0, 0, 0); font-size: 20px;'>账号密码不能为空!</span>"),QMessageBox::Yes);
    return;
    }else if(m_li[0].text()!=m_li[1].text())
        {
           QMessageBox::warning(this,tr("提示"),tr("<span style='color: rgb(0, 0, 0); font-size: 20px;'>密码不一致!</span>"),QMessageBox::Yes);
           return;
        }

    QString username = m_li[0].text();
    QString password = m_li[1].text();
    QString newpassword = m_li[3].text();

    MySQLWidget m_mysql;

    if(m_mysql.loginUser(username,password))
    {

        if(m_mysql.chanePasswd(username,newpassword))
        {
             ConvertWidget::m_staticWidget->setHidden(true);
             emit exit();
        }else
        {
            QMessageBox::warning(this,tr("提示"),tr("<span style='color: rgb(0, 0, 0); font-size: 20px;'>密码修改失败!</span>"),QMessageBox::Yes);
        }
    }
    else
    {

       QMessageBox::warning(this,tr("提示"),tr("<span style='color: rgb(0, 0, 0); font-size: 20px;'>账号不存在或者密码不正确!</span>"),QMessageBox::Yes);
       return;
    }

}

QWidget * ConvertWidget::setConfigWidget()
 {
      QFrame * SetWidget = new QFrame;


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

      QHBoxLayout *hlayot3= new QHBoxLayout;
      m_la[2].setText("再次输入密码");
      m_li[2].setFixedSize(200,30);
      hlayot3->addWidget(&m_la[2],Qt::AlignLeft);
      hlayot3->addWidget(&m_li[2],Qt::AlignLeft);

      QHBoxLayout *hlayot4= new QHBoxLayout;
      m_la[3].setText("新密码(修改密码填)");
      m_li[3].setFixedSize(200,30);

      hlayot4->addWidget(&m_la[3],Qt::AlignLeft);
      hlayot4->addWidget(&m_li[3],Qt::AlignLeft);


      QHBoxLayout *hlayot2 = new QHBoxLayout;
      m_btn[0].setText("删除用户");
      m_btn[1].setText("修改密码");

      hlayot2->addWidget(&m_btn[0],Qt::AlignLeft);
      hlayot2->addWidget(&m_btn[1],Qt::AlignLeft);

      QVBoxLayout *vlayout = new QVBoxLayout;
      vlayout->addLayout(hlayot);
      vlayout->addLayout(hlayot1);
      vlayout->addLayout(hlayot3);
      vlayout->addLayout(hlayot4);
      vlayout->addLayout(hlayot2);
      SetWidget->setLayout(vlayout);
      SetWidget->setMinimumSize(QSize(400, 300));
      SetWidget->setMaximumSize(QSize(400, 300));
      connect(&m_btn[0],SIGNAL(clicked()),this,SLOT(on_deleteUser()));
      connect(&m_btn[1],SIGNAL(clicked()),this,SLOT(on_changpassword()));
        return SetWidget;
 }

void ConvertWidget::addLogText(QString text,bool addtime)
{
    QString time = QTime::currentTime().toString();
    QString str;
    if(addtime)
     str = QString("%1%2%3").arg(time).arg(": ").arg(text);
    else
     str = text;

    m_LogText->append(str);
}



void ConvertWidget::on_btnClicked()
{
    ConvertWidget::m_staticWidget->setHidden(false);
}

void ConvertWidget::on_exit()
{
    emit exit();
}
QWidget * ConvertWidget::createTopWidget()
{
        QFrame * TopWidget = new QFrame;
        QPushButton * m_OpenPathBnt = new QPushButton;
        m_OpenPathBnt->setText("选择work文档");
        QPushButton * m_savePathBnt = new QPushButton;
        m_savePathBnt->setText("保存路径");
        QPushButton * m_startBnt = new QPushButton;
        m_startBnt->setText("开始转换");
        QPushButton * exitBnt = new QPushButton;
        exitBnt->setText("退出登录");

        QPushButton * m_SetCofigBnt = new QPushButton;
        m_SetCofigBnt->setText("设置");

        QHBoxLayout * hlayout = new QHBoxLayout;
        hlayout->addWidget(m_OpenPathBnt,Qt::AlignTop);
        hlayout->addWidget(m_savePathBnt,Qt::AlignTop);
        hlayout->addWidget(m_startBnt,Qt::AlignTop);
        hlayout->addWidget(m_SetCofigBnt,Qt::AlignTop);
        hlayout->addWidget(exitBnt,Qt::AlignTop);
        QVBoxLayout* vlayout = new QVBoxLayout;
        vlayout->addLayout(hlayout,Qt::AlignTop);

        connect(m_SetCofigBnt,SIGNAL(clicked()),this,SLOT(on_btnClicked()));
        connect(m_OpenPathBnt,SIGNAL(clicked()),this,SLOT(on_OpenPath()));
        connect(m_savePathBnt,SIGNAL(clicked()),this,SLOT(on_SavePath()));
        connect(m_startBnt,SIGNAL(clicked()),this,SLOT(on_Start()));
        connect(exitBnt,SIGNAL(clicked()),this,SLOT(on_exit()));


        TopWidget->setLayout(vlayout);
        return TopWidget;
}

QWidget * ConvertWidget::createTButtomWidget()
{
        QFrame * TopWidget = new QFrame;
        QLabel * logname =new QLabel;
        logname->setText("操作记录(最多保存100条)：");
        QVBoxLayout * hlayout = new QVBoxLayout;


        m_LogText->setFixedSize(1280,600);
//        m_LogText->append("11");
//        m_LogText->append("222");
//        m_LogText->append("333");
//        m_LogText->append("4444");
        hlayout->addWidget(logname);
        hlayout->addWidget(m_LogText);
        TopWidget->setLayout(hlayout);
        return TopWidget;
}
