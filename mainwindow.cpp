#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <cipher.h>
#include <QDebug>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->actionVypo_tat_index_koincidence, SIGNAL(triggered()), this, SLOT(countIndexOfCoincidence()));
    connect(ui->encryptTextEdit, SIGNAL(textChanged()), this, SLOT(normalizeText()));
    connect(ui->caesarCipherTab, SIGNAL(decryptedText(QString)), ui->decrpytTextEdit, SLOT(setPlainText(QString)));
    connect(ui->affineCipherTab, SIGNAL(decryptedText(QString)), ui->decrpytTextEdit, SLOT(setPlainText(QString)));
    connect(ui->substitutionWithKeyTab, SIGNAL(decryptedText(QString)), ui->decrpytTextEdit, SLOT(setPlainText(QString)));
}

void MainWindow::normalizeText()
{
    QString text = ui->encryptTextEdit->toPlainText();
    QString normText = Cipher::normalize(text);
    if(text != normText)
    {
        ui->encryptTextEdit->setPlainText(normText);
        ui->encryptTextEdit->moveCursor(QTextCursor::End);
    }
    ui->caesarCipherTab->setEncryptText(normText);
    ui->affineCipherTab->setEncryptText(normText);
    ui->substitutionWithKeyTab->setEncryptText(normText);
}

void MainWindow::countIndexOfCoincidence()
{
    float ic = Cipher::indexOfCoincidence(ui->encryptTextEdit->toPlainText());
    QMessageBox::information(this, tr("Decryptor - Index koincidence"), tr("Index koincidence: <b>")+QString::number(ic)+tr("</b><br />Pokud IC ~ 0.06689, tak se může jednat o monoalfabetickou substituci."));
}

MainWindow::~MainWindow()
{
    delete ui;
}
