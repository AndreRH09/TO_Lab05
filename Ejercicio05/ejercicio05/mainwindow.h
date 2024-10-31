#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include "Task.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void addTask();            // Slot para agregar sinónimos
    void onTaskRemoved(Task* task);  // Slot para manejar la eliminación de una tarea

private:
    Ui::MainWindow *ui;
    QVector<Task*> mTasks;  // Vector de tareas
};

#endif // MAINWINDOW_H
