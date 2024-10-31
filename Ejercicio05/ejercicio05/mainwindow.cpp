#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Conectar el botón de agregar tarea a su slot correspondiente
    connect(ui->addTaskButton, &QPushButton::clicked, this, &MainWindow::addTask);
}

MainWindow::~MainWindow()
{
    delete ui;
}

// Slot para agregar una nueva tarea
void MainWindow::addTask()
{
    Task *task = new Task(this);
    mTasks.append(task);

    // Agregar el widget Task al layout
    ui->tasksLayout->addWidget(task);

    // Conectar la señal de eliminar tarea con el slot de MainWindow
    connect(task, &Task::removeTask, this, &MainWindow::onTaskRemoved);
}

// Slot para eliminar una tarea
void MainWindow::onTaskRemoved(Task* task)
{
    ui->tasksLayout->removeWidget(task);
    mTasks.removeOne(task);
    task->deleteLater();  // Eliminar la tarea
}
