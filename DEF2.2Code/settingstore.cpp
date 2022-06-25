#include <QWidget>
#include <QVariant>
#include "settingstore.h"


settingStore::settingStore() {
    theme = "Light";
    cursor_width = 3;
    auto_tab = true;
    refer_line = false;
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


