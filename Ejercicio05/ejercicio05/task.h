#ifndef TASK_H
#define TASK_H

#include <QWidget>
#include "ui_Task.h"

namespace Ui {
class Task;
}

class Task : public QWidget
{
    Q_OBJECT

public:
    explicit Task(QWidget *parent = nullptr);
    ~Task();

signals:
    void removeTask(Task *task);  // Señal para eliminar la tarea

private:
    Ui::Task *ui;
};

#endif // TASK_H
