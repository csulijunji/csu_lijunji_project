/********************************************************************************
** Form generated from reading UI file 'grabscreen.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_GRABSCREEN_H
#define UI_GRABSCREEN_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_grabScreenClass
{
public:
    QVBoxLayout *verticalLayout;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *btnmin;
    QPushButton *btnclose;
    QPushButton *btnGrabWindow;

    void setupUi(QWidget *grabScreenClass)
    {
        if (grabScreenClass->objectName().isEmpty())
            grabScreenClass->setObjectName(QStringLiteral("grabScreenClass"));
        grabScreenClass->resize(200, 70);
        grabScreenClass->setMaximumSize(QSize(16777215, 16777215));
        verticalLayout = new QVBoxLayout(grabScreenClass);
        verticalLayout->setSpacing(6);
        verticalLayout->setContentsMargins(11, 11, 11, 11);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        btnmin = new QPushButton(grabScreenClass);
        btnmin->setObjectName(QStringLiteral("btnmin"));
        btnmin->setMinimumSize(QSize(24, 24));
        btnmin->setMaximumSize(QSize(24, 24));
        btnmin->setStyleSheet(QLatin1String("QPushButton\n"
"{\n"
"image: url(:/grabScreen/Resources/denglu_suoxiao.png);\n"
"border : 0px;\n"
"\n"
"}\n"
"QPushButton:pressed\n"
"{\n"
"    \n"
"	background-color: rgb(0, 88, 255);\n"
"    border : 0px;\n"
"}"));

        horizontalLayout->addWidget(btnmin);

        btnclose = new QPushButton(grabScreenClass);
        btnclose->setObjectName(QStringLiteral("btnclose"));
        btnclose->setMinimumSize(QSize(24, 24));
        btnclose->setMaximumSize(QSize(24, 24));
        btnclose->setStyleSheet(QLatin1String("QPushButton{\n"
"image: url(:/grabScreen/Resources/denglu_guanbi.png);\n"
"border : 0px;\n"
"\n"
"}\n"
"QPushButton:pressed{\n"
"	background-color: rgb(0, 88, 255);\n"
"    border : 0px;\n"
"}"));

        horizontalLayout->addWidget(btnclose);


        verticalLayout->addLayout(horizontalLayout);

        btnGrabWindow = new QPushButton(grabScreenClass);
        btnGrabWindow->setObjectName(QStringLiteral("btnGrabWindow"));
        btnGrabWindow->setMinimumSize(QSize(0, 25));
        btnGrabWindow->setStyleSheet(QLatin1String("QPushButton{\n"
"	border-radius:6px;\n"
"	background-color: rgb(0, 170, 255);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	\n"
"	background-color: rgb(85, 0, 255);\n"
"}"));

        verticalLayout->addWidget(btnGrabWindow);


        retranslateUi(grabScreenClass);

        QMetaObject::connectSlotsByName(grabScreenClass);
    } // setupUi

    void retranslateUi(QWidget *grabScreenClass)
    {
        grabScreenClass->setWindowTitle(QApplication::translate("grabScreenClass", "grabScreen", Q_NULLPTR));
        btnmin->setText(QString());
        btnclose->setText(QString());
        btnGrabWindow->setText(QApplication::translate("grabScreenClass", "\346\212\223\345\217\226\345\205\250\345\261\217", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class grabScreenClass: public Ui_grabScreenClass {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_GRABSCREEN_H
