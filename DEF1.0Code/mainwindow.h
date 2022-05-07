#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QMenu>
#include <QMenuBar>
#include <QAction>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);

    QString file_path; // 文件路径
    QTextEdit *text_content; // 代码编辑框

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

    QMenu *mhelp; // 菜单：Help 帮助
    QAction *aabout; // 动作：About 关于


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

    void on_compile();
    void on_run();
    void on_compileandrun();

    void on_about();

};
#endif // MAINWINDOW_H
