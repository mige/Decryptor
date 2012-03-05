#ifndef CAESARCIPHERTAB_H
#define CAESARCIPHERTAB_H

#include <QWidget>

namespace Ui {
class CaesarCipherTab;
}

class CaesarCipherTab : public QWidget
{
    Q_OBJECT
    
public:
    explicit CaesarCipherTab(QWidget *parent = 0);
    ~CaesarCipherTab();

public slots:
    void setEncryptText(QString text);
    void decryptText();
    void editInfoText(int shift);

signals:
    void decryptedText(QString text);
    
private:
    Ui::CaesarCipherTab *ui;
    QString mEncryptText;
};

#endif // CAESARCIPHERTAB_H
