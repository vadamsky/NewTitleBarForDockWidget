#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "qtreewidget.h"
#include <QDockWidget>
#include "titlebar.h"
MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    this->setMinimumSize(700,770);
    ui->setupUi(this);
    // Dock widget
    QDockWidget* dockWidget = new QDockWidget(tr("Dock widget header"), this);
    QTreeWidget* tree=new QTreeWidget();
    QStringList treeHeader;
    treeHeader<<"Header1"<<"Header2";
    tree->setHeaderLabels(treeHeader);
    //Set tree on dockWidget
    dockWidget->setWidget(tree);
    // Place dock
    addDockWidget(Qt::BottomDockWidgetArea, dockWidget);

    //title bar
    Titlebar* titleBar = new Titlebar(dockWidget);
    //set title bar for dock widget
    dockWidget->setTitleBarWidget(titleBar);
}

MainWindow::~MainWindow()
{
    delete ui;
}
