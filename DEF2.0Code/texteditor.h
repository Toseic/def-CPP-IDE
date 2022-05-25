#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <string.h>
#include <QWidget>
#include <QWidget>
#include <QDebug>
#include <QWheelEvent>
#include <Qsci/qsciscintilla.h>
#include <Qsci/qscilexer.h>
#include <Qsci/qscilexercpp.h>
#include <Qsci/qsciapis.h>
#include <Qsci/qscistyle.h>

class Texteditor : public QsciScintilla
{
    Q_OBJECT
public:
    explicit Texteditor(QWidget *parent=nullptr);
    ~Texteditor();
    QsciScintilla * qsci;
    QsciLexerCPP * textlexer;
    QsciAPIs * apis;
    void init_editor();
    void setapis();
signals:

public slots:
    void complete_brackets();
};

#endif // TEXTEDITOR_H
