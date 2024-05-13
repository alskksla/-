#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QStackedWidget>

#include "convertwidget.h"

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
signals:
     void sendClear();
public slots:
        void on_logion();
        void on_exit();

public:
    void setWindownFixedSize(int,int);

private:
    QStackedWidget* m_stackWidget;



};
#endif // MAINWINDOW_H
