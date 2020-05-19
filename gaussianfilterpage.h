#ifndef GAUSSIANFILTERPAGE_H
#define GAUSSIANFILTERPAGE_H

#include <QWidget>

namespace Ui {
class GaussianFilterPage;
}

class GaussianFilterPage : public QWidget
{
    Q_OBJECT

public:
    explicit GaussianFilterPage(QWidget *parent = nullptr);
    ~GaussianFilterPage();

private slots:
    void on_pushButton_clicked();

private:
    Ui::GaussianFilterPage *ui;
};

#endif // GAUSSIANFILTERPAGE_H
