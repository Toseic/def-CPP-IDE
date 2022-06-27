#ifndef SETTINGS_H
#define SETTINGS_H

#include <QWidget>
#include"mainwindow.h"

namespace Ui {
class Settings;
}

class Settings : public QWidget
{
    Q_OBJECT

public:
    explicit Settings(MainWindow *set = 0, QWidget *parent = 0);
    MainWindow *set_ori;
    ~Settings();

private slots:
    void on_cancel_clicked();

    void on_confirm_clicked();


private:
    Ui::Settings *ui;
};



#endif // SETTINGS_H
