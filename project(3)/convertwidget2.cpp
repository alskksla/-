#include "convertwidget2.h"
#include "mysqlwidget.h"
#include "ui_convertwidget2.h"

#include <QAxObject>
#include <qfiledialog.h>
#include <qmessagebox.h>
#include <ole2.h>
convertwidget2::convertwidget2(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::convertwidget2)
{
    ui->setupUi(this);
}

convertwidget2::~convertwidget2()
{
    delete ui;
}

void convertwidget2::on_btnClicked()
{
    ui->stackedWidget->setHidden(false);
}

void convertwidget2::on_OpenPath()
{
    m_openFilePath = QFileDialog::getOpenFileName(nullptr, QObject::tr("打开文件"),
                                                  "", QObject::tr("All Files (*.docx)"));
}

void convertwidget2::on_SavePath()
{
    m_saveFilePath = QFileDialog::getSaveFileName(nullptr, QObject::tr("打开文件"),
                                                  "", QObject::tr("All Files (*.pdf)"));
}

void convertwidget2::on_Start()
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

void convertwidget2::on_threadfinish()
{
    count++;
    count*100/4;
    qDebug()<<"on_threadfinish";
    addLogText(QString("%1%2").arg("进度：%").arg(count*100/4));
}

void convertwidget2::addLogText(QString text, bool addtime)
{
    QString time = QTime::currentTime().toString();
    QString str;
    if(addtime)
        str = QString("%1%2%3").arg(time).arg(": ").arg(text);
    else
        str = text;

    m_LogText->append(str);
}

void convertwidget2::on_exit()
{
    emit exit();
}

void convertwidget2::on_clear()
{
    ui->uID->clear();
    ui->password->clear();
    ui->aginpassword->clear();
    ui->nepassword->clear();
    m_LogText->clear();
}



void convertwidget2::on_deleteUser_clicked()
{
    if(ui->uID->text().isEmpty()||ui->password->text().isEmpty()||ui->aginpassword->text().isEmpty())
    {
        QMessageBox::warning(this,tr("提示"),tr("<span style='color: rgb(0, 0, 0); font-size: 20px;'>账号密码不能为空!</span>"),QMessageBox::Yes);
        return;
    }else if(ui->password->text()!=ui->aginpassword->text())
    {
        QMessageBox::warning(this,tr("提示"),tr("<span style='color: rgb(0, 0, 0); font-size: 20px;'>密码不一致!</span>"),QMessageBox::Yes);
        return;
    }
    QString username =ui->uID->text();
    QString password = ui->password->text();
    MySQLWidget m_mysql;
    if(m_mysql.loginUser(username,password))
    {
        if(m_mysql.deleteUser(username))
        {
            ui->stackedWidget->setHidden(true);
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


void convertwidget2::on_changePassward_clicked()
{
    if(ui->uID->text().isEmpty()||ui->password->text().isEmpty()||ui->aginpassword->text().isEmpty())
    {
        QMessageBox::warning(this,tr("提示"),tr("<span style='color: rgb(0, 0, 0); font-size: 20px;'>账号密码不能为空!</span>"),QMessageBox::Yes);
        return;
    }else if(ui->password->text()!=ui->aginpassword->text())
    {
        QMessageBox::warning(this,tr("提示"),tr("<span style='color: rgb(0, 0, 0); font-size: 20px;'>密码不一致!</span>"),QMessageBox::Yes);
        return;
    }

    QString username = ui->uID->text();
    QString password = ui->password->text();
    QString newpassword = ui->nepassword->text();

    MySQLWidget m_mysql;

    if(m_mysql.loginUser(username,password))
    {

        if(m_mysql.chanePasswd(username,newpassword))
        {
            ui->stackedWidget->setHidden(true);
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


void convertwidget2::on_pushButton_clicked()
{
    m_openFilePath = QFileDialog::getOpenFileName(nullptr, QObject::tr("打开文件"),
                                                  "", QObject::tr("All Files (*.docx)"));
}


void convertwidget2::on_pushButton_2_clicked()
{
    m_saveFilePath = QFileDialog::getSaveFileName(nullptr, QObject::tr("打开文件"),
                                                  "", QObject::tr("All Files (*.pdf)"));
}


void convertwidget2::on_pushButton_3_clicked()
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


void convertwidget2::on_pushButton_4_clicked()
{
    emit exit();
}


void convertwidget2::on_pushButton_5_clicked()
{
    ui->stackedWidget->setHidden(false);
}

