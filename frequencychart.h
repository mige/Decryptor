#ifndef FREQUENCYCHART_H
#define FREQUENCYCHART_H

#include <QGraphicsView>

class FrequencyChart : public QWidget
{
    Q_OBJECT
public:
    explicit FrequencyChart(QWidget *parent = 0);
    void setDict(QList<float>);

    QSize minimumSizeHint() const;
    QSize sizeHint() const;

public slots:
    void setShift(int shift);

protected:
    void paintEvent(QPaintEvent *event);
    float findMax(QList<float> dict);

    QList<float> mEnglishDict;
    QList<float> mDict;
    int          mShift;
};

#endif // FREQUENCYCHART_H
