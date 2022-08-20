#ifndef TRANOPTION_H
#define TRANOPTION_H

#include <QDialog>

namespace Ui {
class tranoption;
}

class tranoption : public QDialog
{
    Q_OBJECT

public:
    explicit tranoption(QWidget *parent = nullptr);
    ~tranoption();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::tranoption *ui;
};

#endif // TRANOPTION_H
