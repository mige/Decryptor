#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <cipher.h>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->encryptTextEdit, SIGNAL(textChanged()), this, SLOT(normalizeText()));
    connect(ui->caesarCipherTab, SIGNAL(decryptedText(QString)), ui->decrpytTextEdit, SLOT(setPlainText(QString)));
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
}

MainWindow::~MainWindow()
{
    delete ui;
}
