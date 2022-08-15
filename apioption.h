#ifndef APIOPTION_H
#define APIOPTION_H

#include <QDialog>

namespace Ui {
class apioption;
}

class apioption : public QDialog
{
    Q_OBJECT

public:
    explicit apioption(QWidget *parent = nullptr);
    ~apioption();

private slots:
    void on_buttonBox_accepted();

    void on_buttonBox_rejected();

private:
    Ui::apioption *ui;
};

#endif // APIOPTION_H
