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

QString Cipher::affineDecrypt(QString text, int a, int b)
{
    text = normalize(text);
    int invA = inverse(a, 26);

    for(int i = 0; i < text.length(); i++)
    {
        int ch = text[i].toAscii()-65;
        ch = ((ch-b)*invA)%26;
        if(ch < 0) ch += 26;
        ch += 65;
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

/**
 * Modular multiplicative inverse
 */
int Cipher::inverse(int n, int mod)
{
    if(n > mod) n =  n%mod;

    // coefficients
    int c0 = 0;
    int c1 = 1;

    int prev = mod;
    int inv;

    while(n != 0)
    {
        int t = prev/n;
        int tmp = n;
        n = prev%n;
        prev = tmp;

        inv = c0-c1*t;
        c0 = c1;
        c1 = inv;

        if(n == 1)
        {
            inv = inv%mod;
            if(inv < 0) inv += mod;
            return inv;
        }
    }

    return -1; // invalid inverse
}

int Cipher::gcd(int a, int b)
{
    if(a < 1 || b < 1) return -1;
    while(b != 0)
    {
        int tmp = a;
        a = b;
        b = tmp % a;
    }
    return a;
}

//0,0586844809866393
float Cipher::indexOfCoincidence(QString text)
{
    text = normalize(text);
    int cnt = text.length();
    float ic;
    QList<int> countChar;
    float sum = 0.0;

    for(int i = 0; i <= 25; i++)
        countChar << 0;

    for(int i = 0; i < cnt; i++)
    {
        int ch = text.at(i).toAscii();
        ch-=65;
        countChar[ch]++;
    }

    for(int i = 0; i <= 25; i++)
        sum += countChar[i]*(countChar[i]-1);

    ic = sum/(cnt*(cnt-1));

    return ic;
}
