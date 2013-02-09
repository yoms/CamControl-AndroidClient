#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    tcpSocket = new QTcpSocket(this);
    ui->_hostLineEdit->setText("192.168.1.20");
    connect(ui->pushButton, SIGNAL(clicked()), SLOT(onCaptureClicked()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onCaptureClicked()
{
    tcpSocket->connectToHost(ui->_hostLineEdit->text(),
                             8001);

    while(!tcpSocket->isWritable());
    tcpSocket->write("1");
}
