#include "vigenereciphertab.h"
#include "ui_vigenereciphertab.h"

VigenereCipherTab::VigenereCipherTab(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::VigenereCipherTab)
{
    ui->setupUi(this);
}

VigenereCipherTab::~VigenereCipherTab()
{
    delete ui;
}
