#include "saltandpeppernoisepage.h"
#include "ui_saltandpeppernoisepage.h"
#include "saltpeppernoise.h"

SaltAndPepperNoisePage::SaltAndPepperNoisePage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SaltAndPepperNoisePage)
{
    ui->setupUi(this);
}

SaltAndPepperNoisePage::~SaltAndPepperNoisePage()
{
    delete ui;
}

void SaltAndPepperNoisePage::on_pushButton_clicked()
{
    QString percentage = ui->textEdit->toPlainText();
    if (percentage.toFloat() != NULL) {
        SaltPepperNoise noise_salt_pepper("C:\\Users\\alexandra.hoinoiu\\Desktop\\an3 sem2\\proiect2\\proiect2\\fruits.jpg",percentage.toFloat());
        noise_salt_pepper.applyNoise();
    } else {
        SaltPepperNoise noise_salt_pepper("C:\\Users\\alexandra.hoinoiu\\Desktop\\an3 sem2\\proiect2\\proiect2\\fruits.jpg", 20);
        noise_salt_pepper.applyNoise();
    }
}
