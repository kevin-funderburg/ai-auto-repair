#include <QtGui>

#include "dialog.h"

#define CONC_LIST_SIZE 41
#define CLS_VAR_LIST_SIZE 240
#define VAR_LIST_SIZE 26
#define INSTANTIATE_LIST_SIZE 103

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

QString conclt[CONC_LIST_SIZE];         //conclusion list 
QString clvarlt[CLS_VAR_LIST_SIZE];     //clause variable list 
QString varlt[VAR_LIST_SIZE];           //variable list

int instlt[INSTANTIATE_LIST_SIZE];      //instantiated list
int statsk[INSTANTIATE_LIST_SIZE];      // statement stack 
int clausk[INSTANTIATE_LIST_SIZE];      // clause stack

int sp;                 //stack pointer
int sn;                 //statement number
int f, i, j, s, k;      //loop vars


#define MESSAGE \
    Dialog::tr("<p>Message boxes have a caption, a text = " \
               "and any number of buttons, each with standard or custom texts." \
               "<p>Click a button to close the message box. Pressing the Esc button " \
               "will activate the detected escape button (if any).")

Dialog::Dialog(QWidget *parent)
    : QWidget(parent)
{
    init();

    errorMessageDialog = new QErrorMessage(this);

    int frameStyle = QFrame::Sunken | QFrame::Panel;

    itemLabel = new QLabel;
    itemLabel->setFrameStyle(frameStyle);
    QPushButton *itemButton = new QPushButton(tr("Click to Choose the Symptom"));

    symptomLabel = new QLabel;
    symptomLabel->setFrameStyle(frameStyle);
    QPushButton *symptomButton = new QPushButton(tr("Click to Enter Symptom"));

    repairLabel = new QLabel;
    repairLabel->setFrameStyle(frameStyle);
    QPushButton *repairButton = new QPushButton(tr("What to Repair"));

    informationLabel = new QLabel;
    informationLabel->setFrameStyle(frameStyle);
    QPushButton *informationButton =
            new QPushButton(tr("QMessageBox::i&nformation()"));

    questionLabel = new QLabel;
    questionLabel->setFrameStyle(frameStyle);
    QPushButton *questionButton =
            new QPushButton(tr("QMessageBox::&question()"));

    warningLabel = new QLabel;
    warningLabel->setFrameStyle(frameStyle);
    QPushButton *warningButton = new QPushButton(tr("QMessageBox::&warning()"));

    errorLabel = new QLabel;
    errorLabel->setFrameStyle(frameStyle);
    QPushButton *errorButton =
            new QPushButton(tr("QErrorMessage::showM&essage()"));

    connect(itemButton, SIGNAL(clicked()), this, SLOT(setItem()));
    connect(symptomButton, SIGNAL(clicked()), this, SLOT(setText()));
    connect(repairButton, SIGNAL(clicked()), this, SLOT(setText()));
    connect(informationButton, SIGNAL(clicked()),
            this, SLOT(informationMessage()));
    connect(questionButton, SIGNAL(clicked()), this, SLOT(questionMessage()));
    connect(warningButton, SIGNAL(clicked()), this, SLOT(warningMessage()));
    connect(errorButton, SIGNAL(clicked()), this, SLOT(errorMessage()));

    native = new QCheckBox(this);
    native->setText("Use native file dialog.");
    native->setChecked(true);

    QGridLayout *layout = new QGridLayout;
    layout->setColumnStretch(1, 1);
    layout->setColumnMinimumWidth(1, 250);
    layout->addWidget(itemButton, 2, 0);
    layout->addWidget(itemLabel, 2, 1);
    layout->addWidget(symptomButton, 3, 0);
    layout->addWidget(symptomLabel, 3, 1);
    layout->addWidget(repairButton, 4, 0);
    layout->addWidget(repairLabel, 4, 1);

    layout->addWidget(informationButton, 11, 0);
    layout->addWidget(informationLabel, 11, 1);
    layout->addWidget(questionButton, 12, 0);
    layout->addWidget(questionLabel, 12, 1);
    layout->addWidget(warningButton, 13, 0);
    layout->addWidget(warningLabel, 13, 1);
    layout->addWidget(errorButton, 14, 0);
    layout->addWidget(errorLabel, 14, 1);
    layout->addWidget(native, 15, 0);
#if defined(Q_OS_SYMBIAN) || defined(Q_WS_MAEMO_5) || defined(Q_WS_SIMULATOR)
    QWidget *widget = new QWidget;
    widget->setLayout(layout);

    QScrollArea *scrollArea = new QScrollArea(this);
    scrollArea->setWidget(widget);

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(scrollArea);
    setLayout(mainLayout);
#else
    setLayout(layout);
#endif

    setWindowTitle(tr("Fix Your Car!"));
}


void Dialog::setItem()
{
    QString varble;                 //variable
    QStringList items;
    items << tr("WHEEL") << tr("SQUEAK") << tr("ENGINE") 
          << tr("AC") << tr("BATTERY") << tr("TIRE") 
          << tr("SMOKE") << tr("ACCELERATION");

    bool ok;
    varble = QInputDialog::getItem(this, tr("Choose the symptom occurring."),
                                         tr("Symptom:"), items, 0, false, &ok);
    if (ok && !varble.isEmpty())
    {
        f = 1;
        do
        {
            itemLabel->setText(varble);
            determine_member_concl_list(varble);
            
            if (sn != 0) push_on_stack();

            do
            {
                i = (statsk[sp] - 1) * 6 + clausk[sp];
                varble = clvarlt[i];
                if(varble != "") {
                    instantiate(varble);
                    clausk[sp] = clausk[sp] + 1;
                }
            } while(varble != "");

            sn = statsk[sp];
            s = 0;
            qDebug() << "==>BREAKPOINT==>\n";
            qDebug() << "sn:" << sn;
            switch (sn) 
            {
                case 1:
                    if(WHL_BAL == "YES")
                        s = 1;
                    break;
                case 2:
                    if(WHL_BAL == "NO")
                        s = 1;
                    break;
                case 3:
                    if(SQK_UB == "YES")
                        s = 1;
                    break;
                case 4:
                    if((SQK_UB == "NO") && (BRKPD_FD == "YES"))
                        s = 1;
                    break;
                case 5:
                    if((SQK_UB == "NO") && (BRKPD_FD == "NO"))
                        s = 1;
                    break;
                case 6:
                    if((ENG_PROB == "OVERHEAT") && (THRMST_FLT == "YES"))
                        s = 1;
                    break;
                case 7:
                    if((ENG_PROB == "OVERHEAT") && (THRMST_FLT == "NO") && (CLNT_LK == "YES"))
                        s = 1;
                    break;
                case 8:
                    if((ENG_PROB == "OVERHEAT") && (THRMST_FLT == "NO") && (CLNT_LK == "NO"))
                        s = 1;
                    break;
                case 9:
                    if(HOSE_LK == "YES")
                        s = 1;
                    break;
                case 10:
                    if(HOSE_LK == "NO")
                        s = 1;
                    break;
                case 11:
                    if(BATT_NEW == "YES")
                        s = 1;
                    break;
                case 12:
                    if((BATT_NEW == "NO") && (BATT_LD_TST > 12.45))
                        s = 1;
                    break;
                case 13:
                    if((BATT_NEW == "NO") && (BATT_LD_TST <= 12.45))
                        s = 1;
                    break;
                case 14:
                    if(TIRE_LK == "YES")
                        s = 1;
                    break;
                case 15:
                    if(TIRE_LK == "NO")
                        s = 1;
                    break;
                case 16:
                    if((EXST_SMK_CL == "WHITE") && (CLNT_LK == "YES"))
                        s = 1;
                    break;
                case 17:
                    if((EXST_SMK_CL == "WHITE") && (CLNT_LK == "NO"))
                        s = 1;
                    break;
                case 18:
                    if((EXST_SMK_CL == "BLUE") && (SMK_OCR == "BEFORE"))
                        s = 1;
                    break;
                case 19:
                    if((EXST_SMK_CL == "BLUE") && (SMK_OCR == "AFTER"))
                        s = 1;
                    break;
                case 20:
                    if((EXST_SMK_CL == "BLUE") && (SMK_OCR == "ALL TIME") && (PCV_OK == "YES") && (TRBO_WRK == "YES"))
                        s = 1;
                    break;
                case 21:
                    if((EXST_SMK_CL == "BLUE") && (SMK_OCR == "ALL TIME") && (PCV_OK == "YES") && (TRBO_WRK == "NO"))
                        s = 1;
                    break;
                case 22:
                    if((EXST_SMK_CL == "BLUE") && (SMK_OCR == "ALL TIME") && (PCV_OK == "NO"))
                        s = 1;
                    break;
                case 23:
                    if((EXST_SMK_CL == "BLACK") && (FL_ODR_TLPIPE == "YES"))
                        s = 1;
                    break;
                case 24:
                    if((EXST_SMK_CL == "BLACK") && (FL_ODR_TLPIPE == "NO") && (DRTY_ARFLTR == "YES"))
                        s = 1;
                    break;
                case 25:
                    if((EXST_SMK_CL == "BLACK") && (FL_ODR_TLPIPE == "NO") && (DRTY_ARFLTR == "NO") && (CRBN_BUILDUP == "YES"))
                        s = 1;
                    break;
                case 26:
                    if((EXST_SMK_CL == "BLACK") && (FL_ODR_TLPIPE == "NO") && (DRTY_ARFLTR == "NO") && (CRBN_BUILDUP == "NO"))
                        s = 1;
                    break;
                case 27:
                    if((ENG_PROB == "NOISE") && (PREIGN_NOISE == "YES") && (SCND_SPT_NOISE == "YES"))
                        s = 1;
                    break;
                case 28:
                    if((ENG_PROB == "NOISE") && (PREIGN_NOISE == "YES") && (SCND_SPT_NOISE == "NO") && (CMPR_RATIO > 14))
                        s = 1;
                    break;
                case 29:
                    if((ENG_PROB == "NOISE") && (PREIGN_NOISE == "YES") && (SCND_SPT_NOISE == "NO") && (CMPR_RATIO <= 14))
                        s = 1;
                    break;
                case 30:
                    if((ENG_PROB == "NOISE") && (PREIGN_NOISE == "NO") && (NOISE_SOUND == "CLICKING"))
                        s = 1;
                    break;
                case 31:
                    if((ENG_PROB == "NOISE") && (PREIGN_NOISE == "NO") && (NOISE_SOUND == "KNOCKING"))
                        s = 1;
                    break;
                case 32:
                    if((ENG_PROB == "NOISE") && (PREIGN_NOISE == "NO") && (NOISE_SOUND == "BELL"))
                        s = 1;
                    break;
                case 33:
                    if((ENG_PROB == "NOISE") && (PREIGN_NOISE == "NO") && (NOISE_SOUND == "RUMBLING"))
                        s = 1;
                    break;
                case 34:
                    if((ENG_PROB == "NOISE") && (PREIGN_NOISE == "NO") && (NOISE_SOUND == "RATTLING"))
                        s = 1;
                    break;
                case 35:
                    if(ARFLW_SNSR_MLFNCTN == "YES")
                        s = 1;
                    break;
                case 36:
                    if((ARFLW_SNSR_MLFNCTN == "NO") && (OX_SNSR_MLFNCTN == "YES"))
                        s = 1;
                    break;
                case 37:
                    if((ARFLW_SNSR_MLFNCTN == "NO") && (OX_SNSR_MLFNCTN == "NO") && (THRTL_SNSR_MLFNCTN == "YES"))
                        s = 1;
                    break;
                case 38:
                    if((ARFLW_SNSR_MLFNCTN == "NO") && (OX_SNSR_MLFNCTN == "NO") && (THRTL_SNSR_MLFNCTN == "NO") && (CLG_FL_FLTR == "YES"))
                        s = 1;
                    break;
                case 39:
                    if((ARFLW_SNSR_MLFNCTN == "NO") && (OX_SNSR_MLFNCTN == "NO") && (THRTL_SNSR_MLFNCTN == "NO") && (CLG_FL_FLTR == "NO") && (DRTY_ARFLTR == "YES"))
                        s = 1;
                    break;
                case 40:
                    if((ARFLW_SNSR_MLFNCTN == "NO") && (OX_SNSR_MLFNCTN == "NO") && (THRTL_SNSR_MLFNCTN == "NO") && (CLG_FL_FLTR == "NO") && (DRTY_ARFLTR == "NO"))
                        s = 1;
                    break;
            }
            if( s != 1) {
                i = statsk[sp];
                varble = conclt[i];
                f = statsk[sp] + 1;
                determine_member_concl_list(varble);
                sp = sp + 1;
            }
        } while((s != 1) && (sn !=0));

        switch (sn) 
        {
            case 1: FAULT = "YES";
                qDebug() << "FAULT = FAULTY STEERING";
                break;
            case 2: FAULT = "YES";
                qDebug() << "FAULT = UNBALANCED WHEELS";
                break;
            case 3: FAULT = "YES";
                qDebug() << "FAULT = SERPENTINE BELT SLIPPING";
                break;
            case 4: FAULT = "YES";
                qDebug() << "FAULT = FADED BRAKE PADS";
                break;
            case 5: FAULT = "YES";
                qDebug() << "FAULT = DUST ON DISKS/DRUMS";
                break;
            case 6: FAULT = "YES";
                qDebug() << "FAULT = FAULTY THERMOSTAT";
                break;
            case 7: FAULT = "YES";
                qDebug() << "FAULT = COOLANT LEAKING";
                break;
            case 8: FAULT = "YES";
                qDebug() << "FAULT = LOW COOLANT LEVEL";
                break;
            case 9: FAULT = "YES";
                qDebug() << "FAULT = AC HOSE LEAKING";
                break;
            case 10: FAULT = "YES";
                qDebug() << "FAULT = LOW REFRIGERANT";
                break;
            case 11: FAULT = "YES";
                qDebug() << "FAULT = FAULTY ALTERNATOR";
                break;
            case 12: FAULT = "YES";
                qDebug() << "FAULT = LOOSE BATTERY CONNECTION";
                break;
            case 13: FAULT = "YES";
                qDebug() << "FAULT = DEAD BATTERY";
                break;
            case 14: FAULT = "YES";
                qDebug() << "FAULT = BROKEN TIRE";
                break;
            case 15: FAULT = "YES";
                qDebug() << "FAULT = LOW TIRE PRESSURE";
                break;
            case 16: FAULT = "YES";
                qDebug() << "FAULT = COOLANT LEAKING";
                break;
            case 17: FAULT = "YES";
                qDebug() << "FAULT = FAULTY GASKET";
                break;
            case 18: FAULT = "YES";
                qDebug() << "FAULT = WORN VALVE SEALS";
                break;
            case 19: FAULT = "YES";
                qDebug() << "FAULT = WORN PISTON RING";
                break;
            case 20: FAULT = "YES";
                qDebug() << "FAULT = TRANSMISSION FLUID LOSS";
                break;
            case 21: FAULT = "YES";
                qDebug() << "FAULT = BLOWN TURBO";
                break;
            case 22: FAULT = "YES";
                qDebug() << "FAULT = STUCK PCV VALVE";
                break;
            case 23: FAULT = "YES";
                qDebug() << "FAULT = MALFUNCTIONING FUEL INJECTOR";
                break;
            case 24: FAULT = "YES";
                qDebug() << "FAULT = CLOGGED AIR FILTER";
                break;
            case 25: FAULT = "YES";
                qDebug() << "FAULT = BLOCKED INTAKE MANIFOLD";
                break;
            case 26: FAULT = "YES";
                qDebug() << "FAULT = LOW CYLINDER COMPRESSION";
                break;
            case 27: FAULT = "YES";
                qDebug() << "FAULT = DIRTY ENGINE CYLINDER";
                break;
            case 28: FAULT = "YES";
                qDebug() << "FAULT = HIGH COMPRESSION RATIO";
                break;
            case 29: FAULT = "YES";
                qDebug() << "FAULT = ENGINE COOLANT SYSTEM PROBLEM";
                break;
            case 30: FAULT = "YES";
                qDebug() << "FAULT = VALVE AND HYDRAULIC LIFTER PROBLEM";
                break;
            case 31: FAULT = "YES";
                qDebug() << "FAULT = PISTON PIN PROBLEM";
                break;
            case 32: FAULT = "YES";
                qDebug() << "FAULT = PISTON SLAP PROBLEM";
                break;
            case 33: FAULT = "YES";
                qDebug() << "FAULT = CRANKSHAFT BEARING PROBLEM";
                break;
            case 34: FAULT = "YES";
                qDebug() << "FAULT = LOOSE TIMING CHAIN";
                break;
            case 35: FAULT = "YES";
                qDebug() << "FAULT = MASS AIR FLOW SENSOR MALFUNCTION";
                break;
            case 36: FAULT = "YES";
                qDebug() << "FAULT = OXYGEN SENSOR PROBLEM";
                break;
            case 37: FAULT = "YES";
                qDebug() << "FAULT = THROTTLE POSITION SENSOR PROBLEM";
                break;
            case 38: FAULT = "YES";
                qDebug() << "FAULT = CLOGGED FUEL FILTER";
                break;
            case 39: FAULT = "YES";
                qDebug() << "FAULT = CLOGGED AIR FILTER";
                break;
            case 40: FAULT = "YES";
                qDebug() << "FAULT = FAILING OR BROKEN TIMING BELT";
                break;
        }
        sp++;
        if(sp >= INSTANTIATE_LIST_SIZE) 
            qDebug() << "*** SUCCESS ***";
        else 
            qDebug() << "*** CANNOT DETECT FAULT ***";
    }
}

void Dialog::setText()
{
    bool ok;
    QString text = QInputDialog::getText(this, tr("Enter Text Here"),
                                         tr("Symptom:"), QLineEdit::Normal,
                                         QDir::home().dirName(), &ok);
    if (ok && !text.isEmpty())
        symptomLabel->setText(text);
}

void Dialog::informationMessage()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::information(this, tr("QMessageBox::information()"), MESSAGE);
    if (reply == QMessageBox::Ok)
        informationLabel->setText(tr("OK"));
    else
        informationLabel->setText(tr("Escape"));
}

void Dialog::questionMessage()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("QMessageBox::question()"),
                                    MESSAGE,
                                    QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
    if (reply == QMessageBox::Yes)
        questionLabel->setText(tr("Yes"));
    else if (reply == QMessageBox::No)
        questionLabel->setText(tr("No"));
    else
        questionLabel->setText(tr("Cancel"));
}


void Dialog::warningMessage()
{
    QMessageBox msgBox(QMessageBox::Warning, tr("QMessageBox::warning()"),
                       MESSAGE, 0, this);
    msgBox.addButton(tr("Save &Again"), QMessageBox::AcceptRole);
    msgBox.addButton(tr("&Continue"), QMessageBox::RejectRole);
    if (msgBox.exec() == QMessageBox::AcceptRole)
        warningLabel->setText(tr("Save Again"));
    else
        warningLabel->setText(tr("Continue"));

}


void Dialog::errorMessage()
{
    errorMessageDialog->showMessage(
            tr("This dialog shows and remembers error messages. "
               "If the checkbox is checked (as it is by default) = "
               "the shown message will be shown again = "
               "but if the user unchecks the box the message "
               "will not appear again if QErrorMessage::showMessage() "
               "is called with the same message."));
    errorLabel->setText(tr("If the box is unchecked, the message "
                           "won't appear again."));
}


void Dialog::init()
{
    sp = INSTANTIATE_LIST_SIZE;


    for (i = 1; i < CONC_LIST_SIZE; i++)
        conclt[i] = "";
    for (i = 1; i < VAR_LIST_SIZE; i++)
        varlt[i] = "";
    for (i = 1; i < INSTANTIATE_LIST_SIZE; i++)
    {
        instlt[i] = 0;
        statsk[i] = 0;
        clausk[i] = 0;
    }
    for (i = 1; i < CLS_VAR_LIST_SIZE; i++)
        clvarlt[i] = "";

    conclt[1] = "WHEEL";
    conclt[2] = "WHEEL";
    conclt[3] = "SQUEAK";
    conclt[4] = "SQUEAK";
    conclt[5] = "SQUEAK";
    conclt[6] = "ENGINE";
    conclt[7] = "ENGINE";
    conclt[8] = "ENGINE";
    conclt[9] = "AC";
    conclt[10] = "AC";
    conclt[11] = "BATTERY";
    conclt[12] = "BATTERY";
    conclt[13] = "BATTERY";
    conclt[14] = "TIRE";
    conclt[15] = "TIRE";
    conclt[16] = "SMOKE";
    conclt[17] = "SMOKE";
    conclt[18] = "SMOKE";
    conclt[19] = "SMOKE";
    conclt[20] = "SMOKE";
    conclt[21] = "SMOKE";
    conclt[22] = "SMOKE";
    conclt[23] = "SMOKE";
    conclt[24] = "SMOKE";
    conclt[25] = "SMOKE";
    conclt[26] = "SMOKE";
    conclt[27] = "ENGINE";
    conclt[28] = "ENGINE";
    conclt[29] = "ENGINE";
    conclt[30] = "ENGINE";
    conclt[31] = "ENGINE";
    conclt[32] = "ENGINE";
    conclt[33] = "ENGINE";
    conclt[34] = "ENGINE";
    conclt[35] = "ACCELERATION";
    conclt[36] = "ACCELERATION";
    conclt[37] = "ACCELERATION";
    conclt[38] = "ACCELERATION";
    conclt[39] = "ACCELERATION";
    conclt[40] = "ACCELERATION";

    qDebug() << "*** CAR FAULT LIST ***\n";
    for (i = 1; i < 41; i++)
        qDebug() << "CAR FAULT " << i << conclt[i];
    
    // printf("HIT RETURN TO CONTINUE");
    // gets(buff);
    
    qDebug() << "*** CHECKING POINTS LIST";
    
    varlt[1] = "WHL_BAL";
    varlt[2] = "SQK_UB";
    varlt[3] = "BRKPD_FD";
    varlt[4] = "ENG_PROB";
    varlt[5] = "THRMST_FLT";
    varlt[6] = "CLNT_LK";
    varlt[7] = "HOSE_LK";
    varlt[8] = "BATT_NEW";
    varlt[9] = "BATT_LD_TST";
    varlt[10] = "TIRE_LK";
    varlt[11] = "EXST_SMK_CL";
    varlt[12] = "SMK_OCR";
    varlt[13] = "PCV_OK";
    varlt[14] = "TRBO_WRK";
    varlt[15] = "FL_ODR_TLPIPE";
    varlt[16] = "DRTY_ARFLTR";
    varlt[17] = "CRBN_BUILDUP";
    varlt[18] = "PREIGN_NOISE";
    varlt[19] = "SCND_SPT_NOISE";
    varlt[20] = "COMPR_RATIO";
    varlt[21] = "NOISE_SOUND";
    varlt[22] = "ARFLW_SNSR_MLFNCTN";
    varlt[23] = "OX_SNSR_MLFNCTN";
    varlt[24] = "THRTL_SNSR_MLFNCTN";
    varlt[25] = "CLG_FL_FLTR";

    for(i = 1; i < VAR_LIST_SIZE; i++)
        qDebug() << "CHECKING POINTS " << i << varlt[i];
    
    // printf("HIT RETURN KEY TO CONTINUE");
    
    // gets(buff);
    
    qDebug() << "*** CHECKING POINTS BY CAR FAULTS ***";
    
    clvarlt[1] = "WHL_BAL";
    clvarlt[7] = "WHL_BAL";
    clvarlt[13] = "SQK_UB";
    clvarlt[19] = "SQK_UB";
    clvarlt[20] = "BRKPD_FD";
    clvarlt[25] = "SQK_UB";
    clvarlt[26] = "BRKPD_FD";
    clvarlt[31] = "ENG_PROB";
    clvarlt[32] = "THRMST_FLT";
    clvarlt[37] = "ENG_PROB";
    clvarlt[38] = "THRMST_FLT";
    clvarlt[39] = "CLNT_LK";
    clvarlt[43] = "ENG_PROB";
    clvarlt[44] = "THRMST_FLT";
    clvarlt[45] = "CLNT_LK";
    clvarlt[49] = "HOSE_LK";
    clvarlt[55] = "HOSE_LK";
    clvarlt[61] = "BATT_NEW";
    clvarlt[67] = "BATT_NEW";
    clvarlt[68] = "BATT_LD_TST";
    clvarlt[73] = "BATT_NEW";
    clvarlt[74] = "BATT_LD_TST";
    clvarlt[79] = "TIRE_LK";
    clvarlt[85] = "TIRE_LK";
    clvarlt[91] = "EXST_SMK_CL";
    clvarlt[92] = "CLNT_LK";
    clvarlt[97] = "EXST_SMK_CL";
    clvarlt[98] = "CLNT_LK";
    clvarlt[103] = "EXST_SMK_CL";
    clvarlt[104] = "SMK_OCR";
    clvarlt[109] = "EXST_SMK_CL";
    clvarlt[110] = "SMK_OCR";
    clvarlt[115] = "EXST_SMK_CL";
    clvarlt[116] = "SMK_OCR";
    clvarlt[117] = "PCV_OK";
    clvarlt[118] = "TRBO_WRK";
    clvarlt[121] = "EXST_SMK_CL";
    clvarlt[122] = "SMK_OCR";
    clvarlt[123] = "PCV_OK";
    clvarlt[124] = "TRBO_WRK";
    clvarlt[127] = "EXST_SMK_CL";
    clvarlt[128] = "SMK_OCR";
    clvarlt[129] = "PCV_OK";
    clvarlt[133] = "EXST_SMK_CL";
    clvarlt[134] = "FL_ODR_TLPIPE";
    clvarlt[139] = "EXST_SMK_CL";
    clvarlt[140] = "FL_ODR_TLPIPE";
    clvarlt[141] = "DRTY_ARFLTR";
    clvarlt[145] = "EXST_SMK_CL";
    clvarlt[146] = "FL_ODR_TLPIPE";
    clvarlt[147] = "DRTY_ARFLTR";
    clvarlt[148] = "CRBN_BUILDUP";
    clvarlt[151] = "EXST_SMK_CL";
    clvarlt[152] = "FL_ODR_TLPIPE";
    clvarlt[153] = "DRTY_ARFLTR";
    clvarlt[154] = "CRBN_BUILDUP";
    clvarlt[157] = "ENG_PROB";
    clvarlt[158] = "PREIGN_NOISE";
    clvarlt[159] = "SCND_SPT_NOISE";
    clvarlt[163] = "ENG_PROB";
    clvarlt[164] = "PREIGN_NOISE";
    clvarlt[165] = "SCND_SPT_NOISE";
    clvarlt[166] = "COMPR_RATIO";
    clvarlt[169] = "ENG_PROB";
    clvarlt[170] = "PREIGN_NOISE";
    clvarlt[171] = "SCND_SPT_NOISE";
    clvarlt[172] = "COMPR_RATIO";
    clvarlt[175] = "ENG_PROB";
    clvarlt[176] = "PREIGN_NOISE";
    clvarlt[177] = "NOISE_SOUND";
    clvarlt[181] = "ENG_PROB";
    clvarlt[182] = "PREIGN_NOISE";
    clvarlt[183] = "NOISE_SOUND";
    clvarlt[187] = "ENG_PROB";
    clvarlt[188] = "PREIGN_NOISE";
    clvarlt[189] = "NOISE_SOUND";
    clvarlt[193] = "ENG_PROB";
    clvarlt[194] = "PREIGN_NOISE";
    clvarlt[195] = "NOISE_SOUND";
    clvarlt[199] = "ENG_PROB";
    clvarlt[200] = "PREIGN_NOISE";
    clvarlt[201] = "NOISE_SOUND";
    clvarlt[205] = "ARFLW_SNSR_MLFNCTN";
    clvarlt[211] = "ARFLW_SNSR_MLFNCTN";
    clvarlt[212] = "OX_SNSR_MLFNCTN";
    clvarlt[217] = "ARFLW_SNSR_MLFNCTN";
    clvarlt[218] = "OX_SNSR_MLFNCTN";
    clvarlt[219] = "THRTL_SNSR_MLFNCTN";
    clvarlt[223] = "ARFLW_SNSR_MLFNCTN";
    clvarlt[224] = "OX_SNSR_MLFNCTN";
    clvarlt[225] = "THRTL_SNSR_MLFNCTN";
    clvarlt[226] = "CLG_FL_FLTR";
    clvarlt[229] = "ARFLW_SNSR_MLFNCTN";
    clvarlt[230] = "OX_SNSR_MLFNCTN";
    clvarlt[231] = "THRTL_SNSR_MLFNCTN";
    clvarlt[232] = "CLG_FL_FLTR";
    clvarlt[233] = "DRTY_ARFLTR";
    clvarlt[235] = "ARFLW_SNSR_MLFNCTN";
    clvarlt[236] = "OX_SNSR_MLFNCTN";
    clvarlt[237] = "THRTL_SNSR_MLFNCTN";
    clvarlt[238] = "CLG_FL_FLTR";
    clvarlt[239] = "DRTY_ARFLTR";

    for(i = 1; i < CONC_LIST_SIZE; i++)
    {
        qDebug() << "** CAR FAULTS" << i;
        
        for(j = 1; j < 7; j++)
        {
            k = 6 * (i - 1) + j;
            qDebug() << "CHECKING POINTS" << j << clvarlt[k];
        }
    }

}


void Dialog::inference()
{

}


void Dialog::instantiate(QString varble)
{
    qDebug() << "*** Dialog::instantiate() ***";
    qDebug() << "varble:" << varble;
    QString msg;
    QMessageBox::StandardButton reply;
    i = 1;

    for (i=1; i < VAR_LIST_SIZE; i++)
    {
        qDebug() << varlt[i];
        if ((varble == varlt[i])) break;
    }
    if (i == VAR_LIST_SIZE) i--;
    // while((varble != varlt[i]) && (i < VAR_LIST_SIZE))
    // {
    //     qDebug() << i << varlt[i];
    //     i++;
    // }

    qDebug() << "i:" << i;
    qDebug() << "instlt[i]:" << instlt[i];
    qDebug() << "varlt[i]:" << varlt[i];

    if((varble == varlt[i]) && (instlt[i] != 1))
    {
        instlt[i] = 1;
        switch (i)
        {
            case 1: WHL_BAL = yesOrNo("Are the wheels balanced?");
                break;
            case 2: SQK_UB = yesOrNo("Is there a squeak under the bonnet?");
                break;
            // case 3: printf("INPUT YES OR NO FOR BRAKE PAD FADED? ");
            //     gets(BRKPD_FD);
            //     break;
            // case 4: printf("INPUT OVERHEAT OR NOISE FOR ENGINE PROBLEM? ");
            //     gets(ENG_PROB);
            //     break;
            // case 5: printf("INPUT YES OR NO FOR THERMOSTAT FAULT? ");
            //     gets(THRMST_FLT);
            //     break;
            // case 6: printf("INPUT YES OR NO FOR COOLANT LEAKING? ");
            //     gets(CLNT_LK);
            //     break;
            // case 7: printf("INPUT YES OR NO FOR AC HOSE LEAKING? ");
            //     gets(HOSE_LK);
            //     break;
            // case 8: printf("INPUT YES OR NO FOR NEW BATTERY? ");
            //     gets(BATT_NEW);
            //     break;
            // case 9: printf("INPUT A REAL NUMBER FOR BATTERY LOAD TEST IN VOLTS? ");
            //     scanf("%f", &BATT_LD_TST);
            //     getchar();
            //     break;
            // case 10: printf("INPUT YES OR NO FOR PUNCTURE OR LEAK IN THE TIRE? ");
            //     gets(TIRE_LK);
            //     break;
            // case 11: printf("INPUT WHITE OR BLUE OR BLACK FOR THE COLOR OF EXHAUST SMOKE? ");
            //     gets(EXST_SMK_CL);
            //     break;
            // case 12: printf("INPUT BEFORE OR AFTER OR ALL TIME FOR WHEN THE SMOKE OCCUR? ");
            //     gets(SMK_OCR);
            //     break;
            // case 13: printf("INPUT YES OR NO FOR WHETHER PCV VALVE WELL PERFORMING? ");
            //     gets(PCV_OK);
            //     break;
            // case 14: printf("INPUT YES OR NO FOR WHETHER TURBO WELL PERFORMING? ");
            //     gets(TRBO_WRK);
            //     break;
            // case 15: printf("INPUT YES OR NO FOR FOUL ODOR FROM TAILPIPE? ");
            //     gets(FL_ODR_TLPIPE);
            //     break;
            // case 16: printf("INPUT YES OR NO FOR DIRTY AIR FILTER? ");
            //     gets(DRTY_ARFLTR);
            //     break;
            // case 17: printf("INPUT YES OR NO FOR CARBON BUILDUP IN INTAKE MANIFOLD? ");
            //     gets(CRBN_BUILDUP);
            //     break;
            // case 18: printf("INPUT YES OR NO FOR DENOTATION/PRE-IGNITION NOISE? ");
            //     gets(PREIGN_NOISE);
            //     break;
            // case 19: printf("INPUT YES OR NO FOR SECOND SPOT NOISE? ");
            //     gets(SCND_SPT_NOISE);
            //     break;
            // case 20: printf("INPUT A REAL NUMBER FOR COMPRESSION RATIO? ");
            //     scanf("%f", &CMPR_RATIO);
            //     getchar();
            //     break;
            // case 21: printf("INPUT CLICKING OR KNOCKING OR BELL OR RUMBLING OR RATTLING FOR NOISE YOU HEARD? ");
            //     gets(NOISE_SOUND);
            //     break;
            // case 22: printf("INPUT YES OR NO FOR MALFUNCTIONED MASS AIR FLOW SENSOR? ");
            //     gets(ARFLW_SNSR_MLFNCTN);
            //     break;
            // case 23: printf("INPUT YES OR NO FOR MALFUNCTIONED OXYGEN SENSOR? ");
            //     gets(OX_SNSR_MLFNCTN);
            //     break;
            // case 24: printf("INPUT YES OR NO FOR MALFUNCTIONED THROTTLE POSITION SENSOR? ");
            //     gets(THRTL_SNSR_MLFNCTN);
            //     break;
            // case 25: printf("INPUT YES OR NO FOR DIRTY/CLOGGED FUEL FILTER? ");
            //     gets(CLG_FL_FLTR);
            //     break;
        }
    }



    // if (symptom == "WHEEL")
    //     msg = "Are the wheels balanced?";
}

void Dialog::push_on_stack()
{
    sp--;
    statsk[sp] = sn;
    clausk[sp] = 1;
}


void Dialog::determine_member_concl_list(QString varble) 
{
    qDebug() << "*** Dialog::determine_member_concl_list ***";
    sn = 0;
    i = f;
    while(varble != conclt[i] && (i < CONC_LIST_SIZE))
        i++;
    if (varble == conclt[i])
        sn = i;
    qDebug() << "sn:" << i;
}


QString Dialog::yesOrNo(QString msg)
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("Additional Information"),
                                    msg,
                                    QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
    if (reply == QMessageBox::Yes)
        return "YES";
    else if (reply == QMessageBox::No)
        return "NO";
    else
        return "Cancel";
}