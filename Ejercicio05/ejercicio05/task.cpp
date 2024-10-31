#include "Task.h"
#include "ui_Task.h"

Task::Task(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Task)
{
    ui->setupUi(this);

    // Conectar el clic del checkbox a la señal para eliminar la tarea
    connect(ui->checkbox, &QCheckBox::clicked, this, [this]() {
        emit removeTask(this);  // Emitir señal para eliminar la tarea
    });
}

Task::~Task()
{
    delete ui;
}
