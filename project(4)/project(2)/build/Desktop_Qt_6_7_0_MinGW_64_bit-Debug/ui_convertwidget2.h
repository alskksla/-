/********************************************************************************
** Form generated from reading UI file 'convertwidget2.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONVERTWIDGET2_H
#define UI_CONVERTWIDGET2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_convertwidget2
{
public:
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_6;
    QPushButton *pushButton;
    QPushButton *pushButton_2;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QPushButton *pushButton_5;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_2;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QLineEdit *uID;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label_2;
    QLineEdit *password;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_3;
    QLineEdit *aginpassword;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_4;
    QLineEdit *nepassword;
    QHBoxLayout *horizontalLayout_5;
    QPushButton *deleteUser;
    QPushButton *changePassward;
    QWidget *page_2;

    void setupUi(QWidget *convertwidget2)
    {
        if (convertwidget2->objectName().isEmpty())
            convertwidget2->setObjectName("convertwidget2");
        convertwidget2->resize(529, 374);
        convertwidget2->setStyleSheet(QString::fromUtf8(" background-color: rgb(255, 245, 211);"));
        verticalLayout_3 = new QVBoxLayout(convertwidget2);
        verticalLayout_3->setObjectName("verticalLayout_3");
        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        pushButton = new QPushButton(convertwidget2);
        pushButton->setObjectName("pushButton");

        horizontalLayout_6->addWidget(pushButton);

        pushButton_2 = new QPushButton(convertwidget2);
        pushButton_2->setObjectName("pushButton_2");

        horizontalLayout_6->addWidget(pushButton_2);

        pushButton_3 = new QPushButton(convertwidget2);
        pushButton_3->setObjectName("pushButton_3");

        horizontalLayout_6->addWidget(pushButton_3);

        pushButton_4 = new QPushButton(convertwidget2);
        pushButton_4->setObjectName("pushButton_4");

        horizontalLayout_6->addWidget(pushButton_4);

        pushButton_5 = new QPushButton(convertwidget2);
        pushButton_5->setObjectName("pushButton_5");

        horizontalLayout_6->addWidget(pushButton_5);


        verticalLayout_3->addLayout(horizontalLayout_6);

        stackedWidget = new QStackedWidget(convertwidget2);
        stackedWidget->setObjectName("stackedWidget");
        page = new QWidget();
        page->setObjectName("page");
        verticalLayout_2 = new QVBoxLayout(page);
        verticalLayout_2->setObjectName("verticalLayout_2");
        frame = new QFrame(page);
        frame->setObjectName("frame");
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName("horizontalLayout");
        label = new QLabel(frame);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\215\216\346\226\207\350\241\214\346\245\267\";"));

        horizontalLayout->addWidget(label, 0, Qt::AlignHCenter);

        uID = new QLineEdit(frame);
        uID->setObjectName("uID");
        uID->setMinimumSize(QSize(200, 30));
        uID->setMaximumSize(QSize(200, 30));

        horizontalLayout->addWidget(uID);


        verticalLayout->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\215\216\346\226\207\350\241\214\346\245\267\";"));

        horizontalLayout_2->addWidget(label_2, 0, Qt::AlignHCenter);

        password = new QLineEdit(frame);
        password->setObjectName("password");
        password->setMinimumSize(QSize(200, 30));
        password->setMaximumSize(QSize(200, 30));

        horizontalLayout_2->addWidget(password);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_3 = new QLabel(frame);
        label_3->setObjectName("label_3");
        label_3->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\215\216\346\226\207\350\241\214\346\245\267\";"));

        horizontalLayout_3->addWidget(label_3, 0, Qt::AlignHCenter);

        aginpassword = new QLineEdit(frame);
        aginpassword->setObjectName("aginpassword");
        aginpassword->setMinimumSize(QSize(200, 30));
        aginpassword->setMaximumSize(QSize(200, 20));

        horizontalLayout_3->addWidget(aginpassword);


        verticalLayout->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_4 = new QLabel(frame);
        label_4->setObjectName("label_4");
        label_4->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\215\216\346\226\207\350\241\214\346\245\267\";"));

        horizontalLayout_4->addWidget(label_4, 0, Qt::AlignHCenter);

        nepassword = new QLineEdit(frame);
        nepassword->setObjectName("nepassword");
        nepassword->setMinimumSize(QSize(200, 30));
        nepassword->setMaximumSize(QSize(200, 30));

        horizontalLayout_4->addWidget(nepassword);


        verticalLayout->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        deleteUser = new QPushButton(frame);
        deleteUser->setObjectName("deleteUser");

        horizontalLayout_5->addWidget(deleteUser);

        changePassward = new QPushButton(frame);
        changePassward->setObjectName("changePassward");

        horizontalLayout_5->addWidget(changePassward);


        verticalLayout->addLayout(horizontalLayout_5);


        verticalLayout_2->addWidget(frame);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        stackedWidget->addWidget(page_2);

        verticalLayout_3->addWidget(stackedWidget);


        retranslateUi(convertwidget2);

        QMetaObject::connectSlotsByName(convertwidget2);
    } // setupUi

    void retranslateUi(QWidget *convertwidget2)
    {
        convertwidget2->setWindowTitle(QCoreApplication::translate("convertwidget2", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("convertwidget2", "\351\200\211\346\213\251work\346\226\207\346\241\243", nullptr));
        pushButton_2->setText(QCoreApplication::translate("convertwidget2", "\344\277\235\345\255\230\350\267\257\345\276\204", nullptr));
        pushButton_3->setText(QCoreApplication::translate("convertwidget2", "\345\274\200\345\247\213\350\275\254\346\215\242", nullptr));
        pushButton_4->setText(QCoreApplication::translate("convertwidget2", "\351\200\200\345\207\272\347\231\273\345\275\225", nullptr));
        pushButton_5->setText(QCoreApplication::translate("convertwidget2", "\350\256\276\347\275\256", nullptr));
        label->setText(QCoreApplication::translate("convertwidget2", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_2->setText(QCoreApplication::translate("convertwidget2", "\345\257\206\347\240\201", nullptr));
        label_3->setText(QCoreApplication::translate("convertwidget2", "\345\206\215\346\254\241\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        label_4->setText(QCoreApplication::translate("convertwidget2", "\346\226\260\345\257\206\347\240\201", nullptr));
        deleteUser->setText(QCoreApplication::translate("convertwidget2", "\345\210\240\351\231\244\347\224\250\346\210\267 ", nullptr));
        changePassward->setText(QCoreApplication::translate("convertwidget2", "\344\277\256\346\224\271\345\257\206\347\240\201", nullptr));
    } // retranslateUi

};

namespace Ui {
    class convertwidget2: public Ui_convertwidget2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONVERTWIDGET2_H
