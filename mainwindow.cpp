#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
   // printQRCode();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::printQRCode()
{

}

void MainWindow::on_pushButton_clicked()
{

    QString path = QFileDialog::getSaveFileName(this, tr("Save as image"), "", tr("PNG file (*.png)"));

    if (path.isEmpty())
        return;

    QImage img(600, 600, QImage::Format_ARGB32);

    QPainter painter;
    painter.begin(&img);

    //QPainter painter(&printer);

    QSize size;
    size.setWidth(400);
    size.setHeight(400);
    MyQRCode qr;
    qr.paintQR(painter,QPoint(0,0),size,"https://solucionestip.com",QColor(0, 0, 0));
    painter.end();
    //ui->label->setPixmap()

    img.save(path);

    qDebug()<<"make qr";
}
