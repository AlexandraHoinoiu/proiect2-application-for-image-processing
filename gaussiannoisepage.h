#ifndef GAUSSIANNOISEPAGE_H
#define GAUSSIANNOISEPAGE_H

#include <QWidget>

namespace Ui {
class GaussianNoisePage;
}

class GaussianNoisePage : public QWidget
{
    Q_OBJECT

public:
    explicit GaussianNoisePage(QWidget *parent = nullptr);
    ~GaussianNoisePage();

private slots:
    void on_pushButton_clicked();

private:
    Ui::GaussianNoisePage *ui;
};

#endif // GAUSSIANNOISEPAGE_H
