#ifndef SUBSTITUTIONWITHKEY_H
#define SUBSTITUTIONWITHKEY_H

#include <QWidget>
#include <QLabel>
#include <QLineEdit>

namespace Ui {
class SubstitutionWithKey;
}

class SubstitutionWithKey : public QWidget
{
    Q_OBJECT
    
public:
    explicit SubstitutionWithKey(QWidget *parent = 0);
    ~SubstitutionWithKey();

public slots:
    void setEncryptText(QString text);
    void decryptText();

signals:
    void decryptedText(QString text);

private:
    Ui::SubstitutionWithKey *ui;
    QString mEncryptText;
    QList<QLabel *> mSubstitutonLabel;
    QList<QLineEdit *> mSubstitutonLineEdit;
};

#endif // SUBSTITUTIONWITHKEY_H
