#include "texteditor.h"

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

    setLexer(textlexer);
    setMarginType(0, QsciScintilla::NumberMargin);
    setMarginLineNumbers(0, true);
    setMarginWidth(0,30);
    //括号匹配
    setUnmatchedBraceBackgroundColor(Qt::blue);
    setBraceMatching(QsciScintilla::SloppyBraceMatch);
    // Tab缩进
    setIndentationsUseTabs(true);
    setIndentationWidth(4);
    setTabIndents(false);
    setAutoIndent(true);
    setBackspaceUnindents(true);
    setTabWidth(4);
    setIndentationGuides(true);
    //设置自动补全
    apis = new QsciAPIs(textlexer);
    setapis();
    //自动补全
    setAutoCompletionSource(QsciScintilla::AcsAll);
    setAutoCompletionCaseSensitivity(true);
    setAutoCompletionThreshold(1);
    setCaretLineVisible(true);
    // 选中行背景色
    setCaretLineBackgroundColor(Qt::lightGray);
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

    textlexer->setColor(QColor("#FFA0C4"),QsciLexerCPP::PreProcessor);
    textlexer->setColor(QColor(Qt::blue),QsciLexerCPP::Keyword);
    textlexer->setColor(QColor(Qt::red),QsciLexerCPP::UnclosedString);
    textlexer->setColor(QColor("#800080"),QsciLexerCPP::UserLiteral);
    textlexer->setColor(QColor(Qt::darkGreen),QsciLexerCPP::TripleQuotedVerbatimString);
    textlexer->setColor(QColor(Qt::darkGreen),QsciLexerCPP::Comment);
    textlexer->setColor(QColor(Qt::darkGreen),QsciLexerCPP::HashQuotedString);
    textlexer->setColor(QColor(Qt::darkGreen),QsciLexerCPP::DoubleQuotedString);
    textlexer->setColor(QColor(Qt::darkGreen),QsciLexerCPP::PreProcessorComment);
    textlexer->setColor(QColor(Qt::darkGreen),QsciLexerCPP::CommentLine);
    textlexer->setFont(QFont("Monaco"));

    setText("#include<iostream>\nusing namespace std;\nint main(){\n\tcout << \"Hello world!\" << endl;\n\tsystem(\"pause\");\n\treturn 0;\n}");
}
Texteditor::~Texteditor(){
//    delete qsci;
//    delete textlexer;
//    delete apis;
}
