#include "affineciphertab.h"
#include "ui_affineciphertab.h"

#include <cipher.h>
#include <QMessageBox>

AffineCipherTab::AffineCipherTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AffineCipherTab)
{
    ui->setupUi(this);
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), ui->frequencyChart, SLOT(setShift(int)));
    connect(ui->btnFindParameters, SIGNAL(clicked()), this, SLOT(findParameters()));
    connect(ui->btnDecrypt, SIGNAL(clicked()), this, SLOT(decryptText()));
}

void AffineCipherTab::findParameters()
{
    int ex = ui->txtEX->text().at(0).toAscii()-65;
    int ey = ui->txtEY->text().at(0).toAscii()-65;
    int dx = ui->txtDX->text().at(0).toAscii()-65;
    int dy = ui->txtDY->text().at(0).toAscii()-65;
    if(ex < 0 || ex > 25 ||
       ey < 0 || ey > 25 ||
       dx < 0 || dx > 25 ||
       dy < 0 || dy > 25)
    {
        QMessageBox::warning(this, tr("Decryptor - Afinní šifra"), tr("Musíte vyplnit obě dvě rovnosti písmen."));
        return;
    }
    // x = a*y + b mod 26
    int x = ex-ey;
    int y = dx-dy;
    if(y < 0) y += 26;

    y = Cipher::inverse(y, 26);
    if(y == -1)
    {
        QMessageBox::warning(this, tr("Decryptor - Afinní šifra"), tr("Nelze najít inversi. Zkuste jiné porovnání."));
        return;
    }

    int a = x*y%26;
    if(a < 0) a += 26;
    int b = (ex-a*dx)%26;
    if(b < 0) b += 26;

    ui->spinBoxA->setValue(a);
    ui->spinBoxB->setValue(b);
}

void AffineCipherTab::decryptText()
{
    QString dText = Cipher::affineDecrypt(mEncryptText, ui->spinBoxA->value(), ui->spinBoxB->value());
    emit decryptedText(dText);
}

void AffineCipherTab::setEncryptText(QString text)
{
    mEncryptText = text;
    QList<float> dict = Cipher::getFrequencyAnalysis(text);
    ui->frequencyChart->setDict(dict);
}

AffineCipherTab::~AffineCipherTab()
{
    delete ui;
}
