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
    
private:
    Ui::VigenereCipherTab *ui;
};

#endif // VIGENERECIPHERTAB_H
