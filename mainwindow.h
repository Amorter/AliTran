#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include "apioption.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    apioption *apioption;
private slots:
    void on_apioption_triggered();
    void on_tranButton_clicked();

    void on_Lzh_cn_triggered();

    void on_Len_us_triggered();

    void on_tran_option_triggered();

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
