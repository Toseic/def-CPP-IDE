/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Settings
{
public:
    QLineEdit *compilerEdit;
    QLineEdit *commandlineArgEdit;
    QLabel *label;
    QLabel *label_2;
    QPushButton *confirm;
    QPushButton *cancel;

    void setupUi(QWidget *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName(QStringLiteral("Settings"));
        Settings->resize(350, 170);
        Settings->setMinimumSize(QSize(350, 170));
        Settings->setMaximumSize(QSize(350, 170));
        compilerEdit = new QLineEdit(Settings);
        compilerEdit->setObjectName(QStringLiteral("compilerEdit"));
        compilerEdit->setGeometry(QRect(150, 20, 181, 31));
        commandlineArgEdit = new QLineEdit(Settings);
        commandlineArgEdit->setObjectName(QStringLiteral("commandlineArgEdit"));
        commandlineArgEdit->setGeometry(QRect(150, 70, 181, 31));
        label = new QLabel(Settings);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 20, 121, 31));
        label_2 = new QLabel(Settings);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 70, 121, 31));
        confirm = new QPushButton(Settings);
        confirm->setObjectName(QStringLiteral("confirm"));
        confirm->setGeometry(QRect(250, 120, 80, 31));
        cancel = new QPushButton(Settings);
        cancel->setObjectName(QStringLiteral("cancel"));
        cancel->setGeometry(QRect(160, 120, 80, 31));

        retranslateUi(Settings);

        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QWidget *Settings)
    {
        Settings->setWindowTitle(QApplication::translate("Settings", "Form", Q_NULLPTR));
        compilerEdit->setText(QString());
        label->setText(QApplication::translate("Settings", "\347\274\226\350\257\221\345\231\250\357\274\232", Q_NULLPTR));
        label_2->setText(QApplication::translate("Settings", "\345\221\275\344\273\244\350\241\214\345\217\202\346\225\260\357\274\232", Q_NULLPTR));
        confirm->setText(QApplication::translate("Settings", "\347\241\256\350\256\244", Q_NULLPTR));
        cancel->setText(QApplication::translate("Settings", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
