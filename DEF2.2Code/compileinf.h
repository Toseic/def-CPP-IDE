#ifndef COMPILEINF_H
#define COMPILEINF_H

#include <QWidget>

namespace Ui {
class CompileInf;
}

class CompileInf : public QWidget
{
    Q_OBJECT

public:
    explicit CompileInf(QWidget *parent = 0);
    ~CompileInf();
    void setInf(QString);
private:
    Ui::CompileInf *ui;
};

#endif // COMPILEINF_H
