#ifndef SYMPTOM_H
#define SYMPTOM_H

#include <QWidget>
#include <QString>
#include <QPushButton>

class QGroupBox;

class Symptom: public QWidget
{
    Q_OBJECT

public:
    Symptom(QWidget *parent = 0);

// private slots:
    // void updateSymptom(QString);


signals:
    void sendSymp(QString msg);

// private:
//     QPushButton newButton(QString name, QString path);

};


#endif
