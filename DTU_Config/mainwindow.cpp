#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QToolBar>
#include <QPushButton>
#include <QStatusBar>
#include <QLabel>
#include <QDockWidget>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    resize(600,400);
    QMenuBar * bar = menuBar();
    QToolBar * tool = new QToolBar(this);
    setMenuBar(bar);
    addToolBar(Qt::LeftToolBarArea,tool);
    tool->setAllowedAreas(Qt::LeftToolBarArea | Qt::RightToolBarArea);
    tool->setFloatable(false);


    QMenu * filemenu = bar->addMenu("文件");
    QMenu * editmenu = bar->addMenu("编辑");

    QAction * newAction = filemenu->addAction("新建");
    filemenu->addSeparator();
    QAction * openAction = filemenu->addAction("打开");
    editmenu->addAction("删除");
    tool->addAction(newAction);
    tool->addSeparator();
    tool->addAction(openAction);
    tool->addSeparator();
    QPushButton * btn = new QPushButton("按钮",this);
    tool->addWidget(btn);

    QStatusBar * status = statusBar();
    setStatusBar(status);

    QLabel * label = new QLabel("提示信息",this);
    status->addWidget(label);

    QLabel* lab_right = new QLabel("右侧标签",this);
    status->addPermanentWidget(lab_right);

    QDockWidget* dock = new QDockWidget("浮动",this);
    addDockWidget(Qt::BottomDockWidgetArea,dock);
    dock->setAllowedAreas(Qt::TopDockWidgetArea | Qt::BottomDockWidgetArea);

    QTextEdit* edit = new QTextEdit(this);
    setCentralWidget(edit);
}

MainWindow::~MainWindow()
{
    delete ui;
}

