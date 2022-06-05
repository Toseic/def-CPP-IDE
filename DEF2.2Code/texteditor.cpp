#include "texteditor.h"
#include <string.h>

Texteditor::Texteditor(QWidget *parent): QsciScintilla(parent)
{
    init_editor();
}
void Texteditor::setapis(){
    apis->add(QString("auto"));
    apis->add(QString("break"));
    apis->add(QString("case"));
    apis->add(QString("char"));
    apis->add(QString("const"));
    apis->add(QString("continue"));
    apis->add(QString("default"));
    apis->add(QString("do"));
    apis->add(QString("double"));
    apis->add(QString("else"));
    apis->add(QString("enum"));
    apis->add(QString("extern"));
    apis->add(QString("float"));
    apis->add(QString("for"));
    apis->add(QString("goto"));
    apis->add(QString("if"));
    apis->add(QString("int"));
    apis->add(QString("long"));
    apis->add(QString("regitster"));
    apis->add(QString("return"));
    apis->add(QString("short"));
    apis->add(QString("signed"));
    apis->add(QString("sizeof"));
    apis->add(QString("static"));
    apis->add(QString("struct"));
    apis->add(QString("switch"));
    apis->add(QString("typedef"));
    apis->add(QString("union"));
    apis->add(QString("unsigned"));
    apis->add(QString("void"));
    apis->add(QString("volatite"));
    apis->add(QString("while"));
    apis->add(QString("asm"));
    apis->add(QString("bool"));
    apis->add(QString("catch"));
    apis->add(QString("class"));
    apis->add(QString("const_cast"));
    apis->add(QString("delete"));
    apis->add(QString("dynamic_cast"));
    apis->add(QString("explicit"));
    apis->add(QString("false"));
    apis->add(QString("friend"));
    apis->add(QString("inline"));
    apis->add(QString("mutable"));
    apis->add(QString("namespace"));
    apis->add(QString("new"));
    apis->add(QString("operator"));
    apis->add(QString("private"));
    apis->add(QString("protected"));
    apis->add(QString("public"));
    apis->add(QString("interpret_cast"));
    apis->add(QString("static_cast"));
    apis->add(QString("template"));
    apis->add(QString("this"));
    apis->add(QString("throw"));
    apis->add(QString("true"));
    apis->add(QString("try"));
    apis->add(QString("typeid"));
    apis->add(QString("typename"));
    apis->add(QString("virtual"));
    apis->add(QString("using"));
    apis->add(QString("wchar_t"));
    apis->prepare();
}
void Texteditor::init_editor(){
    textlexer = new QsciLexerCPP(this);
    textlexer->setColor(Qt::darkGreen,QsciLexerCPP::PreProcessor);
    textlexer->setColor(Qt::black,QsciLexerCPP::Default);
    textlexer->setColor(Qt::darkGray,QsciLexerCPP::Keyword);
    textlexer->setColor(Qt::red,QsciLexerCPP::UnclosedString);
    textlexer->setColor(Qt::darkCyan,QsciLexerCPP::UserLiteral);
    textlexer->setColor(Qt::darkCyan,QsciLexerCPP::TripleQuotedVerbatimString);
    textlexer->setColor(Qt::darkRed,QsciLexerCPP::Comment);
    textlexer->setColor(Qt::darkRed,QsciLexerCPP::CommentDoc);
    textlexer->setColor(Qt::darkCyan,QsciLexerCPP::HashQuotedString);
    textlexer->setColor(Qt::darkCyan,QsciLexerCPP::SingleQuotedString);
    textlexer->setColor(Qt::darkMagenta,QsciLexerCPP::DoubleQuotedString);
    textlexer->setColor(Qt::darkRed,QsciLexerCPP::PreProcessorComment);
    textlexer->setColor(Qt::darkRed,QsciLexerCPP::PreProcessorCommentLineDoc);
    textlexer->setColor(Qt::darkRed,QsciLexerCPP::CommentLine);
    textlexer->setColor(Qt::darkRed,QsciLexerCPP::CommentLineDoc);
    zoomTo(5);
    QFont fontnormal;
    fontnormal.setFamily("consolas");
    textlexer->setFont(fontnormal);
    QFont fontbold;
    fontbold.setFamily("consolas");
    fontbold.setBold(true);
    textlexer->setFont(fontbold,QsciLexerCPP::Keyword);
    QFont fontitalic;
    fontitalic.setFamily("consolas");
    fontitalic.setItalic(true);
    textlexer->setFont(fontitalic,QsciLexerCPP::Comment);
    textlexer->setFont(fontitalic,QsciLexerCPP::CommentDoc);
    textlexer->setFont(fontitalic,QsciLexerCPP::CommentLine);
    textlexer->setFont(fontitalic,QsciLexerCPP::CommentLineDoc);
    textlexer->setFont(fontitalic,QsciLexerCPP::PreProcessorComment);
    textlexer->setFont(fontitalic,QsciLexerCPP::PreProcessorCommentLineDoc);

    setLexer(textlexer);

    apis = new QsciAPIs(textlexer);
    setapis();

    setAutoIndent(true);
    setIndentationGuides(true);

    setCaretWidth(2);//光标宽度，0表示不显示光标
    setCaretForegroundColor(Qt::black);  //光标颜色
    setCaretLineVisible(true); //是否高亮显示光标所在行
    setCaretLineBackgroundColor(Qt::lightGray);//光标所在行背景颜色

    setUnmatchedBraceForegroundColor(Qt::lightGray);
    setUnmatchedBraceBackgroundColor(Qt::red);

    setBraceMatching(QsciScintilla::SloppyBraceMatch);

    setMarginType(0, QsciScintilla::NumberMargin);
    setMarginLineNumbers(0, true);
    setMarginWidth(0,30);



    setIndentationsUseTabs(true);
    setIndentationWidth(4);
    setTabIndents(false);

    setBackspaceUnindents(true);
    setTabWidth(4);
    setIndentationGuides(true);
    //设置自动补全

    //自动补全

    // 编码UTF-8
    SendScintilla(QsciScintilla::SCI_SETCODEPAGE,QsciScintilla::SC_CP_UTF8);
    // 代码折叠
    setFolding(QsciScintilla::BoxedTreeFoldStyle);
    setFoldMarginColors(Qt::gray,Qt::lightGray);
    //设置提示
    setCallTipsForegroundColor(QColor(Qt::white));
    setCallTipsHighlightColor(QColor(Qt::blue));
    setHotspotBackgroundColor(QColor(Qt::gray));
    setCallTipsStyle(QsciScintilla::CallTipsNoAutoCompletionContext);
    setWrapMode(QsciScintilla::WrapWhitespace);

    setAutoCompletionSource(QsciScintilla::AcsAll);
    setAutoCompletionCaseSensitivity(true);
    setAutoCompletionThreshold(1);

    setText("#include<iostream>\nusing namespace std;\nint main(int argc, char *argv[]){\n\tcout << \"Hello world!\" << endl; // auto generated by DEF\n\tsystem(\"pause\");\n\treturn 0;\n}");

    connect(this, SIGNAL(textChanged()),this, SLOT(complete_brackets()));
}
Texteditor::~Texteditor(){
//    delete qsci;
//    delete textlexer;
//    delete apis;
}
bool quote_changed_times = 0;
void Texteditor::complete_brackets(){
    int line,index;
    getCursorPosition(&line, &index);
    if(text(line)[index] == '('){
        qDebug() << "Get a bracket";
        QTimer::singleShot(0, [this, line, index](){insert(")");setCursorPosition(line, index+1);});
    }
    else if(text(line)[index] == '['){
        qDebug() << "Get a bracket";
        QTimer::singleShot(0, [this, line, index](){insert("]");setCursorPosition(line, index+1);});
    }
    else if(text(line)[index] == '{'){
        qDebug() << "Get a bracket";
        int tab_num = 0;
        for(int i=0;i<text(line).size();++i){
            if(text(line)[i]=='\t'){
                tab_num++;
            }
        }
        QTimer::singleShot(0, [this, line, index, tab_num](){
            setCursorPosition(line, index+1);
            insert("}");
            insert("\n");
            for(int i=0;i<tab_num+1;++i){
                insert("\t");
            }
            insert("\n");
            setCursorPosition(line+2,0);
            for(int i=0;i<tab_num;++i){
                insert("\t");
            }
            setCursorPosition(line+1, this->text(line+1).size()-1);
        });
    }
    else if(text(line)[index] == '\"'){
        if(quote_changed_times == 0){
            qDebug() << "Get a quotation";
            QTimer::singleShot(0, [this, line, index](){insert("\"");setCursorPosition(line, index+1);});
            quote_changed_times = 1;
        }
        else{
            quote_changed_times = 0;
        }
    }
    else if(text(line)[index] == '\''){
        if(quote_changed_times == 0){
            qDebug() << "Get a quotation";
            QTimer::singleShot(0, [this, line, index](){insert("\'");setCursorPosition(line, index+1);});
            quote_changed_times = 1;
        }
        else{
            quote_changed_times = 0;
        }
    }
}
