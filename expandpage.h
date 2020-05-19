#ifndef EXPANDPAGE_H
#define EXPANDPAGE_H

#include <QWidget>

namespace Ui {
class ExpandPage;
}

class ExpandPage : public QWidget
{
    Q_OBJECT

public:
    explicit ExpandPage(QWidget *parent = nullptr);
    ~ExpandPage();

private slots:
    void on_pushButton_clicked();

private:
    Ui::ExpandPage *ui;
};

#endif // EXPANDPAGE_H
