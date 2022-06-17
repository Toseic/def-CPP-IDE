QScintilla安装教程：https://blog.csdn.net/kangkanglhb88008/article/details/121395643  

# 2.1版本说明：
# 注意！需要解压出QScintilla文件夹
## （gws）界面优化：  
软件美化：导入了icon.png作为图标和theme.qss作为软件皮肤  
自动引号  
完善了颜色字体设计  


# 2.0版本说明：
# 注意！需要解压出QScintilla文件夹
## （gws）加入了代码功能：
文法分析  
边缘序号  
标注选中  
代码折叠  

## (MOLYHECI) 新建Texteditor类
将原本位于mainwindow.cpp的一些设置放到Texteditor类里面  
重新设置字体、颜色 （可改）  
自动括号、提示与补全  

## BUG：
暂不支持中文  
未导入icon  (已在2.1解决)

# 1.0版本说明：

## （gws）加入了基础功能：
新建：开启一个新的窗口，生成默认代码  
打开：打开一个cpp文件（暂不支持中文）  
保存：保存cpp文件，如果是新建文件则选择保存地址  
另存为：选择保存地址保存cpp文件（暂不支持中文）  
退出：关闭窗口  
撤销、重做、复制、剪切、粘贴、全选  
编译：保存，然后使用g++.exe将cpp文件编译生成exe文件  
运行：执行生成的exe文件  
编译并运行  
关于  

## BUG：
暂不支持中文  
未导入icon  (已在2.1解决)
