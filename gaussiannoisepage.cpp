#include "gaussiannoisepage.h"
#include "ui_gaussiannoisepage.h"
#include "gaussianoise.h"

GaussianNoisePage::GaussianNoisePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::GaussianNoisePage)
{
    ui->setupUi(this);
}

GaussianNoisePage::~GaussianNoisePage()
{
    delete ui;
}

void GaussianNoisePage::on_pushButton_clicked()
{
    QString sigma = ui->textEdit->toPlainText();
    QString mean = ui->textEdit_2->toPlainText();
    if(sigma.toFloat() != NULL && mean.toFloat() != NULL) {
        GaussiaNoise noise_gauss("C:\\Users\\alexandra.hoinoiu\\Desktop\\an3 sem2\\proiect2\\proiect2\\fruits.jpg",
                                 sigma.toFloat(),mean.toFloat());
        noise_gauss.applyNoise();
    } else {
        GaussiaNoise noise_gauss("C:\\Users\\alexandra.hoinoiu\\Desktop\\an3 sem2\\proiect2\\proiect2\\fruits.jpg");
        noise_gauss.applyNoise();
    }
}
