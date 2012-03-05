#ifndef CIPHER_H
#define CIPHER_H

#include <QList>
#include <QString>

class Cipher
{
public:
    static QString caesarEncrypt(QString text, int shift);
    static QString caesarDecrypt(QString text, int shift);
    static QString affineDecrypt(QString text, int a, int b);
    static QList<float> getFrequencyAnalysis(QString text);
    static QString normalize(QString text);
    static int inverse(int n, int mod);
};

#endif // CIPHER_H
