#include "affineciphertab.h"
#include "ui_affineciphertab.h"

#include <cipher.h>

AffineCipherTab::AffineCipherTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::AffineCipherTab)
{
    ui->setupUi(this);
    connect(ui->horizontalSlider, SIGNAL(valueChanged(int)), ui->frequencyChart, SLOT(setShift(int)));
    connect(ui->btnFindParameters, SIGNAL(clicked()), this, SLOT(findParameters()));
}

void AffineCipherTab::findParameters()
{

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
