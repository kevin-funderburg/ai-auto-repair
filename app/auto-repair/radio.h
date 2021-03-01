#ifndef RADIO_H
#define RADIO_H

#include <QWidget>
#include <QString>

class QGroupBox;

class Radio: public QWidget
{
    Q_OBJECT

public:
    Radio(QWidget *parent = 0);

private slots:
    // void updateSymptom(QString);

signals:
    void freqChanged(int freqVal);
    void volChanged(int volVal);
    void symptomChosen(int v);
    void sendMsg(QString msg);
};


#endif
