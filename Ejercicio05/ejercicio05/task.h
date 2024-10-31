#ifndef TASK_H
#define TASK_H

#include <QWidget>
#include <QCheckBox>
#include <QPushButton>
#include <QLabel>

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

private slots:
    void editSynonyms();  // Slot para editar los sinónimos
    void removeTaskButton();  // Slot para manejar la eliminación de la tarea

private:
    Ui::Task *ui;
    QCheckBox *checkbox;
    QLabel *synonymsLabel;
    QPushButton *editButton;
    QPushButton *removeButton;
};

#endif // TASK_H
