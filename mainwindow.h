#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTcpSocket>
#include <QModelIndex>
#include "client.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void onCaptureClicked();
    void onServerListUpdate();
    void onSearchClicked();
    void onServerSelectedChange(QModelIndex);

private:
    Ui::MainWindow *ui;
    Client m_client;

};

#endif // MAINWINDOW_H
