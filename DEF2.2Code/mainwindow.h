#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "QMessageBox"
#include "QProcess"
#include "QFileDialog"
#include <qsciscintilla.h>
#include <qscilexercpp.h>
#include <texteditor.h>
#include "settingstore.h"
#include <time.h>
#include <QThread>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    Texteditor *textEdit; // 代码编辑器
    QString file_path; // 文件路径
    QString compiler; // 编译器名称
    QString commandline_arg; // 命令行参数
    QString mytheme; // theme used
    QString themepath; // .qss themefile's path
    settingStore* set_store;
    QLabel *codingtime;
    clock_t start,check;

    QMenu *mfile; // 菜单：File 文件
    QAction *anew; // 动作：New 新建
    QAction *aopen; // 动作：Open 打开
    QAction *asave; // 动作：Save 保存
    QAction *asaveas; // 动作：Save as... 另存为...
    QAction *aexit; // 动作：Exit 退出

    QMenu *medit; // 菜单：Edit 编辑
    QAction *aundo; // 动作：Undo 撤销
    QAction *aredo; // 动作：Redo 重做
    QAction *acopy; // 动作：Copy 复制
    QAction *acut; // 动作：Cut 剪切
    QAction *apaste; // 动作：Paste 粘贴
    QAction *aselectall; // 动作：Select All 全选

    QMenu *mbuild; // 菜单：Build 构建
    QAction *acompile; // 动作：Compile 编译
    QAction *arun; // 动作：Run 运行
    QAction *acompileandrun; // 动作：Compile and Run 编译并运行
    QAction *asettings; // 动作：Settings 设置

    QMenu *mhelp; // 菜单：Help 帮助
    QAction *aabout; // 动作：About 关于

    void set_compiler(QString); 
    void set_commandline_arg(QString);
    void set_theme(QString);  // set color theme
    void set_cursor_width(int); // set cursor's width
    void set_auto_tab(QString); // 设置换行时自动缩进
    void set_auto_tab(bool); // 设置换行时自动缩进
    void set_referline(QString); // 设置缩进参考线
    void set_referline(bool); // 设置缩进参考线
    void set_codingtime(bool); // 设置是否打开coding time显示

    void set_store_refresh(); // 通过setstore的内容更新所有设置


    ~MainWindow();

private:
    Ui::MainWindow *ui;

private slots:
    void on_new();
    void on_open();
    void on_save();
    void on_saveas();
    void on_exit();

    void on_undo();
    void on_redo();
    void on_copy();
    void on_cut();
    void on_paste();
    void on_selectall();

    bool on_compile();
    void on_run();
    void on_compileandrun();
    void on_settings();

    void on_about();


    // void theme_set(QString);
};

class ct_thread: public QThread { // 用于更新codingtime的线程
public:
    MainWindow *mw;
    void set_mw(MainWindow *);
    virtual void run();
};

#endif // MAINWINDOW_H
