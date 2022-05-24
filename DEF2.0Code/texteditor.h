#ifndef TEXTEDITOR_H
#define TEXTEDITOR_H

#include <QWidget>
#include <QWidget>
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

};

#endif // TEXTEDITOR_H
