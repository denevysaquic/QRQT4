#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    printQRCode();
}

MainWindow::~MainWindow()
{
    delete ui;
}

MainWindow::printQRCode()
{
    QPrinter printer;
//    printer.setPrinterName("DASCOM DS-650Pro"); / / printer name
    printer.setPrinterName("CutePDF Writer");
    QPainter painter(&printer);

    QSize size;
    size.setWidth(300);
    size.setHeight(300);
    MyQRCode qr;
    qr.paintQR(painter,QPoint(150,200),size,"Hello, dregs",QColor(0, 160, 230));
    painter.end();
}
