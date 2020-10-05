#include "widget.h"
#include "ui_widget.h"
#include <QFileDialog>
#include <QFile>
#include <QTextCodec>
#include <QFileInfo>
#include <QDateTime>
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    connect(ui->pushButton,&QPushButton::clicked,[=](){
        QString filename = QFileDialog::getOpenFileName(this,"打开文件","C:\\Users\\silen\\Desktop","*.txt");
        ui->lineEdit->setText(filename);
        QFile file(filename);
        QTextCodec * codec= QTextCodec::codecForName("gbk");

        file.open(QIODevice::ReadOnly);
        ui->textEdit->setText(codec->toUnicode(file.readAll()));
        file.close();

        QFileInfo info(file);

        file.open(QIODevice::Append);//打开可写，追加写的模式
        file.write(codec->fromUnicode("\n"));
        file.write(codec->fromUnicode("文件路径："));
        file.write(codec->fromUnicode(info.absoluteFilePath()));
        file.write(codec->fromUnicode("\n"));
        file.write(codec->fromUnicode("文件大小："));
        file.write(codec->fromUnicode(QString::number(info.size())));
        file.write(codec->fromUnicode("\n"));
        file.write(codec->fromUnicode("最后修改时间："));
        file.write(codec->fromUnicode(info.lastModified().toString("yyyy/MM/dd hh:mm:ss")));
        file.close();


    });
}

Widget::~Widget()
{
    delete ui;
}

