#ifndef AFFINECIPHERTAB_H
#define AFFINECIPHERTAB_H

#include <QWidget>

namespace Ui {
class AffineCipherTab;
}

class AffineCipherTab : public QWidget
{
    Q_OBJECT
    
public:
    explicit AffineCipherTab(QWidget *parent = 0);
    ~AffineCipherTab();

public slots:
    void setEncryptText(QString text);
    void findParameters();
    void decryptText();

signals:
    void decryptedText(QString text);

private:
    Ui::AffineCipherTab *ui;
    QString mEncryptText;
};

#endif // AFFINECIPHERTAB_H
