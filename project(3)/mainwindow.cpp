#include "mainwindow.h"
#include <QHBoxLayout>
#include <QScreen>
#include <QApplication>
#include "configwidget.h"
#include "configwidget2.h"
#include "convertwidget2.h"
#include "mysqlwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
        MySQLWidget sql;
        sql.createUserTable();
        configwidget2* configwidget ;
        convertwidget2 *convertWidget;

        configwidget = new configwidget2(this);
        convertWidget = new convertwidget2(this);

        m_stackWidget =new QStackedWidget;
        m_stackWidget->addWidget(configwidget);
        m_stackWidget->addWidget(convertWidget);

       QFrame* centralWidget = new QFrame();


        QHBoxLayout* mainLayout = new QHBoxLayout;
        mainLayout->addWidget(m_stackWidget);
        centralWidget->setLayout(mainLayout);
        this->setCentralWidget(centralWidget);
        m_stackWidget->setCurrentIndex(0);

      //  setFixedSize(QSize(400, 300));

      // setMinimumSize(0, 0);
      // setMaximumSize(QWIDGETSIZE_MAX, QWIDGETSIZE_MAX);

        // 设置窗口的最小大小为800x600像素
        setMinimumSize(QSize(400, 300));

        // 设置窗口的最大大小为800x600像素
        setMaximumSize(QSize(400, 300));

    connect(configwidget,SIGNAL(sendlogion()),this,SLOT(on_logion()));
    connect(convertWidget,SIGNAL(exit()),this,SLOT(on_exit()));
    connect(this,SIGNAL(sendClear()),convertWidget,SLOT(on_clear()));
}

MainWindow::~MainWindow()
{
}

 void MainWindow::setWindownFixedSize(int w,int h)
 {
    setFixedSize(QSize(w, h));
 }


 void MainWindow::on_exit()
 {
     // 设置窗口的最小大小为800x600像素
     setMinimumSize(QSize(400, 300));

     // 设置窗口的最大大小为800x600像素
     setMaximumSize(QSize(400, 300));
     m_stackWidget->setCurrentIndex(0);
 }


 void MainWindow::on_logion()
 {
     qDebug()<<"on_logion";
         m_stackWidget->setCurrentIndex(1);
        // emit sendClear();
         QRect screenGeometry = QApplication::primaryScreen()->geometry();
         setMinimumSize(QSize(screenGeometry.width()/2, screenGeometry.height()/2));

       setMaximumSize(QSize(QWIDGETSIZE_MAX, QWIDGETSIZE_MAX));
 }
