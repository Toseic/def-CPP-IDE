/********************************************************************************
** Form generated from reading UI file 'compileinf.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_COMPILEINF_H
#define UI_COMPILEINF_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QTextBrowser>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_CompileInf
{
public:
    QTextBrowser *textBrowser;

    void setupUi(QWidget *CompileInf)
    {
        if (CompileInf->objectName().isEmpty())
            CompileInf->setObjectName(QStringLiteral("CompileInf"));
        CompileInf->resize(450, 250);
        textBrowser = new QTextBrowser(CompileInf);
        textBrowser->setObjectName(QStringLiteral("textBrowser"));
        textBrowser->setGeometry(QRect(10, 10, 431, 231));

        retranslateUi(CompileInf);

        QMetaObject::connectSlotsByName(CompileInf);
    } // setupUi

    void retranslateUi(QWidget *CompileInf)
    {
        CompileInf->setWindowTitle(QApplication::translate("CompileInf", "Form", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class CompileInf: public Ui_CompileInf {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_COMPILEINF_H
