#include "settings.h"
#include "ui_settings.h"
#include "mainwindow.h"

Settings::Settings(MainWindow *set, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
    set_ori = set;
    this -> setWindowTitle("设置");
    ui->compilerEdit->setText(set_ori->compiler);
    ui->commandlineArgEdit->setText(set_ori->commandline_arg);
}

Settings::~Settings()
{
    delete ui;
}

void Settings::on_cancel_clicked()
{
    this->close();
}


void Settings::on_confirm_clicked()
{
    set_ori->set_compiler(ui->compilerEdit->text());
    set_ori->set_commandline_arg(ui->commandlineArgEdit->text());
    this->close();
}

