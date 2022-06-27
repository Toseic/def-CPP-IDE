#include "settings.h"
#include "ui_settings.h"
#include "mainwindow.h"
#include <string.h>

QString themes[] = {
    "MaterialDark",
    "AMOLED",
    "ConsoleStyle",
    "ElegantDark",
    "Light",
    "MacOS",
    "ManjaroMix",
    "MaterialDark",
    "NeonButtons",
    "Ubuntu"
};

Settings::Settings(MainWindow *set, QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Settings)
{
    ui->setupUi(this);
    QString setting_theme;
    set_ori = set;

    // theme setting
    int theme_num = sizeof(themes) / sizeof(themes[0]);
    QStringList themestrList;
    for (int i=0;i<theme_num;++i) {
        themestrList << themes[i];
    }
    QStringList boolstrList;
    boolstrList << "true" << "false";
    this -> setWindowTitle("设置");

    ui->compilerEdit->setText(set_ori->compiler);
    ui->commandlineArgEdit->setText(set_ori->commandline_arg);
    ui->comboBox_theme->addItems(themestrList);
    ui->comboBox_theme->setCurrentText(set_ori->set_store->theme);
    ui->comboBox_autotab->addItems(boolstrList);

    ui->comboBox_autotab->setCurrentText(settingStore::booltostr(set_ori->set_store->auto_tab));
    ui->comboBox_referline->addItems(boolstrList);
    ui->comboBox_referline->setCurrentText(settingStore::booltostr(set_ori->set_store->refer_line));
    ui->comboBox_codingtime->addItems(boolstrList);
    ui->comboBox_codingtime->setCurrentText(settingStore::booltostr(set_ori->set_store->coding_time));
    ui->cursor_width->setValue(set_ori->set_store->cursor_width);

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

    set_ori->set_store->set_theme(ui->comboBox_theme->currentText());
    set_ori->set_store->set_cursor_width(ui->cursor_width->value());

    set_ori->set_store->set_auto_tab(ui->comboBox_autotab->currentText());
    set_ori->set_store->set_refer_line(ui->comboBox_referline->currentText());
    set_ori->set_store->set_codingtime(ui->comboBox_codingtime->currentText());

    set_ori->set_store_refresh();
    set_ori->set_store->store2file();
    this->close();
}



void MainWindow::set_theme(QString chosthemepath) {
    QFile qssFile(chosthemepath);
    qssFile.open(QFile::ReadOnly);
    if(qssFile.isOpen())
    {
        qDebug() << "open" << endl;
        QString strFile = qssFile.readAll();
        this->setStyleSheet(strFile);
        qssFile.close();
    }
}

void MainWindow::set_cursor_width(int qint) {
    textEdit->setCaretWidth(qint);
}

// 设置自动缩进
void MainWindow::set_auto_tab(bool qbol) {
    textEdit->setAutoIndent(qbol);
}

// 缩进参考线
void MainWindow::set_referline(bool qbol) {
    textEdit->setIndentationGuides(qbol);
}

// 设置是否打开codingtime
void MainWindow::set_codingtime(bool qbol) {
    if (!qbol) {
        this->codingtime->setText("");
    } else {
        this->start = clock();
        this->codingtime->setText("coding time: 0 m");
    }
}

void MainWindow::set_store_refresh() {
    set_theme(set_store->themePath());
    set_cursor_width(set_store->cursor_width);
    set_auto_tab(set_store->auto_tab);
    set_referline(set_store->refer_line);
    set_codingtime(set_store->coding_time);
}


