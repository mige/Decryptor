#include "cipher.h"

#include <QDebug>

QString Cipher::caesarDecrypt(QString text, int shift)
{
    text = normalize(text);
    for(int i = 0; i < text.length(); i++)
    {
        int ch = text[i].toAscii();
        ch -= shift;
        if(ch < 65) ch += 26;
        text[i] = ch;
    }
    return text;
}

QList<float> Cipher::getFrequencyAnalysis(QString text)
{
    text = normalize(text);
    int cnt = text.length();
    QList<float> ret;

    for(int i = 0; i <= 25; i++)
        ret << 0.0;

    for(int i = 0; i < cnt; i++)
    {
        int ch = text.at(i).toAscii();
        ch-=65;
        ret[ch]++;
    }

    for(int i = 0; i <= 25; i++)
        ret[i] = ret[i]/cnt;

    return ret;
}

/**
 *
 */
QString Cipher::normalize(QString text)
{
    text = text.toUpper();
    for(int i = 0; i < text.length(); i++)
    {
        char ch = text.at(i).toAscii();
        if(ch < 65 || ch > 90)
        {
            text.remove(i, 1);
            i--;
        }
    }
    return text;
}
