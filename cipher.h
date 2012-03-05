#ifndef CIPHER_H
#define CIPHER_H

#include <QList>
#include <QString>

class Cipher
{
public:
    static QString caesarEncrypt(QString text, int shift);
    static QString caesarDecrypt(QString text, int shift);
    static QList<float> getFrequencyAnalysis(QString text);
    static QString normalize(QString text);
};

#endif // CIPHER_H
