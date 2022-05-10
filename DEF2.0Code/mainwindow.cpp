#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <qsciscintilla.h>
#include <qscilexercpp.h>
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this -> setWindowTitle("新建文件");
    // 代码编辑器
    textEdit = new QsciScintilla;
    // 文法分析器
    QsciLexerCPP *textLexer = new QsciLexerCPP;
    textEdit->setLexer(textLexer);
    // 边缘序号
    textEdit->setMarginType(0, QsciScintilla::NumberMargin);
    textEdit->setMarginLineNumbers(0, true);
    textEdit->setMarginWidth(0,30);
    textEdit->setTabWidth(4);
    // 自动括号
    textEdit->setUnmatchedBraceBackgroundColor(Qt::blue);
    textEdit->setBraceMatching(QsciScintilla::SloppyBraceMatch);
    textEdit->setIndentationGuides(true);
    textEdit->setAutoIndent(true);
    // 自动补全
    textEdit->setCaretLineVisible(true);
    // 选中行背景色
    textEdit->setCaretLineBackgroundColor(Qt::lightGray);
    // 编码UTF-8
    textEdit->SendScintilla(QsciScintilla::SCI_SETCODEPAGE,QsciScintilla::SC_CP_UTF8);
    // 代码折叠
    textEdit->setFolding(QsciScintilla::BoxedTreeFoldStyle);
    textEdit->setFoldMarginColors(Qt::gray,Qt::lightGray);

    // 摆放代码编辑器
    this -> setCentralWidget(textEdit);
    textEdit->setText("#include<iostream>\nusing namespace std;\nint main(){\n\tcout << \"Hello world!\" << endl;\n\tsystem(\"pause\");\n\treturn 0;\n}");

    //菜单栏
    // File
    mfile = this -> menuBar() -> addMenu("文件");

    anew = new QAction("新建",this);
    anew->setShortcut(QKeySequence::New); // Ctrl + N
    mfile->addAction(anew);

    aopen = new QAction("打开",this);
    aopen->setShortcut(QKeySequence::Open); // Ctrl + O
    mfile->addAction(aopen);

    asave = new QAction("保存",this);
    asave->setShortcut(QKeySequence::Save); // Ctrl + S
    mfile->addAction(asave);

    asaveas = new QAction("另存为...",this);
    asaveas->setShortcut(QKeySequence::SaveAs); // Shift + Ctrl + S
    mfile->addAction(asaveas);

    mfile->addSeparator(); // 分隔符

    aexit = new QAction("退出",this);
    aexit->setShortcut(QKeySequence::Close); // Ctrl + W
    mfile->addAction(aexit);

    // Edit
    medit = this -> menuBar() -> addMenu("编辑");

    aundo = new QAction("撤销",this);
    aundo->setShortcut(QKeySequence::Undo); // Ctrl + Z
    medit->addAction(aundo);

    aredo = new QAction("重做",this);
    aredo->setShortcut(QKeySequence::Redo); // Ctrl + Shift + Z
    medit->addAction(aredo);

    medit->addSeparator(); // 分隔符

    acopy = new QAction("复制",this);
    acopy->setShortcut(QKeySequence::Copy); // Ctrl + C
    medit->addAction(acopy);

    acut = new QAction("剪切",this);
    acut->setShortcut(QKeySequence::Cut); // Ctrl + X
    medit->addAction(acut);

    apaste = new QAction("粘贴",this);
    apaste->setShortcut(QKeySequence::Paste); // Ctrl + V
    medit->addAction(apaste);

    medit->addSeparator(); // 分隔符

    aselectall = new QAction("全选",this);
    aselectall->setShortcut(QKeySequence::SelectAll); // Ctrl + A
    medit->addAction(aselectall);

    // Build
    mbuild = this -> menuBar() -> addMenu("构建");

    acompile = new QAction("编译",this);
    mbuild->addAction(acompile);

    arun = new QAction("运行",this);
    mbuild->addAction(arun);

    acompileandrun = new QAction("编译并运行",this);
    acompileandrun->setShortcut(tr("F5"));
    mbuild->addAction(acompileandrun);

    // Help
    mhelp = this -> menuBar() -> addMenu("帮助");

    aabout = new QAction("关于",this);
    aabout->setShortcut(tr("Ctrl+H"));
    mhelp->addAction(aabout);

    // 消息槽
    connect(anew,SIGNAL(triggered(bool)),this,SLOT(on_new()));
    connect(aopen,SIGNAL(triggered(bool)),this,SLOT(on_open()));
    connect(asave,SIGNAL(triggered(bool)),this,SLOT(on_save()));
    connect(asaveas,SIGNAL(triggered(bool)),this,SLOT(on_saveas()));
    connect(aexit,SIGNAL(triggered(bool)),this,SLOT(on_exit()));

    connect(aundo,SIGNAL(triggered(bool)),this,SLOT(on_undo()));
    connect(aredo,SIGNAL(triggered(bool)),this,SLOT(on_redo()));
    connect(acopy,SIGNAL(triggered(bool)),this,SLOT(on_copy()));
    connect(acut,SIGNAL(triggered(bool)),this,SLOT(on_cut()));
    connect(apaste,SIGNAL(triggered(bool)),this,SLOT(on_paste()));
    connect(aselectall,SIGNAL(triggered(bool)),this,SLOT(on_selectall()));

    connect(acompile,SIGNAL(triggered(bool)),this,SLOT(on_compile()));
    connect(arun,SIGNAL(triggered(bool)),this,SLOT(on_run()));
    connect(acompileandrun,SIGNAL(triggered(bool)),this,SLOT(on_compileandrun()));

    connect(aabout,SIGNAL(triggered(bool)),this,SLOT(on_about()));
}

// 新建
void MainWindow::on_new(){
    MainWindow *new_w = new MainWindow;
    new_w -> resize(1500,1200);
    new_w -> show();
}

// 打开
void MainWindow::on_open(){
    file_path = QFileDialog::getOpenFileName(this,"选择文件","","C++ 文件(*.cpp)"); // 读取文件位置
    if(file_path.isEmpty()){
        return;
    }
    QString open_content;
    FILE *p = fopen(file_path.toStdString().data(),"r"); // 将QString转换为const char *
    if(p == NULL){
        QMessageBox::information(this,"错误","无法打开文件");
        this -> setWindowTitle(file_path);
    }else{
        while(!feof(p)){ // 读入数据
            char buffer[1024] = {0};
            fgets(buffer, sizeof(buffer), p);
            open_content += buffer;
        }
        fclose(p);
        textEdit -> setText(open_content); // 向文本框写入
        this -> setWindowTitle(file_path);
    }
}

// 保存
void MainWindow::on_save(){
    // 如果当前不存在位置则另存为
    if(file_path.isEmpty()){
        MainWindow::on_saveas();
    }else{
        FILE *p = fopen(file_path.toStdString().data(),"w"); // 将QString转换为const char *
        if(p == NULL){
            QMessageBox::information(this,"错误","无法保存文件");
            this -> setWindowTitle(file_path);
        }else{
            fputs(textEdit->text().toStdString().data(),p);
            fclose(p);
            this -> setWindowTitle(file_path);
        }
    }
}

// 另存为
void MainWindow::on_saveas(){
    file_path = QFileDialog::getSaveFileName(this,"选择位置","","C++ 文件(*.cpp)"); // 选择保存位置
    if(file_path.isEmpty()){
        return;
    }
    FILE *p = fopen(file_path.toStdString().data(),"w"); // 将QString转换为const char *
    if(p == NULL){
        QMessageBox::information(this,"错误","无法保存文件");
        this -> setWindowTitle(file_path);
    }else{
        fputs(textEdit->text().toStdString().data(),p);
        fclose(p);
        this -> setWindowTitle(file_path);
    }
}

// 退出
void MainWindow::on_exit(){
    this -> close();
}

// 撤销
void MainWindow::on_undo(){
    textEdit -> undo();
}

// 重做
void MainWindow::on_redo(){
    textEdit -> redo();
}

// 复制
void MainWindow::on_copy(){
    textEdit -> copy();
}

// 剪切
void MainWindow::on_cut(){
    textEdit -> cut();
}

// 粘贴
void MainWindow::on_paste(){
    textEdit -> paste();
}

// 全选
void MainWindow::on_selectall(){
    textEdit -> selectAll();
}

// 编译
void MainWindow::on_compile(){
    MainWindow::on_save(); // 保存
    QString generate_file_path = file_path;
    generate_file_path.replace(".cpp",".exe");
    QString command="g++.exe "+ file_path +" -o " + generate_file_path;
    system(command.toStdString().data());
}

// 运行
void MainWindow::on_run(){
    QString generate_file_path = file_path;
    generate_file_path.replace(".cpp",".exe");
    system(generate_file_path.toStdString().data());
}

// 编译并运行
void MainWindow::on_compileandrun(){
    MainWindow::on_compile();
    MainWindow::on_run();
}

// 关于
void MainWindow::on_about(){
    QMessageBox::information(this,"关于","DEF C++ IDE 2022");
}

MainWindow::~MainWindow()
{
    delete ui;
}
