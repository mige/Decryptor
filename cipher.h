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
    static QString vigenereDecrypt(QString text, QString key);
    static QList<float> getFrequencyAnalysis(QString text);
    static QString normalize(QString text);
    static int inverse(int n, int mod);
    static int gcd(int a, int b);
    static float indexOfCoincidence(QString text);
    static float friedmannTest(QString text);
};

#endif // CIPHER_H
