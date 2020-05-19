#ifndef DECREASEPAGE_H
#define DECREASEPAGE_H

#include <QWidget>

namespace Ui {
class DecreasePage;
}

class DecreasePage : public QWidget
{
    Q_OBJECT

public:
    explicit DecreasePage(QWidget *parent = nullptr);
    ~DecreasePage();

private slots:
    void on_pushButton_clicked();

private:
    Ui::DecreasePage *ui;
};

#endif // DECREASEPAGE_H
