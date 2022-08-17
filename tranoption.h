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

private:
    Ui::tranoption *ui;
};

#endif // TRANOPTION_H
