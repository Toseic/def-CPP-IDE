/********************************************************************************
** Form generated from reading UI file 'settings.ui'
**
** Created by: Qt User Interface Compiler version 5.6.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SETTINGS_H
#define UI_SETTINGS_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpinBox>
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
    QLabel *label_3;
    QComboBox *comboBox_theme;
    QLabel *label_4;
    QComboBox *comboBox_referline;
    QLabel *label_5;
    QComboBox *comboBox_autotab;
    QLabel *label_6;
    QSpinBox *cursor_width;
    QLabel *label_7;
    QComboBox *comboBox_codingtime;

    void setupUi(QWidget *Settings)
    {
        if (Settings->objectName().isEmpty())
            Settings->setObjectName(QStringLiteral("Settings"));
        Settings->resize(700, 500);
        Settings->setMinimumSize(QSize(700, 500));
        Settings->setMaximumSize(QSize(700, 500));
        compilerEdit = new QLineEdit(Settings);
        compilerEdit->setObjectName(QStringLiteral("compilerEdit"));
        compilerEdit->setGeometry(QRect(140, 20, 161, 31));
        commandlineArgEdit = new QLineEdit(Settings);
        commandlineArgEdit->setObjectName(QStringLiteral("commandlineArgEdit"));
        commandlineArgEdit->setGeometry(QRect(140, 70, 161, 31));
        label = new QLabel(Settings);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(30, 20, 121, 31));
        label->setWordWrap(false);
        label->setMargin(1);
        label_2 = new QLabel(Settings);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(30, 70, 121, 31));
        confirm = new QPushButton(Settings);
        confirm->setObjectName(QStringLiteral("confirm"));
        confirm->setGeometry(QRect(450, 450, 80, 31));
        cancel = new QPushButton(Settings);
        cancel->setObjectName(QStringLiteral("cancel"));
        cancel->setGeometry(QRect(190, 450, 80, 31));
        label_3 = new QLabel(Settings);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(30, 120, 91, 31));
        comboBox_theme = new QComboBox(Settings);
        comboBox_theme->setObjectName(QStringLiteral("comboBox_theme"));
        comboBox_theme->setGeometry(QRect(140, 120, 161, 31));
        label_4 = new QLabel(Settings);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(30, 170, 91, 31));
        comboBox_referline = new QComboBox(Settings);
        comboBox_referline->setObjectName(QStringLiteral("comboBox_referline"));
        comboBox_referline->setGeometry(QRect(140, 170, 161, 31));
        label_5 = new QLabel(Settings);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(30, 220, 101, 31));
        comboBox_autotab = new QComboBox(Settings);
        comboBox_autotab->setObjectName(QStringLiteral("comboBox_autotab"));
        comboBox_autotab->setGeometry(QRect(140, 220, 161, 31));
        label_6 = new QLabel(Settings);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(380, 20, 121, 31));
        cursor_width = new QSpinBox(Settings);
        cursor_width->setObjectName(QStringLiteral("cursor_width"));
        cursor_width->setGeometry(QRect(480, 20, 161, 31));
        label_7 = new QLabel(Settings);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(380, 80, 81, 16));
        comboBox_codingtime = new QComboBox(Settings);
        comboBox_codingtime->setObjectName(QStringLiteral("comboBox_codingtime"));
        comboBox_codingtime->setGeometry(QRect(480, 70, 161, 31));

        retranslateUi(Settings);

        QMetaObject::connectSlotsByName(Settings);
    } // setupUi

    void retranslateUi(QWidget *Settings)
    {
        Settings->setWindowTitle(QApplication::translate("Settings", "Form", 0));
        compilerEdit->setText(QString());
        label->setText(QApplication::translate("Settings", "\347\274\226\350\257\221\345\231\250\357\274\232", 0));
        label_2->setText(QApplication::translate("Settings", "\345\221\275\344\273\244\350\241\214\345\217\202\346\225\260\357\274\232", 0));
        confirm->setText(QApplication::translate("Settings", "\347\241\256\350\256\244", 0));
        cancel->setText(QApplication::translate("Settings", "\345\217\226\346\266\210", 0));
        label_3->setText(QApplication::translate("Settings", "\351\242\234\350\211\262\344\270\273\351\242\230\357\274\232", 0));
        label_4->setText(QApplication::translate("Settings", "\347\274\251\350\277\233\345\217\202\350\200\203\347\272\277", 0));
        label_5->setText(QApplication::translate("Settings", "\350\207\252\345\212\250\347\274\251\350\277\233", 0));
        label_6->setText(QApplication::translate("Settings", "\345\205\211\346\240\207\345\256\275\345\272\246", 0));
        label_7->setText(QApplication::translate("Settings", "open coding time", 0));
    } // retranslateUi

};

namespace Ui {
    class Settings: public Ui_Settings {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SETTINGS_H
