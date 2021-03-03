#ifndef SYMPTOM_H
#define SYMPTOM_H

#include <QtWidgets/QWidget>
#include <QString>
#include <QPushButton>

class QGroupBox;

class Symptom: public QWidget
{
    Q_OBJECT

public:
    Symptom(QWidget *parent = 0);


signals:
    void sendSymp(QString msg); //connects buttons pressed to mainwindow

};


#endif
