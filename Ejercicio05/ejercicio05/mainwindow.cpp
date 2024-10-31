#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(ui->addTaskButton, &QPushButton::clicked, this, &MainWindow::addTask);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::addTask()
{
    Task *task = new Task(this);
    mTasks.append(task);
    ui->tasksLayout->addWidget(task);

    // Conectar la señal de eliminar tarea con el slot de MainWindow
    connect(task, &Task::removeTask, this, &MainWindow::onTaskRemoved);
}

void MainWindow::onTaskRemoved(Task* task)
{
    ui->tasksLayout->removeWidget(task);
    mTasks.removeOne(task);
    task->deleteLater();
}
