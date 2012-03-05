#include "frequencychart.h"
#include <QDebug>

FrequencyChart::FrequencyChart(QWidget *parent) :
    QWidget(parent)
{
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);

    mEnglishDict << 0.082 << 0.015 << 0.028 << 0.043 << 0.127 << 0.022 << 0.02 << 0.061
                 << 0.07 << 0.002 << 0.008 << 0.04 << 0.024 << 0.067 << 0.075 << 0.049
                 << 0.001 << 0.06 << 0.063 << 0.091 << 0.028 << 0.01 << 0.024 << 0.002
                 << 0.02 << 0.001;
    mShift = 0;
}

QSize FrequencyChart::minimumSizeHint() const
{
    return QSize(500, 200);
}

QSize FrequencyChart::sizeHint() const
{
    return QSize(800, 400);
}

void FrequencyChart::setDict(QList<float> dict)
{
    mDict = dict;
    //mShift = 0;
    repaint();
}

void FrequencyChart::setShift(int shift)
{
    mShift = shift;
    repaint();
}

float FrequencyChart::findMax(QList<float> dict)
{
    float ret = 0;
    for(int i = 0; i < dict.length(); i++)
        if(ret < dict[i]) ret = dict[i];
    return ret;
}

void FrequencyChart::paintEvent(QPaintEvent *event)
{
    int width = this->width();
    int height = this->height();
//    QPen pen(Qt::black, 1);
    QBrush brush(Qt::SolidPattern);
    QPainter painter(this);
    painter.setPen(Qt::black);
    painter.setBrush(brush);

    painter.drawLine(QPoint(10, 10), QPoint(10, height-40)); // |
    painter.drawLine(QPoint(10, height-40), QPoint(width-10, height-40)); // __

    float leap = (width-20)/26.0;
    float max = findMax(mEnglishDict);
    if(mDict.length() != 0)
    {
        float max2 = findMax(mDict);
        if(max2 > max) max = max2;
    }
    for(int i = 0; i <= 25; i++)
    {
        float x = 10+leap*(i+1)-leap/2;
        painter.setPen(Qt::black);
        painter.drawLine(QPoint(x, height-40), QPoint(x, height-35));
        brush.setColor(Qt::blue);
        painter.setPen(Qt::blue);
        painter.drawText(x-3, height-22, QChar(i+65));
        painter.setBrush(brush);

        float barHeightEng = (height-50)*(1/(max/mEnglishDict[i]));

        if(mDict.length() != 0)
        {
            painter.drawRect(x-7, 10+height-50-barHeightEng, 6, barHeightEng);
            brush.setColor(Qt::red);
            painter.setPen(Qt::red);
            painter.setBrush(brush);
            int idx = (i-mShift)%26;
            if(idx < 0) idx = 26+idx;
            if(mDict[idx] > 0)
            {
                float barHeight = (height-50)*(1/(max/mDict[idx]));
                painter.drawRect(x+1, 10+height-50-barHeight, 6, barHeight);
            }
            painter.drawText(x-3, height-8, QChar(idx+65));
        }
        else
            painter.drawRect(x-3, 10+height-50-barHeightEng, 6, barHeightEng);
    }
}
