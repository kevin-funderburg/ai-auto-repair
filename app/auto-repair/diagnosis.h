#ifndef DIAGNOSIS_H
#define DIAGNOSIS_H

#include <string>
#include <QWidget>
#include <QDebug>
#include <QQueue>
#include <QMap>

class QCheckBox;
class QLabel;
class QErrorMessage;
class QString;
class QGroupBox;

class Diagnosis : public QWidget
{
    Q_OBJECT

public:
    Diagnosis(QWidget *parent = 0);
    void inference(QString varble);

private slots:
    void init();
    void instantiate(QString symptom);
    void push_on_stack();
    void determine_member_concl_list(QString varble);
    QString yesOrNo(QString msg);

signals:
    void sendDiag(QString msg);

private:

    static const int CONC_LIST_SIZE = 41;
    static const int CLS_VAR_LIST_SIZE = 240;
    static const int VAR_LIST_SIZE = 26;
    static const int INSTANTIATE_LIST_SIZE = 103;

    QString conclt[CONC_LIST_SIZE];         //conclusion list 
    QString clvarlt[CLS_VAR_LIST_SIZE];     //clause variable list 
    QString varlt[VAR_LIST_SIZE];           //variable list

    int instlt[INSTANTIATE_LIST_SIZE];      //instantiated list
    int statsk[INSTANTIATE_LIST_SIZE];      // statement stack 
    int clausk[INSTANTIATE_LIST_SIZE];      // clause stack

    QString WHL_BAL;                //wheel balanced
    QString SQK_UB;                 //squeak under bonnet
    QString BRKPD_FD;               //break pad faded
    QString ENG_PROB;               //engine problem
    QString THRMST_FLT;             //thermostat fault
    QString CLNT_LK;                //coolant leak
    QString HOSE_LK;                //AC hose leak
    QString BATT_NEW;               //battery new
    QString TIRE_LK;                //tire leak
    QString EXST_SMK_CL;            //smoke color
    QString SMK_OCR;                //smoke occur
    QString PCV_OK;                 //pcv valve ok
    QString TRBO_WRK;               //turbo works well
    QString FL_ODR_TLPIPE;          //foul odor from tailpipe
    QString DRTY_ARFLTR;            //dirty air filter
    QString CRBN_BUILDUP;           //carbon buildup
    QString PREIGN_NOISE;           //denotation, preignition noise
    QString SCND_SPT_NOISE;         //second spot noise
    QString NOISE_SOUND;            //noise sound like    
    QString ARFLW_SNSR_MLFNCTN;     //air flow sensor malfunctioned
    QString OX_SNSR_MLFNCTN;        //oxygen sensor malfunctioned
    QString THRTL_SNSR_MLFNCTN;     //throttle position sensor malfunctioned
    QString CLG_FL_FLTR;            //clogged fuel filter
    QString FAULT;                  //fault
    float BATT_LD_TST;              //battery load test (higher than 12.45 volt)
    float CMPR_RATIO;               //compression ratio (over 14)

    int sp;                         //stack pointer
    int sn;                         //statement number
    int f, i, j, s, k;              //loop vars

    QString result;                 //diagnosis result

    QCheckBox *native;
    QLabel *itemLabel;
    QLabel *symptomLabel;
    QLabel *repairLabel;
    QLabel *errorLabel;
    QErrorMessage *errorMessageDialog;
};

#endif