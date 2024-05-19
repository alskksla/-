/********************************************************************************
** Form generated from reading UI file 'configwidget2.ui'
**
** Created by: Qt User Interface Compiler version 6.7.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIGWIDGET2_H
#define UI_CONFIGWIDGET2_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QFrame>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_configwidget2
{
public:
    QVBoxLayout *verticalLayout_3;
    QStackedWidget *stackedWidget;
    QWidget *page;
    QVBoxLayout *verticalLayout_4;
    QFrame *frame;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *id;
    QHBoxLayout *horizontalLayout_3;
    QLabel *label_2;
    QLineEdit *passward;
    QSplitter *splitter_3;
    QPushButton *loginButton;
    QPushButton *regitButton;
    QWidget *page_2;
    QVBoxLayout *verticalLayout_5;
    QFrame *frame_2;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *label_3;
    QLineEdit *regitid;
    QHBoxLayout *horizontalLayout_5;
    QLabel *label_4;
    QLineEdit *regitpassward;
    QHBoxLayout *horizontalLayout_6;
    QLabel *label_5;
    QLineEdit *aginpassward;
    QHBoxLayout *horizontalLayout_7;
    QPushButton *regit;
    QPushButton *tologin;

    void setupUi(QWidget *configwidget2)
    {
        if (configwidget2->objectName().isEmpty())
            configwidget2->setObjectName("configwidget2");
        configwidget2->resize(495, 215);
        configwidget2->setStyleSheet(QString::fromUtf8("background-color: rgb(255, 227, 143);\n"
"background-color: rgb(255, 245, 211);"));
        verticalLayout_3 = new QVBoxLayout(configwidget2);
        verticalLayout_3->setObjectName("verticalLayout_3");
        stackedWidget = new QStackedWidget(configwidget2);
        stackedWidget->setObjectName("stackedWidget");
        page = new QWidget();
        page->setObjectName("page");
        verticalLayout_4 = new QVBoxLayout(page);
        verticalLayout_4->setObjectName("verticalLayout_4");
        frame = new QFrame(page);
        frame->setObjectName("frame");
        frame->setStyleSheet(QString::fromUtf8(""));
        frame->setFrameShape(QFrame::StyledPanel);
        frame->setFrameShadow(QFrame::Raised);
        verticalLayout = new QVBoxLayout(frame);
        verticalLayout->setObjectName("verticalLayout");
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setObjectName("horizontalLayout_2");
        label = new QLabel(frame);
        label->setObjectName("label");
        label->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\215\216\346\226\207\350\241\214\346\245\267\";"));

        horizontalLayout_2->addWidget(label);

        id = new QLineEdit(frame);
        id->setObjectName("id");

        horizontalLayout_2->addWidget(id);


        verticalLayout->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setObjectName("horizontalLayout_3");
        label_2 = new QLabel(frame);
        label_2->setObjectName("label_2");
        label_2->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\215\216\346\226\207\350\241\214\346\245\267\";"));

        horizontalLayout_3->addWidget(label_2);

        passward = new QLineEdit(frame);
        passward->setObjectName("passward");

        horizontalLayout_3->addWidget(passward);


        verticalLayout->addLayout(horizontalLayout_3);

        splitter_3 = new QSplitter(frame);
        splitter_3->setObjectName("splitter_3");
        splitter_3->setOrientation(Qt::Horizontal);
        loginButton = new QPushButton(splitter_3);
        loginButton->setObjectName("loginButton");
        splitter_3->addWidget(loginButton);
        regitButton = new QPushButton(splitter_3);
        regitButton->setObjectName("regitButton");
        splitter_3->addWidget(regitButton);

        verticalLayout->addWidget(splitter_3);


        verticalLayout_4->addWidget(frame);

        stackedWidget->addWidget(page);
        page_2 = new QWidget();
        page_2->setObjectName("page_2");
        verticalLayout_5 = new QVBoxLayout(page_2);
        verticalLayout_5->setObjectName("verticalLayout_5");
        frame_2 = new QFrame(page_2);
        frame_2->setObjectName("frame_2");
        frame_2->setFrameShape(QFrame::StyledPanel);
        frame_2->setFrameShadow(QFrame::Raised);
        verticalLayout_2 = new QVBoxLayout(frame_2);
        verticalLayout_2->setObjectName("verticalLayout_2");
        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setObjectName("horizontalLayout_4");
        label_3 = new QLabel(frame_2);
        label_3->setObjectName("label_3");
        label_3->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\215\216\346\226\207\350\241\214\346\245\267\";"));

        horizontalLayout_4->addWidget(label_3, 0, Qt::AlignHCenter);

        regitid = new QLineEdit(frame_2);
        regitid->setObjectName("regitid");
        regitid->setMinimumSize(QSize(200, 30));
        regitid->setMaximumSize(QSize(200, 30));

        horizontalLayout_4->addWidget(regitid);


        verticalLayout_2->addLayout(horizontalLayout_4);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setObjectName("horizontalLayout_5");
        label_4 = new QLabel(frame_2);
        label_4->setObjectName("label_4");
        label_4->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\215\216\346\226\207\350\241\214\346\245\267\";"));

        horizontalLayout_5->addWidget(label_4, 0, Qt::AlignHCenter);

        regitpassward = new QLineEdit(frame_2);
        regitpassward->setObjectName("regitpassward");
        regitpassward->setMinimumSize(QSize(200, 30));
        regitpassward->setMaximumSize(QSize(200, 30));

        horizontalLayout_5->addWidget(regitpassward);


        verticalLayout_2->addLayout(horizontalLayout_5);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setObjectName("horizontalLayout_6");
        label_5 = new QLabel(frame_2);
        label_5->setObjectName("label_5");
        label_5->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\215\216\346\226\207\350\241\214\346\245\267\";"));

        horizontalLayout_6->addWidget(label_5, 0, Qt::AlignHCenter);

        aginpassward = new QLineEdit(frame_2);
        aginpassward->setObjectName("aginpassward");
        aginpassward->setMinimumSize(QSize(200, 30));
        aginpassward->setMaximumSize(QSize(200, 30));

        horizontalLayout_6->addWidget(aginpassward);


        verticalLayout_2->addLayout(horizontalLayout_6);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setObjectName("horizontalLayout_7");
        regit = new QPushButton(frame_2);
        regit->setObjectName("regit");
        regit->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\215\216\346\226\207\350\241\214\346\245\267\";"));

        horizontalLayout_7->addWidget(regit);

        tologin = new QPushButton(frame_2);
        tologin->setObjectName("tologin");
        tologin->setStyleSheet(QString::fromUtf8("font: 9pt \"\345\215\216\346\226\207\350\241\214\346\245\267\";"));

        horizontalLayout_7->addWidget(tologin);


        verticalLayout_2->addLayout(horizontalLayout_7);


        verticalLayout_5->addWidget(frame_2);

        stackedWidget->addWidget(page_2);

        verticalLayout_3->addWidget(stackedWidget);


        retranslateUi(configwidget2);

        stackedWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(configwidget2);
    } // setupUi

    void retranslateUi(QWidget *configwidget2)
    {
        configwidget2->setWindowTitle(QCoreApplication::translate("configwidget2", "Form", nullptr));
        label->setText(QCoreApplication::translate("configwidget2", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_2->setText(QCoreApplication::translate("configwidget2", "\345\257\206\347\240\201", nullptr));
        loginButton->setText(QCoreApplication::translate("configwidget2", "\347\231\273\345\275\225", nullptr));
        regitButton->setText(QCoreApplication::translate("configwidget2", "\346\263\250\345\206\214", nullptr));
        label_3->setText(QCoreApplication::translate("configwidget2", "\347\224\250\346\210\267\345\220\215", nullptr));
        label_4->setText(QCoreApplication::translate("configwidget2", "\345\257\206\347\240\201", nullptr));
        label_5->setText(QCoreApplication::translate("configwidget2", "\350\257\267\345\206\215\346\254\241\350\276\223\345\205\245\345\257\206\347\240\201", nullptr));
        regit->setText(QCoreApplication::translate("configwidget2", "\346\263\250\345\206\214", nullptr));
        tologin->setText(QCoreApplication::translate("configwidget2", "\345\216\273\347\231\273\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class configwidget2: public Ui_configwidget2 {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIGWIDGET2_H
