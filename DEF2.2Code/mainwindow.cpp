#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "settings.h"
#include <qsciscintilla.h>
#include <texteditor.h>
#include <qscilexercpp.h>
#include "compileinf.h"
#include "settingstore.h"
#include <QLabel>
#include <QThread>
#include<windows.h> // Sleep()



MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this -> setWindowTitle("新建文件");
    compiler = "g++.exe";
    commandline_arg = "";
    start = clock();
    // 储存设置
    set_store = new settingStore();

    // 在statubar中添加codingtime label
    codingtime = new QLabel(this);
    codingtime->setText("0 m");
    ui->statusBar->addPermanentWidget(codingtime);

    //  更新codingtime的线程
    ct_thread *ct = new ct_thread();
    ct->set_mw(this);
    ct->start();

    // 代码编辑器
    textEdit = new Texteditor(this);
    // 摆放编辑器
    this -> setCentralWidget(textEdit);
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

    mbuild->addSeparator(); // 分隔符

    asettings = new QAction("设置",this);
    asettings->setShortcut(QKeySequence::WhatsThis);
    mbuild->addAction(asettings);

    // Help
    mhelp = this -> menuBar() -> addMenu("帮助");

    aabout = new QAction("关于",this);
    aabout->setShortcut(tr("Ctrl+H"));
    mhelp->addAction(aabout);

    // 读取配置文件后刷新设置
    set_store_refresh();

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
    connect(asettings,SIGNAL(triggered(bool)),this,SLOT(on_settings()));

    connect(aabout,SIGNAL(triggered(bool)),this,SLOT(on_about()));
}

void MainWindow::set_compiler(QString str){
    compiler = str;
}

void MainWindow::set_commandline_arg(QString str){
    commandline_arg = str;
}

// 新建
void MainWindow::on_new(){
    MainWindow *new_w = new MainWindow;
    new_w -> resize(1500,1200);
    QFile qssFile(set_store->themePath());
    qssFile.open(QFile::ReadOnly);
    QString qss = QLatin1String(qssFile.readAll());
    new_w->setStyleSheet(qss);
    qssFile.close();
    new_w->setWindowIcon(QIcon("./icon.png"));
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
            fprintf(p,"%s",textEdit->text().toStdString().c_str());
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
        fprintf(p,"%s",textEdit->text().toStdString().c_str());
        fclose(p);
        this -> setWindowTitle(file_path);
    }
}

// 退出
void MainWindow::on_exit(){
    this->set_store->store2file();
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
bool MainWindow::on_compile(){
    MainWindow::on_save(); // 保存
    QString generate_file_path = file_path;
    generate_file_path.replace(".cpp",".exe");
    QString command=compiler + " " + file_path +" -o " + generate_file_path;
    qDebug() << "Now compiling:";
    qDebug() << command.toStdString().data();
    QStringList para;
    para << file_path << "-o" << generate_file_path;
    QProcess compilecmd;
    compilecmd.start(compiler, para);
    compilecmd.waitForStarted();
    compilecmd.waitForFinished();
    CompileInf *information = new CompileInf;
    QString report = compilecmd.readAllStandardError();
    information->setInf(command + "\n" + report);
    information->show();
    if(report.isEmpty()){
        return true;
    }else{
        return false;
    }
}

// 运行
void MainWindow::on_run(){
    QString generate_file_path = file_path;
    generate_file_path.replace(".cpp",".exe");
    QString command=generate_file_path+" "+commandline_arg;
    qDebug() << "Now running:";
    qDebug() << command.toStdString().data();
    system(command.toStdString().data());
}

// 编译并运行
void MainWindow::on_compileandrun(){
    if(MainWindow::on_compile()){
       MainWindow::on_run();
    }
}

// 设置
void MainWindow::on_settings(){
    Settings *set = new Settings(this, NULL);
    qDebug() << themepath << endl;
    QFile qssFile(set_store->themePath());
    qssFile.open(QFile::ReadOnly);
    QString qss = QLatin1String(qssFile.readAll());
    set->setStyleSheet(qss);
    qssFile.close();
    set->setWindowIcon(QIcon("./icon.png"));
    set -> show();
}

// 关于
void MainWindow::on_about(){
    QMessageBox::information(this,"关于","DEF C++ IDE 2022");
}





// codingtime 多线程更新
void ct_thread::run() {
    while (true) {
        if (mw->set_store->coding_time) {  // 通过直接读取set_store的内容设置是否显示codingtime
            mw->check = clock();
            int minut = (int)((mw->check - mw->start) / CLOCKS_PER_SEC) / 60;
            int hour = minut / 60;
            minut %= 60;
            if (hour)
                mw->codingtime->setText("coding time: "+QString::number(hour)+" h "+QString::number(minut)+" m");
            else
                mw->codingtime->setText("coding time: "+QString::number(minut)+" m");
        } else {
            mw->codingtime->setText("");
        }

        Sleep(60000); // sleep one minute
    }
}

void ct_thread::set_mw(MainWindow * mw1) {
    mw = mw1;
}

MainWindow::~MainWindow()
{
    delete ui;
}
