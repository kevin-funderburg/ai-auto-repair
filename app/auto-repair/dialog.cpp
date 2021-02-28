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
int f, i, j, s, k;      //loop vars


#define MESSAGE \
    Dialog::tr("<p>Message boxes have a caption, a text, " \
               "and any number of buttons, each with standard or custom texts." \
               "<p>Click a button to close the message box. Pressing the Esc button " \
               "will activate the detected escape button (if any).")

Dialog::Dialog(QWidget *parent)
    : QWidget(parent)
{
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

void Dialog::setInteger()
{
    bool ok;
    int i = QInputDialog::getInt(this, tr("QInputDialog::getInteger()"),
                                 tr("Percentage:"), 25, 0, 100, 1, &ok);
    if (ok)
        integerLabel->setText(tr("%1%").arg(i));
}

void Dialog::setDouble()
{
    bool ok;
    double d = QInputDialog::getDouble(this, tr("QInputDialog::getDouble()"),
                                       tr("Amount:"), 37.56, -10000, 10000, 2, &ok);
    if (ok)
        doubleLabel->setText(QString("$%1").arg(d));
}

void Dialog::setItem()
{
    QStringList items;
    items << tr("WHEEL") << tr("SQUEAK") << tr("ENGINE") 
          << tr("AC") << tr("BATTERY") << tr("TIRE") 
          << tr("SMOKE") << tr("ACCELERATION");

    bool ok;
    QString item = QInputDialog::getItem(this, tr("Choose the symptom occurring."),
                                         tr("Symptom:"), items, 0, false, &ok);
    if (ok && !item.isEmpty())
        itemLabel->setText(item);
        instantiate(item);
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

void Dialog::setColor()
{
    QColor color;
    if (native->isChecked())
        color = QColorDialog::getColor(Qt::green, this);
    else
        color = QColorDialog::getColor(Qt::green, this, "Select Color", QColorDialog::DontUseNativeDialog);

    if (color.isValid()) {
        colorLabel->setText(color.name());
        colorLabel->setPalette(QPalette(color));
        colorLabel->setAutoFillBackground(true);
    }
}

void Dialog::setFont()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, QFont(fontLabel->text()), this);
    if (ok) {
        fontLabel->setText(font.key());
        fontLabel->setFont(font);
    }
}

void Dialog::setExistingDirectory()
{
    QFileDialog::Options options = QFileDialog::DontResolveSymlinks | QFileDialog::ShowDirsOnly;
    if (!native->isChecked())
        options |= QFileDialog::DontUseNativeDialog;
    QString directory = QFileDialog::getExistingDirectory(this,
                                tr("QFileDialog::getExistingDirectory()"),
                                directoryLabel->text(),
                                options);
    if (!directory.isEmpty())
        directoryLabel->setText(directory);
}

void Dialog::setOpenFileName()
{
    QFileDialog::Options options;
    if (!native->isChecked())
        options |= QFileDialog::DontUseNativeDialog;
    QString selectedFilter;
    QString fileName = QFileDialog::getOpenFileName(this,
                                tr("QFileDialog::getOpenFileName()"),
                                openFileNameLabel->text(),
                                tr("All Files (*);;Text Files (*.txt)"),
                                &selectedFilter,
                                options);
    if (!fileName.isEmpty())
        openFileNameLabel->setText(fileName);
}

void Dialog::setOpenFileNames()
{
    QFileDialog::Options options;
    if (!native->isChecked())
        options |= QFileDialog::DontUseNativeDialog;
    QString selectedFilter;
    QStringList files = QFileDialog::getOpenFileNames(
                                this, tr("QFileDialog::getOpenFileNames()"),
                                openFilesPath,
                                tr("All Files (*);;Text Files (*.txt)"),
                                &selectedFilter,
                                options);
    if (files.count()) {
        openFilesPath = files[0];
        openFileNamesLabel->setText(QString("[%1]").arg(files.join(", ")));
    }
}

void Dialog::setSaveFileName()
{
    QFileDialog::Options options;
    if (!native->isChecked())
        options |= QFileDialog::DontUseNativeDialog;
    QString selectedFilter;
    QString fileName = QFileDialog::getSaveFileName(this,
                                tr("QFileDialog::getSaveFileName()"),
                                saveFileNameLabel->text(),
                                tr("All Files (*);;Text Files (*.txt)"),
                                &selectedFilter,
                                options);
    if (!fileName.isEmpty())
        saveFileNameLabel->setText(fileName);
}

void Dialog::criticalMessage()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::critical(this, tr("QMessageBox::critical()"),
                                    MESSAGE,
                                    QMessageBox::Abort | QMessageBox::Retry | QMessageBox::Ignore);
    if (reply == QMessageBox::Abort)
        criticalLabel->setText(tr("Abort"));
    else if (reply == QMessageBox::Retry)
        criticalLabel->setText(tr("Retry"));
    else
        criticalLabel->setText(tr("Ignore"));
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
               "If the checkbox is checked (as it is by default), "
               "the shown message will be shown again, "
               "but if the user unchecks the box the message "
               "will not appear again if QErrorMessage::showMessage() "
               "is called with the same message."));
    errorLabel->setText(tr("If the box is unchecked, the message "
                           "won't appear again."));
}


void Dialog::init()
{
    sp = INSTANTIATE_LIST_SIZE;
    for (i = 1; i < INSTANTIATE_LIST_SIZE; i++)
    {
        conclt[i] = "";
        varlt[i] = "";
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

    // printf("*** CAR FAULT LIST ***\n");
    // for (i = 1; i < 41; i++)
    //     printf("CAR FAULT %d %s\n", i, conclt[i]);
    
    // printf("HIT RETURN TO CONTINUE");
    // gets(buff);
    
    // printf("*** CHECKING POINTS LIST *\n");
    
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

    // for(i = 1; i < 26; i++)
    //     printf("CHECKING POINTS %d %s\n", i, varlt[i]);
    
    // printf("HIT RETURN KEY TO CONTINUE");
    
    // gets(buff);
    
    // printf("*** CHECKING POINTS BY CAR FAULTS ***\n");
    
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

    // for(i = 1; i < CONC_LIST_SIZE; i++)
    // {
    //     printf("** CAR FAULTS %d\n", i);
        
    //     for(j = 1; j < 7; j++)
    //     {
    //         k = 6 * (i - 1) + j;
    //         printf("CHECKING POINTS %d  %s\n", j, clvarlt[k]);
    //     }
        
        
    //     if (i == 20)
    //     {
    //         printf("HIT RETURN KEY TO CONTINUE");
    //         gets(buff);
    //     }
    // }

}


void Dialog::instantiate(QString varble)
{
    QString msg;
    QMessageBox::StandardButton reply;
    i = 1;
    while((varble != varlt[i]) && (i < 26))
        i = i + 1;
    
    if((varble == varlt[i]) && (instlt[i] != 1))
    {
        instlt[i] = 1;
        switch (i)
        {
            case 1: msg = "Are the wheels balanced?";
                reply = QMessageBox::question(this, tr("Additional Information"),
                                        msg,
                                        QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
                if (reply == QMessageBox::Yes)
                    WHL_BAL == "YES";
                else if (reply == QMessageBox::No)
                    WHL_BAL == "NO";
                else
                    questionLabel->setText(tr("Cancel"));
                break;
            // case 2: msg = "Is there a squeak under the bonnet?";
            //     gets(SQK_UB);
            //     break;
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

    reply = QMessageBox::question(this, tr("Additional Information"),
                                    msg,
                                    QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
    if (reply == QMessageBox::Yes)
        questionLabel->setText(tr("Yes"));
    else if (reply == QMessageBox::No)
        questionLabel->setText(tr("No"));
    else
        questionLabel->setText(tr("Cancel"));
}