#include "substitutionwithkey.h"
#include "ui_substitutionwithkey.h"

#include <cipher.h>
#include <QDebug>

SubstitutionWithKey::SubstitutionWithKey(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SubstitutionWithKey)
{
    ui->setupUi(this);

    for(int i = 0; i < 26; i++)
    {
        mSubstitutonLabel.append(new QLabel(QString(i+65)+"="));
        mSubstitutonLineEdit.append(new QLineEdit());
        mSubstitutonLineEdit.at(i)->setInputMask(">a;_");
    }

    for(int i = 0; i < 9; i++)
    {
        ui->substitutionLayout->addWidget(mSubstitutonLabel[i], i, 0);
        ui->substitutionLayout->addWidget(mSubstitutonLineEdit[i], i, 1);

        ui->substitutionLayout->addWidget(mSubstitutonLabel[i+9], i, 2);
        ui->substitutionLayout->addWidget(mSubstitutonLineEdit[i+9], i, 3);

        if(i+18 < 26)
        {
            ui->substitutionLayout->addWidget(mSubstitutonLabel[i+18], i, 4);
            ui->substitutionLayout->addWidget(mSubstitutonLineEdit[i+18], i, 5);
        }

        //ui->substitutionLayout->addRow(mSubstitutonLabel[i], mSubstitutonLineEdit[i]);
    }

    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), ui->frequencyChart, SLOT(setShift(int)));
    connect(ui->btnDecrypt, SIGNAL(clicked()), this, SLOT(decryptText()));
}

void SubstitutionWithKey::setEncryptText(QString text)
{
    mEncryptText = text;
    QList<float> dict = Cipher::getFrequencyAnalysis(text);
    ui->frequencyChart->setDict(dict);
}

void SubstitutionWithKey::decryptText()
{
    QString decryptedTextString;

    for(int i = 0; i < mEncryptText.length(); i++)
    {
        int idx = mEncryptText[i].toAscii()-65;
        QString ch = mSubstitutonLineEdit[idx]->text() == "" ? "_" : mSubstitutonLineEdit[idx]->text();
        decryptedTextString.append(ch);
    }
    emit decryptedText(decryptedTextString);
}

SubstitutionWithKey::~SubstitutionWithKey()
{
    delete ui;
}
