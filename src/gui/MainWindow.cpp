#include "MainWindow.hpp"

#include "ui_MainWindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent), ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    auto file = new QMenu("File", ui->menuBar);
    auto quit = new QAction("Quit", file);
    connect(quit, &QAction::triggered, this, []() { qApp->quit(); });
    file->addAction(quit);

    ui->menuBar->addMenu(file);

    btnActivateConnection = new QPushButton();
    btnActivateConnection->setText("connect");
    layout()->addWidget(btnActivateConnection);
    connect(btnActivateConnection, SIGNAL(&QPushButton::clicked), this,
            SLOT(activateConnection()));
}

void MainWindow::activateConnection()
{
    if (btnActivateConnection->text() == "connect")
        btnActivateConnection->setText("disconect");
    else
        btnActivateConnection->setText("connect");
}

MainWindow::~MainWindow()
{
    delete ui;
}
