#ifndef TRANSCATIONENTRY_H
#define TRANSCATIONENTRY_H

#include <QDialog>

namespace Ui {
class TranscationEntry;
}

class TranscationEntry : public QDialog
{
    Q_OBJECT

public:
    explicit TranscationEntry(QWidget *parent = nullptr);
    ~TranscationEntry();

private slots:


    void on_doneBtn_clicked();

private:
    Ui::TranscationEntry *ui;
};

#endif // TRANSCATIONENTRY_H
