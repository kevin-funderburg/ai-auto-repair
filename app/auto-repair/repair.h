#ifndef REPAIR_H
#define REPAIR_H

#include <string>
#include <QWidget>
#include <QDebug>
#include <QQueue>
#include <QMap>

// #include "diagnosis.h"

class QString;

enum printOptions {CLS_VAR_LIST, VAR_LIST, ALL};
class Repair
{

public:
    Repair(QString diag);
    QString getResult();
    void inference();

private slots:
    bool check_instantiation(QString key);
    void instantiate(QString key);
    void print_structures(printOptions option);
    void execute_then(int snum);
    bool rule_exists(int snum);
    void check_clauses(int snum);
    bool present(QString v, int snum);

private:

    static const int NUM_STATEMENTS = 38;
    static const int VAR_LST_SIZE = 1;
    static const int CLS_VAR_LIST_SIZE = NUM_STATEMENTS * VAR_LST_SIZE;

    QMap<QString, QString> varlt;           // variable list
    QQueue<QString> cnvarq;                 // conclusion variable queue
    QString clvarlt[CLS_VAR_LIST_SIZE];     // clause var list

    QString diagnosis;                      // fault detemined from backward chaining
    QString result;                         // repair 

};

#endif