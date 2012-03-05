#include "caesarciphertab.h"
#include "ui_caesarciphertab.h"

#include <cipher.h>

CaesarCipherTab::CaesarCipherTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CaesarCipherTab)
{
    ui->setupUi(this);

    connect(ui->spinBox, SIGNAL(valueChanged(int)), ui->frequencyChart, SLOT(setShift(int)));
    connect(ui->spinBox, SIGNAL(valueChanged(int)), this, SLOT(editInfoText(int)));
    connect(ui->btnDecrypt, SIGNAL(clicked()), this, SLOT(decryptText()));
}

void CaesarCipherTab::editInfoText(int shift)
{
    ui->txtShiftD->setText(QString::number(shift)+" pozic");
    shift = -1*shift;
    if(shift < 0) shift += 26;
    ui->txtShiftE->setText(QString::number(shift)+" pozic");
}

void CaesarCipherTab::setEncryptText(QString text)
{
    mEncryptText = text;
    QList<float> dict = Cipher::getFrequencyAnalysis(text);
    ui->frequencyChart->setDict(dict);
}

void CaesarCipherTab::decryptText()
{
    int shift = ui->spinBox->value();
    shift = -1*shift; // chceme posun před šifrováním
    if(shift < 0) shift += 26;
    QString dText = Cipher::caesarDecrypt(mEncryptText, shift);
    emit decryptedText(dText);
}

CaesarCipherTab::~CaesarCipherTab()
{
    delete ui;
}
