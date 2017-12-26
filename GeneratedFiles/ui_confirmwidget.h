/********************************************************************************
** Form generated from reading UI file 'confirmwidget.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONFIRMWIDGET_H
#define UI_CONFIRMWIDGET_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_confirmWidget
{
public:
    QPushButton *btnsave;
    QPushButton *btncancel;

    void setupUi(QWidget *confirmWidget)
    {
        if (confirmWidget->objectName().isEmpty())
            confirmWidget->setObjectName(QStringLiteral("confirmWidget"));
        confirmWidget->resize(202, 28);
        btnsave = new QPushButton(confirmWidget);
        btnsave->setObjectName(QStringLiteral("btnsave"));
        btnsave->setGeometry(QRect(0, 0, 100, 28));
        btnsave->setStyleSheet(QLatin1String("QPushButton{\n"
"	border:none;\n"
"	border-radius:5px;\n"
"	font: 75 10pt \"Arial\";\n"
"	\n"
"	background-color: rgb(255, 170, 0);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	\n"
"	background-color: rgb(255, 85, 0);\n"
"}\n"
""));
        btncancel = new QPushButton(confirmWidget);
        btncancel->setObjectName(QStringLiteral("btncancel"));
        btncancel->setGeometry(QRect(102, 0, 100, 28));
        btncancel->setStyleSheet(QLatin1String("QPushButton{\n"
"	border:none;\n"
"	border-radius:5px;\n"
"	font: 75 10pt \"Arial\";\n"
"	\n"
"	background-color: rgb(255, 170, 0);\n"
"}\n"
"\n"
"QPushButton:pressed{\n"
"	\n"
"	background-color: rgb(255, 85, 0);\n"
"}"));

        retranslateUi(confirmWidget);

        QMetaObject::connectSlotsByName(confirmWidget);
    } // setupUi

    void retranslateUi(QWidget *confirmWidget)
    {
        confirmWidget->setWindowTitle(QApplication::translate("confirmWidget", "confirmWidget", Q_NULLPTR));
        btnsave->setText(QApplication::translate("confirmWidget", "\344\277\235\345\255\230", Q_NULLPTR));
        btncancel->setText(QApplication::translate("confirmWidget", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class confirmWidget: public Ui_confirmWidget {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONFIRMWIDGET_H
