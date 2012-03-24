#ifndef VIGENERECIPHERTAB_H
#define VIGENERECIPHERTAB_H

#include <QWidget>

namespace Ui {
class VigenereCipherTab;
}

class VigenereCipherTab : public QWidget
{
    Q_OBJECT
    
public:
    explicit VigenereCipherTab(QWidget *parent = 0);
    ~VigenereCipherTab();

public slots:
    void setEncryptText(QString text);
    void decryptText();
    void splitText(int keyLength);
    void setSubDict(int idx);
    void setSubShift(int shift);

signals:
    void decryptedText(QString text);
    
private:
    Ui::VigenereCipherTab *ui;
    QString mEncryptText;
    QString mSubString;
};

#endif // VIGENERECIPHERTAB_H
