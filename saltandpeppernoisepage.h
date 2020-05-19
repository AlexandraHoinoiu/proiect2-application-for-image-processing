#ifndef SALTANDPEPPERNOISEPAGE_H
#define SALTANDPEPPERNOISEPAGE_H

#include <QWidget>

namespace Ui {
class SaltAndPepperNoisePage;
}

class SaltAndPepperNoisePage : public QWidget
{
    Q_OBJECT

public:
    explicit SaltAndPepperNoisePage(QWidget *parent = nullptr);
    ~SaltAndPepperNoisePage();

private slots:
    void on_pushButton_clicked();

private:
    Ui::SaltAndPepperNoisePage *ui;
};

#endif // SALTANDPEPPERNOISEPAGE_H
