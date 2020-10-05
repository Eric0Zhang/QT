#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include <QDebug>
#include <QMessageBox>
#include <QFileDialog>
#include <QFontDialog>
#include <QColorDialog>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->actionnew->setIcon(QIcon(":/iconset/Image/Luffy.png"));
    ui->actionopen->setIcon(QIcon(":/iconset/Image/LuffyQ.png"));
    connect(ui->actionnew,&QAction::triggered,[=](){
        //模态对话框
//        QDialog dlg(this);
//        qDebug()<<"即将创建模态对话框！";
//        dlg.resize(120,100);
//        dlg.exec();//显示为模态对话框 应用程序级别
//        qDebug()<<"创建了模态对话框！";//这里会阻塞

        QDialog *dlg = new QDialog(this);
        qDebug()<<"即将创建模态对话框！";
        dlg->resize(200,100);
        dlg->open();//显示为模态对话框,open 不同于exec是窗口级别的 不用new创建会一闪而过
        dlg->setAttribute(Qt::WA_DeleteOnClose,true);
        qDebug()<<"创建了模态对话框！";//这里会阻塞

        //非模态对话框
//        QDialog dlg2(this);//这种创建方式是对象树创建,lambda表达式结束时，自动释放掉了。
//        dlg2.show();


//        QDialog * dlg3 = new QDialog(this);//new手动创建，则不会自动释放
//        dlg3->show();
//        dlg3->setAttribute(Qt::WA_DeleteOnClose,true);//防止反复创建，没有显式调用delete，而出现内存泄漏
//        qDebug()<<"创建了非模态对话框！";//这里不会阻塞
    });//发送者actionnew 发送信号triggered 接受者和槽函数是一个lambda表达式
    connect(ui->actionabout,&QAction::triggered,[=](){QMessageBox::about(this,"关于","这个程序由Elliot创建。");});
    connect(ui->actionopen,&QAction::triggered,[=](){
//        QFileDialog *file = new QFileDialog(this);
//        file->exec();
        QString filename =  QFileDialog::getOpenFileName(this,"打开文本","C:\\Users\\silen\\Desktop","(*.txt *.ini *.xml)");
        qDebug()<<"打开文件："<<filename;
    });

    connect(ui->actionfont,&QAction::triggered,[=](){
        bool flag;
        QFont font = QFontDialog::getFont(&flag,QFont("微软雅黑",24),this);
        ui->textEdit->setFont(font);
    });

    connect(ui->actionprint,&QAction::triggered,[=](){
       if( QMessageBox::Save == QMessageBox::question(this,"打印","版权所有：章鱼干红。",QMessageBox::Save|QMessageBox::Cancel,QMessageBox::Save))
       {
           qDebug()<<"选择了保存按钮！";
       }
       else
           qDebug()<<"选择了取消按钮！";
    });

    //通过getColor打开颜色对话框
    connect(ui->actionbackground,&QAction::triggered,[=](){
      QColor cl = QColorDialog::getColor(QColor(255,255,255));
      QPalette palette= ui->textEdit->palette();
      palette.setColor(QPalette::Base, cl);
      QColor ct;
      ct.setRgb(255-cl.red(),255-cl.green(),255-cl.blue());
      palette.setColor(QPalette::Text, ct);
      ui->textEdit->setPalette(palette);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

