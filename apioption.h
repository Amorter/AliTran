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

private:
    Ui::apioption *ui;
};

#endif // APIOPTION_H
