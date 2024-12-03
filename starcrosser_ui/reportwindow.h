#ifndef REPORTWINDOW_H
#define REPORTWINDOW_H

#include <QDialog>

namespace Ui {
class reportWindow;
}

class reportWindow : public QDialog
{
    Q_OBJECT

public:
    explicit reportWindow(QWidget *parent = nullptr);
    ~reportWindow();

private slots:
    void on_pushButton_clicked();

private:
    Ui::reportWindow *ui;
};

#endif // REPORTWINDOW_H
