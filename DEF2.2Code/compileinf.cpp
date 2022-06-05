#include "compileinf.h"
#include "ui_compileinf.h"

CompileInf::CompileInf(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CompileInf)
{
    ui->setupUi(this);
    this -> setWindowTitle("编译信息");
}

CompileInf::~CompileInf()
{
    delete ui;
}

void CompileInf::setInf(QString inf){
    ui -> textBrowser -> setText(inf);
}
