#include <QtWidgets>

#include "diagnosis.h"

Diagnosis::Diagnosis(QWidget *parent)
    : QWidget(parent)
{
    init();

    int frameStyle = QFrame::Sunken | QFrame::Panel;

    itemLabel = new QLabel;
    itemLabel->setFrameStyle(frameStyle);

    repairLabel = new QLabel;
    repairLabel->setFrameStyle(frameStyle);
    QPushButton *repairButton = new QPushButton(tr("What to Repair"));

    native = new QCheckBox(this);
    native->setText("Use native file dialog.");
    native->setChecked(true);

    QGridLayout *layout = new QGridLayout;

    layout->addWidget(repairButton, 4, 0);
    layout->addWidget(repairLabel, 4, 1);
    layout->addWidget(native, 15, 0);

    setLayout(layout);
    setWindowTitle(tr("Fix Your Car!"));
}


void Diagnosis::init()
{
    qDebug() << "TRACE==>   initializing Diagnosis object";

    sp = INSTANTIATE_LIST_SIZE;
    result = "";

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

    qDebug() << "\n\n*** CAR FAULT LIST ***\n";
    for (i = 1; i < CONC_LIST_SIZE; i++)
        qDebug() << "CAR FAULT " << i << conclt[i];
    
    qDebug() << "\n\n*** CHECKING POINTS LIST";
    
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
    
    qDebug() << "\n\n*** CHECKING POINTS BY CAR FAULTS ***";
    
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


void Diagnosis::inference(QString varble)
{

    qDebug() << "TRACE==>   inference section of backward chaining...";

    f = 1;
    QString flt;
    do
    {

        itemLabel->setText(varble);
        determine_member_concl_list(varble);
        
        if (sn != 0) 
            push_on_stack();

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
                if((EXST_SMK_CL == "BLUE") && (SMK_OCR == "ALL TIME") && 
                   (PCV_OK == "YES") && (TRBO_WRK == "YES"))
                    s = 1;
                break;
            case 21:
                if((EXST_SMK_CL == "BLUE") && (SMK_OCR == "ALL TIME") && 
                   (PCV_OK == "YES") && (TRBO_WRK == "NO"))
                    s = 1;
                break;
            case 22:
                if((EXST_SMK_CL == "BLUE") && (SMK_OCR == "ALL TIME") && 
                   (PCV_OK == "NO"))
                    s = 1;
                break;
            case 23:
                if((EXST_SMK_CL == "BLACK") && (FL_ODR_TLPIPE == "YES"))
                    s = 1;
                break;
            case 24:
                if((EXST_SMK_CL == "BLACK") && (FL_ODR_TLPIPE == "NO") && 
                   (DRTY_ARFLTR == "YES"))
                    s = 1;
                break;
            case 25:
                if((EXST_SMK_CL == "BLACK") && (FL_ODR_TLPIPE == "NO") && 
                   (DRTY_ARFLTR == "NO") && (CRBN_BUILDUP == "YES"))
                    s = 1;
                break;
            case 26:
                if((EXST_SMK_CL == "BLACK") && (FL_ODR_TLPIPE == "NO") && 
                   (DRTY_ARFLTR == "NO") && (CRBN_BUILDUP == "NO"))
                    s = 1;
                break;
            case 27:
                if((ENG_PROB == "NOISE") && (PREIGN_NOISE == "YES") && 
                   (SCND_SPT_NOISE == "YES"))
                    s = 1;
                break;
            case 28:
                if((ENG_PROB == "NOISE") && (PREIGN_NOISE == "YES") && 
                   (SCND_SPT_NOISE == "NO") && (CMPR_RATIO > 14))
                    s = 1;
                break;
            case 29:
                if((ENG_PROB == "NOISE") && (PREIGN_NOISE == "YES") && 
                   (SCND_SPT_NOISE == "NO") && (CMPR_RATIO <= 14))
                    s = 1;
                break;
            case 30:
                if((ENG_PROB == "NOISE") && (PREIGN_NOISE == "NO") && 
                   (NOISE_SOUND == "CLICKING"))
                    s = 1;
                break;
            case 31:
                if((ENG_PROB == "NOISE") && (PREIGN_NOISE == "NO") && 
                   (NOISE_SOUND == "KNOCKING"))
                    s = 1;
                break;
            case 32:
                if((ENG_PROB == "NOISE") && (PREIGN_NOISE == "NO") &&
                   (NOISE_SOUND == "BELL"))
                    s = 1;
                break;
            case 33:
                if((ENG_PROB == "NOISE") && (PREIGN_NOISE == "NO") && 
                   (NOISE_SOUND == "RUMBLING"))
                    s = 1;
                break;
            case 34:
                if((ENG_PROB == "NOISE") && (PREIGN_NOISE == "NO") && 
                   (NOISE_SOUND == "RATTLING"))
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
                if((ARFLW_SNSR_MLFNCTN == "NO") && (OX_SNSR_MLFNCTN == "NO") && 
                   (THRTL_SNSR_MLFNCTN == "YES"))
                    s = 1;
                break;
            case 38:
                if((ARFLW_SNSR_MLFNCTN == "NO") && (OX_SNSR_MLFNCTN == "NO") && 
                   (THRTL_SNSR_MLFNCTN == "NO") && (CLG_FL_FLTR == "YES"))
                    s = 1;
                break;
            case 39:
                if((ARFLW_SNSR_MLFNCTN == "NO") && (OX_SNSR_MLFNCTN == "NO") && 
                   (THRTL_SNSR_MLFNCTN == "NO") && (CLG_FL_FLTR == "NO") && 
                   (DRTY_ARFLTR == "YES"))
                    s = 1;
                break;
            case 40:
                if((ARFLW_SNSR_MLFNCTN == "NO") && (OX_SNSR_MLFNCTN == "NO") && 
                   (THRTL_SNSR_MLFNCTN == "NO") && (CLG_FL_FLTR == "NO") && 
                   (DRTY_ARFLTR == "NO"))
                    s = 1;
                break;
        }
        if( s != 1) {
            i = statsk[sp];
            varble = conclt[i];
            f = statsk[sp] + 1;
            determine_member_concl_list(varble);
            sp++;
        }
    } while((s != 1) && (sn !=0));

    switch (sn) 
    {
        case 1: FAULT = "YES";
            flt = "FAULTY_STEERING";
            break;
        case 2: FAULT = "YES";
            flt = "UNBALANCED_WHEELS";
            break;
        case 3: FAULT = "YES";
            flt = "SERPENTINE_BELT_SLIPPING";
            break;
        case 4: FAULT = "YES";
            flt = "FADED_BRAKE_PADS";
            break;
        case 5: FAULT = "YES";
            flt = "DUST_ON_DISKS/DRUMS";
            break;
        case 6: FAULT = "YES";
            flt = "FAULTY_THERMOSTAT";
            break;
        case 7: FAULT = "YES";
            flt = "COOLANT_LEAKING";
            break;
        case 8: FAULT = "YES";
            flt = "LOW_COOLANT_LEVEL";
            break;
        case 9: FAULT = "YES";
            flt = "AC_HOSE_LEAKING";
            break;
        case 10: FAULT = "YES";
            flt = "LOW_REFRIGERANT";
            break;
        case 11: FAULT = "YES";
            flt = "FAULTY_ALTERNATOR";
            break;
        case 12: FAULT = "YES";
            flt = "LOOSE_BATTERY_CONNECTION";
            break;
        case 13: FAULT = "YES";
            flt = "DEAD_BATTERY";
            break;
        case 14: FAULT = "YES";
            flt = "BROKEN_TIRE";
            break;
        case 15: FAULT = "YES";
            flt = "LOW_TIRE_PRESSURE";
            break;
        case 16: FAULT = "YES";
            flt = "COOLANT_LEAKING";
            break;
        case 17: FAULT = "YES";
            flt = "FAULTY_GASKET";
            break;
        case 18: FAULT = "YES";
            flt = "WORN_VALVE_SEALS";
            break;
        case 19: FAULT = "YES";
            flt = "WORN_PISTON_RING";
            break;
        case 20: FAULT = "YES";
            flt = "TRANSMISSION_FLUID_LOSS";
            break;
        case 21: FAULT = "YES";
            flt = "BLOWN_TURBO";
            break;
        case 22: FAULT = "YES";
            flt = "STUCK_PCV_VALVE";
            break;
        case 23: FAULT = "YES";
            flt = "MALFUNCTIONING_FUEL_INJECTOR";
            break;
        case 24: FAULT = "YES";
            flt = "CLOGGED_AIR_FILTER";
            break;
        case 25: FAULT = "YES";
            flt = "BLOCKED_INTAKE_MANIFOLD";
            break;
        case 26: FAULT = "YES";
            flt = "LOW_CYLINDER_COMPRESSION";
            break;
        case 27: FAULT = "YES";
            flt = "DIRTY_ENGINE_CYLINDER";
            break;
        case 28: FAULT = "YES";
            flt = "HIGH_COMPRESSION_RATIO";
            break;
        case 29: FAULT = "YES";
            flt = "ENGINE_COOLANT_SYSTEM_PROBLEM";
            break;
        case 30: FAULT = "YES";
            flt = "VALVE_AND_HYDRAULIC_LIFTER_PROBLEM";
            break;
        case 31: FAULT = "YES";
            flt = "PISTON_PIN_PROBLEM";
            break;
        case 32: FAULT = "YES";
            flt = "PISTON_SLAP_PROBLEM";
            break;
        case 33: FAULT = "YES";
            flt = "CRANKSHAFT_BEARING_PROBLEM";
            break;
        case 34: FAULT = "YES";
            flt = "LOOSE_TIMING_CHAIN";
            break;
        case 35: FAULT = "YES";
            flt = "MASS_AIR_FLOW_SENSOR_MALFUNCTION";
            break;
        case 36: FAULT = "YES";
            flt = "OXYGEN_SENSOR_PROBLEM";
            break;
        case 37: FAULT = "YES";
            flt = "THROTTLE_POSITION_SENSOR_PROBLEM";
            break;
        case 38: FAULT = "YES";
            flt = "CLOGGED_FUEL_FILTER";
            break;
        case 39: FAULT = "YES";
            flt = "CLOGGED_AIR_FILTER";
            break;
        case 40: FAULT = "YES";
            flt = "FAILING_OR_BROKEN_TIMING_BELT";
            break;
    }

    sp++;
    if(sp >= INSTANTIATE_LIST_SIZE) 
    {
        result = flt;
        qDebug() << "TRACE==>   diagnosis determined:" << result << ", now sending ui signal to determine repair";
        emit sendDiag(flt);     //send signal to indicate diagnosis was found
    } else {
        qDebug() << "*** CANNOT DETECT FAULT ***";
    }
}


bool Diagnosis::isInsantiated(QString var)
{

}

void Diagnosis::instantiate(QString varble)
{
    QString msg;
    i = 1;

    while((varble != varlt[i]) && (i < VAR_LIST_SIZE))
        i++;
    
    qDebug().nospace() << "TRACE==>     varlt[" << i << "]: " << varlt[i] << "\t\t" << "instlt[" << i <<"]: " << instlt[i];

    if((varble == varlt[i]) && (instlt[i] != 1))
    {
        instlt[i] = 1;
        switch (i)
        {
            case 1: WHL_BAL = yesOrNo("Are the wheels balanced?");
                break;
            case 2: SQK_UB = yesOrNo("Is there a squeak under the bonnet?");
                break;
            case 3: BRKPD_FD = yesOrNo("Are the brakepads faded?");
                break;
            case 4: {
                msg = "Is the engine problem noise or overheating?";
                qDebug() << "TRACE==>   " << msg;
                QMessageBox msgBox;
                msgBox.setText(msg);
                QPushButton *overheatButton = msgBox.addButton(tr("Overheating"), QMessageBox::ActionRole);
                QPushButton *noiseButton = msgBox.addButton(tr("Noise"), QMessageBox::ActionRole);
                QPushButton *cancelButton = msgBox.addButton(QMessageBox::Cancel);

                msgBox.exec();

                if (msgBox.clickedButton() == overheatButton)
                    ENG_PROB = "OVERHEAT";
                else if (msgBox.clickedButton() == noiseButton)
                    ENG_PROB = "NOISE";
                else
                    qDebug() << "Cancelling";
                }
                qDebug() << "TRACE==>   " << ENG_PROB;

                break;

            case 5: THRMST_FLT = yesOrNo("Is there a thermostat fault?");
                break;
            case 6: CLNT_LK = yesOrNo("Is the coolant leaking?");
                break;
            case 7: HOSE_LK = yesOrNo("Is the AC hose leaking?");
                break;
            case 8: BATT_NEW = yesOrNo("Is the batterey new?");
                break;
            case 9: {
                bool ok;
                msg = "Enter the value of load battery test in volts.";
                qDebug() << "TRACE==>   " << msg;
                double d = QInputDialog::getDouble(this, msg,
                                                   tr("Volts:"), 37.56, -10000, 10000, 2, &ok);
                BATT_LD_TST = d;
                qDebug() << "TRACE==>   " << BATT_LD_TST;
                break;
            }
			case 10: TIRE_LK = yesOrNo("Is there a puncture or leak in the tire?");
				break;
            case 11: {
                bool ok;
                msg = "Choose the color of the engine smoke.";
                QStringList items;
                items << tr("WHITE") << tr("BLUE") << tr("BLACK") ;
                qDebug() << "TRACE==>   " << msg;
                EXST_SMK_CL = QInputDialog::getItem(this, msg,
                                         tr("Smoke Color:"), items, 0, false, &ok);
                EXST_SMK_CL.toUpper();
                qDebug() << "TRACE==>   " << EXST_SMK_CL;
                break;
            }

            case 12: {
                QStringList items;
                items << tr("BEFORE") << tr("AFTER") << tr("ALL TIME") ;
                msg = "Choose when the smoke occurs: before, after or all the time.";
                qDebug() << "TRACE==>   " << msg;
                bool ok;
                SMK_OCR = QInputDialog::getItem(this, msg,
                                         tr("When Smoke Occurs:"), items, 0, false, &ok);
                SMK_OCR.toUpper();
                qDebug() << "TRACE==>   " << SMK_OCR;
                break;
            } 
            case 13: PCV_OK = yesOrNo("Is the PCV valve performing well?");
                break;
            case 14: TRBO_WRK = yesOrNo("Is the turbo performing well?");
                break;
            case 15: FL_ODR_TLPIPE = yesOrNo("Is there a foul odor coming from the tailpipe?");
                break;
            case 16: DRTY_ARFLTR = yesOrNo("Is the air filter dirty?");
                break;
            case 17: CRBN_BUILDUP = yesOrNo("Is there carbon buildup in the intake manifold?");
                break;
            case 18: PREIGN_NOISE = yesOrNo("Is there denotation/pre-ignition noise?");
                break;
            case 19: SCND_SPT_NOISE = yesOrNo("Is there a second spot noise?");
                break;
            case 20: {
                bool ok;
                msg = "Input a real number for the compression ratio.";
                qDebug() << "TRACE==>   " << msg;
                double d = QInputDialog::getDouble(this, msg,
                                                   tr("Compression Ratio:"), 37.56, -10000, 10000, 2, &ok);
                CMPR_RATIO = d;
                qDebug() << "TRACE==>   " << CMPR_RATIO;
                break;
            } 
            case 21: {
                msg = "Choose which kind of noise you heard.";
                qDebug() << "TRACE==>   " << msg;
                QStringList items;
                items << "CLICKING" << "KNOCKING" << "BELL"
                      << "RUMBLING" << "RATTLING";

                bool ok;
                NOISE_SOUND = QInputDialog::getItem(this, msg,
                                         tr("Noise:"), items, 0, false, &ok);
                NOISE_SOUND.toUpper();
                qDebug() << "TRACE==>   " << NOISE_SOUND;
                break;
            }
            case 22: ARFLW_SNSR_MLFNCTN = yesOrNo("Is the mass air flow sensor malfunctioning?");
                break;
            case 23: OX_SNSR_MLFNCTN = yesOrNo("Is the oxygen sensor malfunctioning?");
                break;
            case 24: THRTL_SNSR_MLFNCTN = yesOrNo("Is the throttle position sensor malfunctioning?");
                break;
            case 25: CLG_FL_FLTR = yesOrNo("Is the fuel filter dirty or clogged?");
                break;
        }
    }

}


void Diagnosis::push_on_stack()
{
    sp--;
    statsk[sp] = sn;
    clausk[sp] = 1;
}


void Diagnosis::determine_member_concl_list(QString varble) 
{
    sn = 0;
    i = f;
    while(varble != conclt[i] && (i < CONC_LIST_SIZE))
        i++;
    if (varble == conclt[i])
        sn = i;
}


QString Diagnosis::yesOrNo(QString msg)
{
    qDebug() << "TRACE==>   " << msg;
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("Additional Information"), msg,
                                    QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
    if (reply == QMessageBox::Yes) {
        qDebug() << "TRACE==>   YES";
        return "YES";
    }
    else if (reply == QMessageBox::No) {
        qDebug() << "TRACE==>   NO";
        return "NO";
    }
    else
        return "Cancel";
}
