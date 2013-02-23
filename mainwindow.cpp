#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QStringListModel>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->_capturePushButton, SIGNAL(clicked()), SLOT(onCaptureClicked()));
    connect(ui->_searchPushButton, SIGNAL(clicked()), SLOT(onSearchClicked()));
    connect(&m_client, SIGNAL(serverListChanged()), SLOT(onServerListUpdate()));
    connect(ui->_serverListView, SIGNAL(pressed(QModelIndex)), SLOT(onServerSelectedChange(QModelIndex)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onCaptureClicked()
{

    m_client.sendCommand("1");
}

void MainWindow::onServerListUpdate()
{
    QAbstractItemModel* oldModel =  ui->_serverListView->model();
    QList<QHostAddress> hostList = m_client.getHostList();
    QStringList hostStringList;
    for(int i = 0; i < hostList.size() ; i++)
    {
        hostStringList << hostList[i].toString();
    }
    ui->_serverListView->setModel(new QStringListModel(hostStringList));
    if(oldModel)
        delete oldModel;
}

void MainWindow::onSearchClicked()
{
    m_client.updateServerRequest();
}

void MainWindow::onServerSelectedChange(QModelIndex index)
{
    m_client.connectToServer( QHostAddress( index.data().toString() ) );
}
