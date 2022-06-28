#include <QWidget>
#include <QVariant>
#include <QSettings>
#include <QDebug>
#include <QDir>
#include "settingstore.h"


settingStore::settingStore() {
    theme = "Light";
    cursor_width = 3;
    auto_tab = true;
    refer_line = false;
    coding_time = true;
    QDir dir;
    QString filePath = dir.currentPath() + "/config.ini";
    qDebug() << filePath << endl;
    QFile file(filePath);
    if (file.exists()) {
        qDebug() << "exists" << endl;
        file2store();
    }

}

void settingStore::file2store() { // 从文件中读取配置
    QSettings *configIniRead = new QSettings("config.ini", QSettings::IniFormat);
    QString theme_result = configIniRead->value("/config/theme").toString();
    int cursor_width_result = configIniRead->value("config/cursor_width").toInt();
    QString auto_tab_result = configIniRead->value("config/auto_tab").toString();
    QString refer_line_result = configIniRead->value("config/refer_line").toString();
    QString coding_time_result = configIniRead->value("config/coding_time").toString();

    theme = theme_result;
    cursor_width = cursor_width_result;
    auto_tab = strtobool(auto_tab_result);
    refer_line = strtobool(refer_line_result);
    coding_time = strtobool(coding_time_result);
}

void settingStore::store2file() {  // 将配置储存到文件
    QSettings *configIniWrite = new QSettings("config.ini", QSettings::IniFormat);
    configIniWrite->setValue("/config/theme", theme);
    configIniWrite->setValue("/config/cursor_width", cursor_width);
    configIniWrite->setValue("/config/auto_tab", auto_tab);
    configIniWrite->setValue("/config/refer_line", refer_line);
    configIniWrite->setValue("/config/coding_time",coding_time);
    qDebug() << "here ini" << endl;
    delete configIniWrite;
}

settingStore::~settingStore() {
    qDebug() << "here quit" << endl;
    store2file();
}

QString settingStore::themePath() {
    themepath = ":/new/prefix1/theme/"+theme+".qss";
    return themepath;
}

QString settingStore::booltostr(bool bol) {
    if (bol) return "true";
    return "false";
}

bool settingStore::strtobool(QString qstr) {
    QVariant onLineTemp = qstr;
    bool qbol = onLineTemp.toBool();
    return qbol;
}

void settingStore::set_theme(QString qst) {
    theme = qst;
}

void settingStore::set_cursor_width(int qint) {
    cursor_width = qint;
}

void settingStore::set_auto_tab(QString qst) {
    auto_tab = strtobool(qst);
}

void settingStore::set_refer_line(QString qst) {
    refer_line = strtobool(qst);
}

void settingStore::set_codingtime(QString qst) {
    coding_time = strtobool(qst);
}

