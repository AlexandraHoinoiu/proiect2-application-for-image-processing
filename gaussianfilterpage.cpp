#include "gaussianfilterpage.h"
#include "ui_gaussianfilterpage.h"
#include "gaussianfilter.h"
#include <iostream>

GaussianFilterPage::GaussianFilterPage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GaussianFilterPage)
{
    ui->setupUi(this);
}

GaussianFilterPage::~GaussianFilterPage()
{
    delete ui;
}

void GaussianFilterPage::on_pushButton_clicked()
{
    QString data = ui->textEdit->toPlainText();
    if(data.toFloat() != NULL) {
        GaussianFilter gaussian_filter("C:\\Users\\alexandra.hoinoiu\\Desktop\\an3 sem2\\proiect2\\proiect2\\fruits.jpg",data.toInt());
        gaussian_filter.applyFilter();

    } else {
        GaussianFilter gaussian_filter("C:\\Users\\alexandra.hoinoiu\\Desktop\\an3 sem2\\proiect2\\proiect2\\fruits.jpg");
        gaussian_filter.applyFilter();

    }
}
