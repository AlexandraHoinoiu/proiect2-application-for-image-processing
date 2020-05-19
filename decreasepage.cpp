#include "decreasepage.h"
#include "ui_decreasepage.h"
#include "decrease.h"

DecreasePage::DecreasePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::DecreasePage)
{
    ui->setupUi(this);
}

DecreasePage::~DecreasePage()
{
    delete ui;
}

void DecreasePage::on_pushButton_clicked()
{
    QString factor = ui->textEdit->toPlainText();
    if(factor.toFloat() != NULL) {
        Decrease smallImage("C:\\Users\\alexandra.hoinoiu\\Desktop\\an3 sem2\\proiect2\\proiect2\\fruits.jpg",factor.toFloat());
        smallImage.decrease();
    } else {
        Decrease smallImage("C:\\Users\\alexandra.hoinoiu\\Desktop\\an3 sem2\\proiect2\\proiect2\\fruits.jpg",2);
        smallImage.decrease();
    }
}
