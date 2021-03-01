#ifndef SYMPTOM_H
#define SYMPTOM_H

#include <QWidget>
#include <QString>

class QGroupBox;

class Symptom: public QWidget
{
    Q_OBJECT

public:
    Symptom(QWidget *parent = 0);

private slots:
    // void updateSymptom(QString);

signals:
    void freqChanged(int freqVal);
    void volChanged(int volVal);
    void symptomChosen(int v);
    void sendMsg(QString msg);
};


#endif
