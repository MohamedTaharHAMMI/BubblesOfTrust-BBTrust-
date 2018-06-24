/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 5.2.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QCommandLinkButton>
#include <QtWidgets/QFormLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QLabel *labelPicture;
    QVBoxLayout *verticalLayout_2;
    QHBoxLayout *horizontalLayout_2;
    QLabel *label;
    QLineEdit *lineEdit1;
    QLabel *label_2;
    QLineEdit *lineEdit2;
    QLabel *label_3;
    QLineEdit *lineEdit3;
    QSpacerItem *horizontalSpacer;
    QHBoxLayout *horizontalLayout_3;
    QFormLayout *formLayout;
    QLabel *label_4;
    QComboBox *comboBox;
    QLabel *label_5;
    QLineEdit *lineEdit4;
    QLabel *label_6;
    QLineEdit *lineEdit5;
    QLabel *label_7;
    QLineEdit *lineEdit6;
    QLabel *label_8;
    QTextEdit *textEdit;
    QLabel *labTansaction;
    QPushButton *startButton;
    QFormLayout *formLayout_2;
    QLabel *labTo;
    QLabel *labMessage;
    QTextEdit *textEdit2;
    QHBoxLayout *horizontalLayout_4;
    QLineEdit *lineEdit7;
    QCommandLinkButton *sendButton;
    QCommandLinkButton *readButton;
    QSpacerItem *horizontalSpacer_2;
    QMenuBar *menuBar;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(957, 340);
        MainWindow->setMinimumSize(QSize(0, 340));
        MainWindow->setMaximumSize(QSize(16777215, 340));
        QIcon icon;
        icon.addFile(QStringLiteral("../../img/follower.png"), QSize(), QIcon::Normal, QIcon::Off);
        MainWindow->setWindowIcon(icon);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        verticalLayoutWidget = new QWidget(centralWidget);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(10, 10, 937, 439));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        labelPicture = new QLabel(verticalLayoutWidget);
        labelPicture->setObjectName(QStringLiteral("labelPicture"));
        labelPicture->setMinimumSize(QSize(150, 0));
        labelPicture->setMaximumSize(QSize(150, 16777215));

        horizontalLayout->addWidget(labelPicture);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        label = new QLabel(verticalLayoutWidget);
        label->setObjectName(QStringLiteral("label"));
        label->setMaximumSize(QSize(60, 16777215));

        horizontalLayout_2->addWidget(label);

        lineEdit1 = new QLineEdit(verticalLayoutWidget);
        lineEdit1->setObjectName(QStringLiteral("lineEdit1"));
        lineEdit1->setMinimumSize(QSize(75, 0));
        lineEdit1->setMaximumSize(QSize(75, 16777215));

        horizontalLayout_2->addWidget(lineEdit1);

        label_2 = new QLabel(verticalLayoutWidget);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setMaximumSize(QSize(50, 16777215));

        horizontalLayout_2->addWidget(label_2);

        lineEdit2 = new QLineEdit(verticalLayoutWidget);
        lineEdit2->setObjectName(QStringLiteral("lineEdit2"));
        lineEdit2->setMinimumSize(QSize(45, 0));
        lineEdit2->setMaximumSize(QSize(45, 16777215));

        horizontalLayout_2->addWidget(lineEdit2);

        label_3 = new QLabel(verticalLayoutWidget);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setMinimumSize(QSize(125, 0));
        label_3->setMaximumSize(QSize(125, 16777215));

        horizontalLayout_2->addWidget(label_3);

        lineEdit3 = new QLineEdit(verticalLayoutWidget);
        lineEdit3->setObjectName(QStringLiteral("lineEdit3"));
        lineEdit3->setMinimumSize(QSize(295, 0));
        lineEdit3->setMaximumSize(QSize(275, 16777215));

        horizontalLayout_2->addWidget(lineEdit3);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_2->addItem(horizontalSpacer);


        verticalLayout_2->addLayout(horizontalLayout_2);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QStringLiteral("horizontalLayout_3"));
        formLayout = new QFormLayout();
        formLayout->setSpacing(6);
        formLayout->setObjectName(QStringLiteral("formLayout"));
        formLayout->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout->setContentsMargins(15, -1, 0, -1);
        label_4 = new QLabel(verticalLayoutWidget);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setMinimumSize(QSize(125, 0));
        label_4->setMaximumSize(QSize(125, 16777215));

        formLayout->setWidget(0, QFormLayout::LabelRole, label_4);

        comboBox = new QComboBox(verticalLayoutWidget);
        comboBox->setObjectName(QStringLiteral("comboBox"));
        comboBox->setMaximumSize(QSize(285, 16777215));

        formLayout->setWidget(0, QFormLayout::FieldRole, comboBox);

        label_5 = new QLabel(verticalLayoutWidget);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setMinimumSize(QSize(125, 0));
        label_5->setMaximumSize(QSize(125, 16777215));

        formLayout->setWidget(1, QFormLayout::LabelRole, label_5);

        lineEdit4 = new QLineEdit(verticalLayoutWidget);
        lineEdit4->setObjectName(QStringLiteral("lineEdit4"));
        lineEdit4->setMinimumSize(QSize(60, 0));
        lineEdit4->setMaximumSize(QSize(60, 16777215));
        lineEdit4->setMaxLength(2);

        formLayout->setWidget(1, QFormLayout::FieldRole, lineEdit4);

        label_6 = new QLabel(verticalLayoutWidget);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setMinimumSize(QSize(125, 0));
        label_6->setMaximumSize(QSize(125, 16777215));

        formLayout->setWidget(2, QFormLayout::LabelRole, label_6);

        lineEdit5 = new QLineEdit(verticalLayoutWidget);
        lineEdit5->setObjectName(QStringLiteral("lineEdit5"));
        lineEdit5->setMinimumSize(QSize(60, 0));
        lineEdit5->setMaximumSize(QSize(60, 16777215));
        lineEdit5->setMaxLength(2);

        formLayout->setWidget(2, QFormLayout::FieldRole, lineEdit5);

        label_7 = new QLabel(verticalLayoutWidget);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setMinimumSize(QSize(125, 0));
        label_7->setMaximumSize(QSize(125, 16777215));

        formLayout->setWidget(3, QFormLayout::LabelRole, label_7);

        lineEdit6 = new QLineEdit(verticalLayoutWidget);
        lineEdit6->setObjectName(QStringLiteral("lineEdit6"));
        lineEdit6->setMinimumSize(QSize(285, 0));
        lineEdit6->setMaximumSize(QSize(285, 16777215));
        lineEdit6->setMaxLength(40);

        formLayout->setWidget(3, QFormLayout::FieldRole, lineEdit6);

        label_8 = new QLabel(verticalLayoutWidget);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setMinimumSize(QSize(125, 0));
        label_8->setMaximumSize(QSize(125, 16777215));

        formLayout->setWidget(4, QFormLayout::LabelRole, label_8);

        textEdit = new QTextEdit(verticalLayoutWidget);
        textEdit->setObjectName(QStringLiteral("textEdit"));
        textEdit->setMinimumSize(QSize(60, 95));
        textEdit->setMaximumSize(QSize(285, 60));

        formLayout->setWidget(4, QFormLayout::FieldRole, textEdit);


        horizontalLayout_3->addLayout(formLayout);

        labTansaction = new QLabel(verticalLayoutWidget);
        labTansaction->setObjectName(QStringLiteral("labTansaction"));
        labTansaction->setMinimumSize(QSize(250, 150));
        labTansaction->setMaximumSize(QSize(150, 150));

        horizontalLayout_3->addWidget(labTansaction);


        verticalLayout_2->addLayout(horizontalLayout_3);

        startButton = new QPushButton(verticalLayoutWidget);
        startButton->setObjectName(QStringLiteral("startButton"));

        verticalLayout_2->addWidget(startButton);


        horizontalLayout->addLayout(verticalLayout_2);


        verticalLayout->addLayout(horizontalLayout);

        formLayout_2 = new QFormLayout();
        formLayout_2->setSpacing(6);
        formLayout_2->setObjectName(QStringLiteral("formLayout_2"));
        formLayout_2->setFieldGrowthPolicy(QFormLayout::AllNonFixedFieldsGrow);
        formLayout_2->setContentsMargins(175, -1, 350, -1);
        labTo = new QLabel(verticalLayoutWidget);
        labTo->setObjectName(QStringLiteral("labTo"));
        labTo->setMinimumSize(QSize(125, 0));
        labTo->setMaximumSize(QSize(125, 16777215));

        formLayout_2->setWidget(0, QFormLayout::LabelRole, labTo);

        labMessage = new QLabel(verticalLayoutWidget);
        labMessage->setObjectName(QStringLiteral("labMessage"));
        labMessage->setMinimumSize(QSize(125, 0));
        labMessage->setMaximumSize(QSize(125, 16777215));

        formLayout_2->setWidget(1, QFormLayout::LabelRole, labMessage);

        textEdit2 = new QTextEdit(verticalLayoutWidget);
        textEdit2->setObjectName(QStringLiteral("textEdit2"));
        textEdit2->setMinimumSize(QSize(0, 80));
        textEdit2->setMaximumSize(QSize(285, 60));

        formLayout_2->setWidget(1, QFormLayout::FieldRole, textEdit2);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QStringLiteral("horizontalLayout_4"));
        lineEdit7 = new QLineEdit(verticalLayoutWidget);
        lineEdit7->setObjectName(QStringLiteral("lineEdit7"));
        lineEdit7->setMinimumSize(QSize(60, 0));
        lineEdit7->setMaximumSize(QSize(60, 16777215));
        lineEdit7->setMaxLength(2);

        horizontalLayout_4->addWidget(lineEdit7);

        sendButton = new QCommandLinkButton(verticalLayoutWidget);
        sendButton->setObjectName(QStringLiteral("sendButton"));
        sendButton->setMaximumSize(QSize(80, 30));

        horizontalLayout_4->addWidget(sendButton);

        readButton = new QCommandLinkButton(verticalLayoutWidget);
        readButton->setObjectName(QStringLiteral("readButton"));
        readButton->setMaximumSize(QSize(80, 30));

        horizontalLayout_4->addWidget(readButton);

        horizontalSpacer_2 = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout_4->addItem(horizontalSpacer_2);


        formLayout_2->setLayout(0, QFormLayout::FieldRole, horizontalLayout_4);


        verticalLayout->addLayout(formLayout_2);

        MainWindow->setCentralWidget(centralWidget);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 957, 25));
        MainWindow->setMenuBar(menuBar);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "MainWindow", 0));
        labelPicture->setText(QString());
        label->setText(QApplication::translate("MainWindow", "IP:", 0));
        lineEdit1->setText(QApplication::translate("MainWindow", "127.0.0.1", 0));
        label_2->setText(QApplication::translate("MainWindow", "Port:", 0));
        lineEdit2->setText(QApplication::translate("MainWindow", "8545", 0));
        label_3->setText(QApplication::translate("MainWindow", "Contract Address:", 0));
        lineEdit3->setText(QString());
        label_4->setText(QApplication::translate("MainWindow", "Category:", 0));
        comboBox->clear();
        comboBox->insertItems(0, QStringList()
         << QApplication::translate("MainWindow", "Follower", 0)
         << QApplication::translate("MainWindow", "Master", 0)
        );
        label_5->setText(QApplication::translate("MainWindow", "Group ID:", 0));
        lineEdit4->setText(QString());
        label_6->setText(QApplication::translate("MainWindow", "Node ID:", 0));
        lineEdit5->setText(QString());
        label_7->setText(QApplication::translate("MainWindow", "Public address:", 0));
        lineEdit6->setText(QString());
        label_8->setText(QApplication::translate("MainWindow", "<html><head/><body><p>Ticket:</p></body></html>", 0));
        textEdit->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0));
        textEdit->setPlaceholderText(QApplication::translate("MainWindow", "< If you access to BCTrust for the first time, you need to put your ticket here >", 0));
        labTansaction->setText(QString());
        startButton->setText(QApplication::translate("MainWindow", "Access to BCTrust", 0));
        labTo->setText(QApplication::translate("MainWindow", "<html><head/><body><p>To:</p></body></html>", 0));
        labMessage->setText(QApplication::translate("MainWindow", "<html><head/><body><p>Message:</p></body></html>", 0));
        textEdit2->setHtml(QApplication::translate("MainWindow", "<!DOCTYPE HTML PUBLIC \"-//W3C//DTD HTML 4.0//EN\" \"http://www.w3.org/TR/REC-html40/strict.dtd\">\n"
"<html><head><meta name=\"qrichtext\" content=\"1\" /><style type=\"text/css\">\n"
"p, li { white-space: pre-wrap; }\n"
"</style></head><body style=\" font-family:'Ubuntu'; font-size:11pt; font-weight:400; font-style:normal;\">\n"
"<p style=\"-qt-paragraph-type:empty; margin-top:0px; margin-bottom:0px; margin-left:0px; margin-right:0px; -qt-block-indent:0; text-indent:0px;\"><br /></p></body></html>", 0));
        textEdit2->setPlaceholderText(QString());
        lineEdit7->setText(QString());
        sendButton->setText(QApplication::translate("MainWindow", "Send", 0));
        readButton->setText(QApplication::translate("MainWindow", "Read", 0));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
