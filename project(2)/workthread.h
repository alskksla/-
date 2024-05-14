#ifndef WORKTHREAD_H
#define WORKTHREAD_H
#include <QThread>
#include <QtDebug>
#include<QString>
class WorkThread : public QThread
{
        Q_OBJECT
public:
    WorkThread(int i);
    void setOpenPath( QString Path){m_OpenPath = Path;}
    void setSavePath(QString Path){m_SavePath = Path;}

    int  odd;

private:
    QString m_OpenPath;
    QString m_SavePath;
protected:
    void run() ;

};

#endif // WORKTHREAD_H
