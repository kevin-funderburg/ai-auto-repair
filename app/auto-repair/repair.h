#ifndef REPAIR_H
#define REPAIR_H


#include <string>
#include <QWidget>
#include <QDebug>
#include <QQueue>
#include <QMap>


class Repair : public QWidget
{
   Q_OBJECT

public:
    Repair(QWidget *parent = 0);

private slots:
    void inference();
    void search(QString var);
    bool check_instantiation(QString key);
    void instantiate(QString key, QString value);
    void print_structures(void);
    QString yesOrNo(QString msg);

private:

    static const int CLS_VAR_LIST_SIZE = 38;
    static const int VAR_LST_SIZE = 1;

    QMap<QString, QString> varlt;           // variable list
    QQueue<QString> cnvarq;                 // conclusion variable queue
    QString clvarlt[CLS_VAR_LIST_SIZE];     // clause var list          //variable list

    QString v;           // variable 
    QString fault;       // fault - to be considered our condition variable?
    QString repair;      // repair 

    int sp;                         //stack pointer
    int sn;                         //statement number
    int f, i, j, s, k;              //loop vars

    QCheckBox *native;
    QLabel *itemLabel;
    QLabel *symptomLabel;
    QLabel *repairLabel;
    QLabel *errorLabel;
    QErrorMessage *errorMessageDialog;
};

#endif