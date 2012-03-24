#include "vigenereciphertab.h"
#include "ui_vigenereciphertab.h"

#include <cipher.h>
#include <QDebug>

VigenereCipherTab::VigenereCipherTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VigenereCipherTab)
{
    ui->setupUi(this);

    connect(ui->btnDecrypt, SIGNAL(clicked()), this, SLOT(decryptText()));
    connect(ui->spinBox, SIGNAL(valueChanged(int)), this, SLOT(splitText(int)));
    connect(ui->comboBox, SIGNAL(currentIndexChanged(int)), this, SLOT(setSubDict(int)));
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), this, SLOT(setSubShift(int)));
}

void VigenereCipherTab::setEncryptText(QString text)
{
    mEncryptText = text;
}

void VigenereCipherTab::splitText(int keyLength)
{
    int comboCount = ui->comboBox->count();
    if(comboCount < keyLength)
    {
        for(int i = comboCount; i < keyLength; i++)
            ui->comboBox->insertItem(i, QString::number(i+1)+".");
    }
    else if(comboCount > keyLength)
    {
        for(int i = comboCount-1; i >= keyLength; i--)
            ui->comboBox->removeItem(i);
    }

    QString key;
    ui->txtKey->setText(key.fill('A', keyLength));

    if(keyLength <= 0)
    {
        QList<float> dict;
        ui->frequencyChart->setDict(dict);
        return;
    }

    ui->comboBox->setCurrentIndex(0);
    setSubDict(0);
}

void VigenereCipherTab::setSubDict(int idx)
{
    if(idx < 0) return;
    mSubString = "";
    for(int i = idx; i < mEncryptText.length(); i+=ui->spinBox->value())
    {
            mSubString.append(mEncryptText[i]);
    }
    QList<float> dict = Cipher::getFrequencyAnalysis(mSubString);
    ui->frequencyChart->setDict(dict);
    int shift = -1*(ui->txtKey->text().at(idx).toAscii()-65);
    ui->frequencyChart->setShift(shift);
    ui->horizontalSlider->setValue(shift);
}

void VigenereCipherTab::setSubShift(int shift)
{
    ui->frequencyChart->setShift(shift);
    QString key = ui->txtKey->text();
    key[ui->comboBox->currentIndex()] = -1*shift+65;
    ui->txtKey->setText(key);
}

void VigenereCipherTab::decryptText()
{
    if(ui->txtKey->text().length() == 0) return;
    QString dText = Cipher::vigenereDecrypt(mEncryptText, ui->txtKey->text());
    emit decryptedText(dText);
}

VigenereCipherTab::~VigenereCipherTab()
{
    delete ui;
}
