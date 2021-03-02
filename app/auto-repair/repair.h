#ifndef REPAIR_H
#define REPAIR_H


#include <string>
#include <QWidget>
#include <QDebug>
#include <QQueue>
#include <QMap>


class QCheckBox;
class QLabel;
class QErrorMessage;
class QString;

class Repair : public QWidget
{
   Q_OBJECT

public:
    Repair(QWidget *parent = 0);

private slots:
    void init();
    bool check_instantiation(QString key);
    QString instantiate(QString key);
    void print_structures(int option);
    void execute_then(int snum);
    bool check_rule(int snum);
    void check_clauses(int snum);
    bool present(QString v, int snum);
    void inference();
    // void search(QString var);
    // QString yesOrNo(QString msg);

private:

    static const int NUM_STATEMENTS = 38;
    static const int VAR_LST_SIZE = 1;
    static const int CLS_VAR_LIST_SIZE = NUM_STATEMENTS * VAR_LST_SIZE;

    QMap<QString, QString> varlt;           // variable list
    QQueue<QString> cnvarq;                 // conclusion variable queue
    QString clvarlt[CLS_VAR_LIST_SIZE];     // clause var list          //variable list

    QString v;           // variable 
    QString fault;       // fault - to be considered our condition variable?
    QString repair;      // repair 

    int i, j;            //loop vars

    QCheckBox *native;
    QLabel *itemLabel;
    QLabel *symptomLabel;
    QLabel *repairLabel;
    QLabel *errorLabel;
    QErrorMessage *errorMessageDialog;
};

#endif