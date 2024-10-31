#include "Task.h"
#include "ui_Task.h"
#include <QInputDialog>

Task::Task(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Task)
{
    ui->setupUi(this);

    // Conectar señales y slots
    connect(ui->editButton, &QPushButton::clicked, this, &Task::editSynonyms);  // Conectar el botón Editar
    connect(ui->removeButton, &QPushButton::clicked, this, &Task::removeTaskButton);  // Conectar el botón Quitar
}

Task::~Task()
{
    delete ui;
}

// Slot para editar los sinónimos
void Task::editSynonyms()
{
    // Permitir al usuario editar los sinónimos
    bool ok;
    QString text = QInputDialog::getText(this, tr("Editar sinónimos"),
                                         tr("Sinónimos:"), QLineEdit::Normal,
                                         ui->synonymsLabel->text(), &ok);
    if (ok && !text.isEmpty())
        ui->synonymsLabel->setText(text);
}

// Slot para eliminar la tarea
void Task::removeTaskButton()
{
    emit removeTask(this);
}
