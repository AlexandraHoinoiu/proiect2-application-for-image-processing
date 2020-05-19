#include "expandpage.h"
#include "ui_expandpage.h"
#include "expand.h"
ExpandPage::ExpandPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ExpandPage)
{
    ui->setupUi(this);
}

ExpandPage::~ExpandPage()
{
    delete ui;
}

void ExpandPage::on_pushButton_clicked()
{
    QString factor = ui->textEdit->toPlainText();
    if(factor.toFloat() != NULL) {
        Expand bigImage("C:\\Users\\alexandra.hoinoiu\\Desktop\\an3 sem2\\proiect2\\proiect2\\fruits.jpg",factor.toFloat());
        bigImage.expand();
    } else {
        Expand bigImage("C:\\Users\\alexandra.hoinoiu\\Desktop\\an3 sem2\\proiect2\\proiect2\\fruits.jpg",2);
        bigImage.expand();
    }

}
