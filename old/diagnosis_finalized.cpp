# include <iostream>
# include <string>
using namespace std;

void backward_init(char conclt[41][13], char varlt[26][20], int instlt[], int statsk[], int clausk[], char clvarlt[103][20], int offset[]);
int determine_member_concl_list(int f, char varble[20], char conclt[41][13]);
int push_on_stack(int sn, int sp, int statsk[], int clausk[]);
void backward_instantiate(char varble[20], char varlt[26][20], int instlt[], char WHL_BAL[4], char SQK_UB[4], char BRKPD_FD[4], char ENG_PROB[10], char THRMST_FLT[4], char CLNT_LK[4], char HOSE_LK[4], char BATT_NEW[4], char TIRE_LK[4], char EXST_SMK_CL[6], char SMK_OCR[15], char PCV_OK[4], char TRBO_WRK[4], char FL_ODR_TLPIPE[4], char DRTY_ARFLTR[4], char CRBN_BUILDUP[4], char PREIGN_NOISE[4], char SCND_SPT_NOISE[4], char NOISE_SOUND[40], char ARFLW_SNSR_MLFNCTN[4], char OX_SNSR_MLFNCTN[4], char THRTL_SNSR_MLFNCTN[4], char CLG_FL_FLTR[4], float BATT_LD_TST, float CMPR_RATIO);

int main()
{
    char conclt[41][13], varlt[26][20], clvarlt[103][20], varble[20];
    //char buff[3];
    char /*fault*/ FAULT[4];
    int offset[41] = {0, 1, 2, 3, 5, 7, 9, 12, 15, 16, 17, 18, 20, 22, 23, 24, 26, 28, 30, 32, 36, 40, 43, 45, 48, 52, 56, 59, 63, 67, 70, 73, 76, 79, 82, 83, 85, 88, 92, 97, 102};
    int sn, f, s, idx, sp;
    int statsk[103], clausk[103], instlt[103];
    char /*wheel balanced*/ WHL_BAL[4];
    char /*squeak sound under bonnet*/ SQK_UB[4], /*brake pad faded*/ BRKPD_FD[4];
    char /*engine problem*/ ENG_PROB[10], /*thermostat fault*/ THRMST_FLT[4], /*coolant leaking*/ CLNT_LK[4];
    char /*AC hose leak*/ HOSE_LK[4];
    char /*battery new*/ BATT_NEW[4];
    char /*tire leak*/ TIRE_LK[4];
    char /*smoke color*/ EXST_SMK_CL[6], /*smoke occur*/ SMK_OCR[15], /*pcv valve ok*/ PCV_OK[4], /*turbo works well*/ TRBO_WRK[4], /*foul odor from tailpipe*/ FL_ODR_TLPIPE[4], /*dirty air filter*/ DRTY_ARFLTR[4], /*carbon buildup*/ CRBN_BUILDUP[4];
    char /*denotation, preignition noise*/ PREIGN_NOISE[4], /*second spot noise*/ SCND_SPT_NOISE[4], /*noise sound like*/ NOISE_SOUND[40];
    char /*air flow sensor malfunctioned*/ ARFLW_SNSR_MLFNCTN[4], /*oxygen sensor malfunctioned*/ OX_SNSR_MLFNCTN[4], /*throttle position sensor malfunctioned*/ THRTL_SNSR_MLFNCTN[4], /* clogged fuel filter*/ CLG_FL_FLTR[4];
    float /*battery load test (higher than 12.45 volt)*/ BATT_LD_TST, /*compression ratio (over 14)*/ CMPR_RATIO;
    
    /***** initialization section ******/
    sp = 103;
    backward_init(conclt, varlt, instlt, statsk, clausk, clvarlt, offset);
    
    /****** inference section *****/
    cout << "** ENTER THE SYMPTOM? (PLEASE CHOOSE FROM WHEEL, SQUEAK, ENGINE, AC, BATTERY, TIRE, SMOKE, OR ACCELERATION)" << endl;
    cin.getline(varble, sizeof varble);
    
    f = 1;
    BATT_LD_TST = 0;
    CMPR_RATIO = 0;
    
    do
    {
        sn = determine_member_concl_list(f, varble, conclt);
       
        if (sn != 0)
            sp = push_on_stack(sn, sp, statsk, clausk);
        
        do
        {
            idx = offset[statsk[sp] - 1] + clausk[sp];
            strcpy(varble, clvarlt[idx]);
            backward_instantiate(varble, varlt, instlt, WHL_BAL, SQK_UB, BRKPD_FD, ENG_PROB, THRMST_FLT, CLNT_LK, HOSE_LK, BATT_NEW, TIRE_LK, EXST_SMK_CL, SMK_OCR, PCV_OK, TRBO_WRK, FL_ODR_TLPIPE, DRTY_ARFLTR, CRBN_BUILDUP, PREIGN_NOISE, SCND_SPT_NOISE, NOISE_SOUND, ARFLW_SNSR_MLFNCTN, OX_SNSR_MLFNCTN, THRTL_SNSR_MLFNCTN, CLG_FL_FLTR, BATT_LD_TST, CMPR_RATIO);
            clausk[sp] = clausk[sp] + 1;
        } while(idx <= offset[statsk[sp]] - 1);
        
        sn = statsk[sp];
        s = 0;

        cout << "DEBUG     sn: " << sn << "   before\n";

        switch (sn) {
            case 1:
                if((strcmp(WHL_BAL, "YES") == 0) || (strcmp(WHL_BAL, "Y") == 0))
                    s = 1;
                break;
            case 2:
                if((strcmp(WHL_BAL, "NO") == 0) || (strcmp(WHL_BAL, "N") == 0))
                    s = 1;
                break;
            case 3:
                if((strcmp(SQK_UB, "YES") == 0) || (strcmp(SQK_UB, "Y") == 0))
                    s = 1;
                break;
            case 4:
                if(((strcmp(SQK_UB, "NO") == 0)|| (strcmp(SQK_UB, "N") == 0)) && ((strcmp(BRKPD_FD, "YES") == 0) || (strcmp(BRKPD_FD, "Y") == 0)))
                    s = 1;
                break;
            case 5:
                if(((strcmp(SQK_UB, "NO") == 0) || (strcmp(SQK_UB, "N") == 0)) && ((strcmp(BRKPD_FD, "NO") == 0) || (strcmp(BRKPD_FD, "N") == 0)))
                    s = 1;
                break;
            case 6:
                if((strcmp(ENG_PROB, "OVERHEAT") == 0) && ((strcmp(THRMST_FLT, "YES") == 0) || (strcmp(THRMST_FLT, "Y") == 0)))
                    s = 1;
                break;
            case 7:
                if((strcmp(ENG_PROB, "OVERHEAT") == 0) && ((strcmp(THRMST_FLT, "NO") == 0) || (strcmp(THRMST_FLT, "N") == 0)) && ((strcmp(CLNT_LK, "YES") == 0) || (strcmp(CLNT_LK, "Y") == 0)))
                    s = 1;
                break;
            case 8:
                if((strcmp(ENG_PROB, "OVERHEAT") == 0) && ((strcmp(THRMST_FLT, "NO") == 0) || (strcmp(THRMST_FLT, "N") == 0)) && ((strcmp(CLNT_LK, "NO") == 0) || (strcmp(CLNT_LK, "N") == 0)))
                    s = 1;
                break;
            case 9:
                if((strcmp(HOSE_LK, "YES") == 0) || (strcmp(HOSE_LK, "Y") == 0))
                    s = 1;
                break;
            case 10:
                if((strcmp(HOSE_LK, "NO") == 0) || (strcmp(HOSE_LK, "N") == 0))
                    s = 1;
                break;
            case 11:
                if((strcmp(BATT_NEW, "YES") == 0) || (strcmp(BATT_NEW, "Y") == 0))
                    s = 1;
                break;
            case 12:
                if(((strcmp(BATT_NEW, "NO") == 0) || (strcmp(BATT_NEW, "N") == 0)) && (BATT_LD_TST > 12.45))
                    s = 1;
                break;
            case 13:
                if(((strcmp(BATT_NEW, "NO") == 0) || (strcmp(BATT_NEW, "N") == 0)) && (BATT_LD_TST <= 12.45))
                    s = 1;
                break;
            case 14:
                if((strcmp(TIRE_LK, "YES") == 0) || (strcmp(TIRE_LK, "Y") == 0))
                    s = 1;
                break;
            case 15:
                if((strcmp(TIRE_LK, "NO") == 0) || (strcmp(TIRE_LK, "N") == 0))
                    s = 1;
                break;
            case 16:
                if((strcmp(EXST_SMK_CL, "WHITE") == 0) && ((strcmp(CLNT_LK, "YES") == 0)|| (strcmp(CLNT_LK, "Y") == 0)))
                    s = 1;
                break;
            case 17:
                if((strcmp(EXST_SMK_CL, "WHITE") == 0) && ((strcmp(CLNT_LK, "NO") == 0) || (strcmp(CLNT_LK, "N") == 0)))
                    s = 1;
                break;
            case 18:
                if((strcmp(EXST_SMK_CL, "BLUE") == 0) && (strcmp(SMK_OCR, "BEFORE") == 0))
                    s = 1;
                break;
            case 19:
                if((strcmp(EXST_SMK_CL, "BLUE") == 0) && (strcmp(SMK_OCR, "AFTER") == 0))
                    s = 1;
                break;
            case 20:
                if((strcmp(EXST_SMK_CL, "BLUE") == 0) && (strcmp(SMK_OCR, "ALL TIME") == 0) && ((strcmp(PCV_OK, "YES") == 0) || (strcmp(PCV_OK, "Y") == 0)) && ((strcmp(TRBO_WRK, "YES") == 0) || (strcmp(TRBO_WRK, "Y") == 0)))
                    s = 1;
                break;
            case 21:
                if((strcmp(EXST_SMK_CL, "BLUE") == 0) && (strcmp(SMK_OCR, "ALL TIME") == 0) && ((strcmp(PCV_OK, "YES") == 0) || (strcmp(PCV_OK, "Y") == 0)) && ((strcmp(TRBO_WRK, "NO") == 0) || (strcmp(TRBO_WRK, "N") == 0)))
                    s = 1;
                break;
            case 22:
                if((strcmp(EXST_SMK_CL, "BLUE") == 0) && (strcmp(SMK_OCR, "ALL TIME") == 0) && ((strcmp(PCV_OK, "NO") == 0) || (strcmp(PCV_OK, "N") == 0)))
                    s = 1;
                break;
            case 23:
                if((strcmp(EXST_SMK_CL, "BLACK") == 0) && ((strcmp(FL_ODR_TLPIPE, "YES") == 0) || (strcmp(FL_ODR_TLPIPE, "Y") == 0)))
                    s = 1;
                break;
            case 24:
                if((strcmp(EXST_SMK_CL, "BLACK") == 0) && ((strcmp(FL_ODR_TLPIPE, "NO") == 0) || (strcmp(FL_ODR_TLPIPE, "N") == 0)) && ((strcmp(DRTY_ARFLTR, "YES") == 0) || (strcmp(DRTY_ARFLTR, "Y") == 0)))
                    s = 1;
                break;
            case 25:
                if((strcmp(EXST_SMK_CL, "BLACK") == 0) && ((strcmp(FL_ODR_TLPIPE, "NO") == 0) || (strcmp(FL_ODR_TLPIPE, "N") == 0)) && ((strcmp(DRTY_ARFLTR, "NO") == 0) || (strcmp(DRTY_ARFLTR, "N") == 0)) && ((strcmp(CRBN_BUILDUP, "YES") == 0) || (strcmp(CRBN_BUILDUP, "Y") == 0)))
                    s = 1;
                break;
            case 26:
                if((strcmp(EXST_SMK_CL, "BLACK") == 0) && ((strcmp(FL_ODR_TLPIPE, "NO") == 0) || (strcmp(FL_ODR_TLPIPE, "N") == 0)) && ((strcmp(DRTY_ARFLTR, "NO") == 0) || (strcmp(DRTY_ARFLTR, "N") == 0)) && ((strcmp(CRBN_BUILDUP, "NO") == 0) || (strcmp(CRBN_BUILDUP, "N") == 0)))
                    s = 1;
                break;
            case 27:
                if((strcmp(ENG_PROB, "NOISE") == 0) && ((strcmp(PREIGN_NOISE, "YES") == 0) || (strcmp(PREIGN_NOISE, "Y") == 0)) && ((strcmp(SCND_SPT_NOISE, "YES") == 0) || (strcmp(SCND_SPT_NOISE, "Y") == 0)))
                    s = 1;
                break;
            case 28:
                if((strcmp(ENG_PROB, "NOISE") == 0) && ((strcmp(PREIGN_NOISE, "YES") == 0) || (strcmp(PREIGN_NOISE, "Y") == 0)) && ((strcmp(SCND_SPT_NOISE, "NO") == 0) || (strcmp(SCND_SPT_NOISE, "N") == 0)) && (CMPR_RATIO > 14))
                    s = 1;
                break;
            case 29:
                if((strcmp(ENG_PROB, "NOISE") == 0) && ((strcmp(PREIGN_NOISE, "YES") == 0) || (strcmp(PREIGN_NOISE, "Y") == 0)) && ((strcmp(SCND_SPT_NOISE, "NO") == 0) || (strcmp(SCND_SPT_NOISE, "N") == 0)) && (CMPR_RATIO <= 14))
                    s = 1;
                break;
            case 30:
                if((strcmp(ENG_PROB, "NOISE") == 0) && ((strcmp(PREIGN_NOISE, "NO") == 0) || (strcmp(PREIGN_NOISE, "N") == 0)) && (strcmp(NOISE_SOUND, "CLICKING") == 0))
                    s = 1;
                break;
            case 31:
                if((strcmp(ENG_PROB, "NOISE") == 0) && ((strcmp(PREIGN_NOISE, "NO") == 0) || (strcmp(PREIGN_NOISE, "N") == 0)) && (strcmp(NOISE_SOUND, "KNOCKING") == 0))
                    s = 1;
                break;
            case 32:
                if((strcmp(ENG_PROB, "NOISE") == 0) && ((strcmp(PREIGN_NOISE, "NO") == 0) || (strcmp(PREIGN_NOISE, "N") == 0)) && (strcmp(NOISE_SOUND, "BELL") == 0))
                    s = 1;
                break;
            case 33:
                if((strcmp(ENG_PROB, "NOISE") == 0) && ((strcmp(PREIGN_NOISE, "NO") == 0) || (strcmp(PREIGN_NOISE, "N") == 0)) && (strcmp(NOISE_SOUND, "RUMBLING") == 0))
                    s = 1;
                break;
            case 34:
                if((strcmp(ENG_PROB, "NOISE") == 0) && ((strcmp(PREIGN_NOISE, "NO") == 0) || (strcmp(PREIGN_NOISE, "N") == 0)) && (strcmp(NOISE_SOUND, "RATTLING") == 0))
                    s = 1;
                break;
            case 35:
                if(((strcmp(ARFLW_SNSR_MLFNCTN, "YES") == 0) || (strcmp(ARFLW_SNSR_MLFNCTN, "Y") == 0)))
                    s = 1;
                break;
            case 36:
                if(((strcmp(ARFLW_SNSR_MLFNCTN, "NO") == 0) || (strcmp(ARFLW_SNSR_MLFNCTN, "N") == 0)) && ((strcmp(OX_SNSR_MLFNCTN, "YES") == 0) || (strcmp(OX_SNSR_MLFNCTN, "Y") == 0)))
                    s = 1;
                break;
            case 37:
                if(((strcmp(ARFLW_SNSR_MLFNCTN, "NO") == 0) || (strcmp(ARFLW_SNSR_MLFNCTN, "N") == 0)) && ((strcmp(OX_SNSR_MLFNCTN, "NO") == 0) || (strcmp(OX_SNSR_MLFNCTN, "N") == 0)) && ((strcmp(THRTL_SNSR_MLFNCTN, "YES") == 0) || (strcmp(THRTL_SNSR_MLFNCTN, "Y") == 0)))
                    s = 1;
                break;
            case 38:
                if(((strcmp(ARFLW_SNSR_MLFNCTN, "NO") == 0) || (strcmp(ARFLW_SNSR_MLFNCTN, "N") == 0)) && ((strcmp(OX_SNSR_MLFNCTN, "NO") == 0) || (strcmp(OX_SNSR_MLFNCTN, "N") == 0)) && ((strcmp(THRTL_SNSR_MLFNCTN, "NO") == 0) || (strcmp(THRTL_SNSR_MLFNCTN, "N") == 0)) && ((strcmp(CLG_FL_FLTR, "YES") == 0) || (strcmp(CLG_FL_FLTR, "Y") == 0)))
                    s = 1;
                break;
            case 39:
                if(((strcmp(ARFLW_SNSR_MLFNCTN, "NO") == 0) || (strcmp(ARFLW_SNSR_MLFNCTN, "N") == 0)) && ((strcmp(OX_SNSR_MLFNCTN, "NO") == 0) || (strcmp(OX_SNSR_MLFNCTN, "N") == 0)) && ((strcmp(THRTL_SNSR_MLFNCTN, "NO") == 0) || (strcmp(THRTL_SNSR_MLFNCTN, "N") == 0)) && ((strcmp(CLG_FL_FLTR, "NO") == 0) || (strcmp(CLG_FL_FLTR, "N") == 0)) && ((strcmp(DRTY_ARFLTR, "YES") == 0) || (strcmp(DRTY_ARFLTR, "Y") == 0)))
                    s = 1;
                break;
            case 40:
                if(((strcmp(ARFLW_SNSR_MLFNCTN, "NO") == 0) || (strcmp(ARFLW_SNSR_MLFNCTN, "N") == 0)) && ((strcmp(OX_SNSR_MLFNCTN, "NO") == 0) || (strcmp(OX_SNSR_MLFNCTN, "N") == 0)) && ((strcmp(THRTL_SNSR_MLFNCTN, "NO") == 0) || (strcmp(THRTL_SNSR_MLFNCTN, "N") == 0)) && ((strcmp(CLG_FL_FLTR, "NO") == 0) || (strcmp(CLG_FL_FLTR, "N") == 0)) && ((strcmp(DRTY_ARFLTR, "NO") == 0) || (strcmp(DRTY_ARFLTR, "N") == 0)))
                    s = 1;
                break;
        }
        if( s != 1) {
            int i = statsk[sp];
            strcpy(varble, conclt[i]);
            f = statsk[sp] + 1;
            sn = determine_member_concl_list(f, varble, conclt);
            sp = sp + 1;
        }
    } while((s != 1) && (sn !=0));
    
    cout << "DEBUG     sn: " << sn << "   after\n";

    switch (sn) {
        case 1: strcpy(FAULT, "YES");
            cout << "FAULT = FAULTY STEERING" << endl;
            break;
        case 2: strcpy(FAULT, "YES");
            cout << "FAULT = UNBALANCED WHEELS" << endl;
            break;
        case 3: strcpy(FAULT, "YES");
            cout << "FAULT = SERPENTINE BELT SLIPPING" << endl;
            break;
        case 4: strcpy(FAULT, "YES");
            cout << "FAULT = FADED BRAKE PADS" << endl;
            break;
        case 5: strcpy(FAULT, "YES");
            cout << "FAULT = DUST ON DISKS/DRUMS" << endl;
            break;
        case 6: strcpy(FAULT, "YES");
            cout << "FAULT = FAULTY THERMOSTAT" << endl;
            break;
        case 7: strcpy(FAULT, "YES");
            cout << "FAULT = COOLANT LEAKING" << endl;
            break;
        case 8: strcpy(FAULT, "YES");
            cout << "FAULT = LOW COOLANT LEVEL" << endl;
            break;
        case 9: strcpy(FAULT, "YES");
            cout << "FAULT = AC HOSE LEAKING" << endl;
            break;
        case 10: strcpy(FAULT, "YES");
            cout << "FAULT = LOW REFRIGERANT" << endl;
            break;
        case 11: strcpy(FAULT, "YES");
            cout << "FAULT = FAULTY ALTERNATOR" << endl;
            break;
        case 12: strcpy(FAULT, "YES");
            cout << "FAULT = LOOSE BATTERY CONNECTION" << endl;
            break;
        case 13: strcpy(FAULT, "YES");
            cout << "FAULT = DEAD BATTERY" << endl;
            break;
        case 14: strcpy(FAULT, "YES");
            cout << "FAULT = BROKEN TIRE" << endl;
            break;
        case 15: strcpy(FAULT, "YES");
            cout << "FAULT = LOW TIRE PRESSURE" << endl;
            break;
        case 16: strcpy(FAULT, "YES");
            cout << "FAULT = COOLANT LEAKING" << endl;
            break;
        case 17: strcpy(FAULT, "YES");
            cout << "FAULT = FAULTY GASKET" << endl;
            break;
        case 18: strcpy(FAULT, "YES");
            cout << "FAULT = WORN VALVE SEALS" << endl;
            break;
        case 19: strcpy(FAULT, "YES");
            cout << "FAULT = WORN PISTON RING" << endl;
            break;
        case 20: strcpy(FAULT, "YES");
            cout << "FAULT = TRANSMISSION FLUID LOSS" << endl;
            break;
        case 21: strcpy(FAULT, "YES");
            cout << "FAULT = BLOWN TURBO" << endl;
            break;
        case 22: strcpy(FAULT, "YES");
            cout << "FAULT = STUCK PCV VALVE" << endl;
            break;
        case 23: strcpy(FAULT, "YES");
            cout << "FAULT = MALFUNCTIONING FUEL INJECTOR" << endl;
            break;
        case 24: strcpy(FAULT, "YES");
            cout << "FAULT = CLOGGED AIR FILTER" << endl;
            break;
        case 25: strcpy(FAULT, "YES");
            cout << "FAULT = BLOCKED INTAKE MANIFOLD" << endl;
            break;
        case 26: strcpy(FAULT, "YES");
            cout << "FAULT = LOW CYLINDER COMPRESSION" << endl;
            break;
        case 27: strcpy(FAULT, "YES");
            cout << "FAULT = DIRTY ENGINE CYLINDER" << endl;
            break;
        case 28: strcpy(FAULT, "YES");
            cout << "FAULT = HIGH COMPRESSION RATIO" << endl;
            break;
        case 29: strcpy(FAULT, "YES");
            cout << "FAULT = ENGINE COOLANT SYSTEM PROBLEM" << endl;
            break;
        case 30: strcpy(FAULT, "YES");
            cout << "FAULT = VALVE AND HYDRAULIC LIFTER PROBLEM" << endl;
            break;
        case 31: strcpy(FAULT, "YES");
            cout << "FAULT = PISTON PIN PROBLEM" << endl;
            break;
        case 32: strcpy(FAULT, "YES");
            cout << "FAULT = PISTON SLAP PROBLEM" << endl;
            break;
        case 33: strcpy(FAULT, "YES");
            cout << "FAULT = CRANKSHAFT BEARING PROBLEM" << endl;
            break;
        case 34: strcpy(FAULT, "YES");
            cout << "FAULT = LOOSE TIMING CHAIN" << endl;
            break;
        case 35: strcpy(FAULT, "YES");
            cout << "FAULT = MASS AIR FLOW SENSOR MALFUNCTION" << endl;
            break;
        case 36: strcpy(FAULT, "YES");
            cout << "FAULT = OXYGEN SENSOR PROBLEM" << endl;
            break;
        case 37: strcpy(FAULT, "YES");
            cout << "FAULT = THROTTLE POSITION SENSOR PROBLEM" << endl;
            break;
        case 38: strcpy(FAULT, "YES");
            cout << "FAULT = CLOGGED FUEL FILTER" << endl;
            break;
        case 39: strcpy(FAULT, "YES");
            cout << "FAULT = CLOGGED AIR FILTER" << endl;
            break;
        case 40: strcpy(FAULT, "YES");
            cout << "FAULT = FAILING OR BROKEN TIMING BELT" << endl;
            break;
        default:
            cout << "INVALID INPUT. PLEASE TRY AGAIN." << endl;
    }
    sp = sp + 1;
    if(sp >= 103) {
        cout << "*** SUCCESS ***" << endl;
        }
    else {
        cout << "*** CANNOT DETECT FAULT ***" << endl;
        }
}

void backward_init(char conclt[41][13], char varlt[26][20], int instlt[], int statsk[], int clausk[], char clvarlt[103][20], int offset[])
{
    char buff[3];
    
    for (int i = 1; i < 41; i++)
        strcpy(conclt[i], "");
    
    for (int i = 1; i < 26; i++)
        strcpy(varlt[i], "");
    
    for (int i = 1; i < 103; i++)
    {
        instlt[i] = 0;
        statsk[i] = 0;
        clausk[i] = 0;
        strcpy(clvarlt[i], "");
    }
    
    strcpy(conclt[1], "WHEEL");
    strcpy(conclt[2], "WHEEL");
    strcpy(conclt[3], "SQUEAK");
    strcpy(conclt[4], "SQUEAK");
    strcpy(conclt[5], "SQUEAK");
    strcpy(conclt[6], "ENGINE");
    strcpy(conclt[7], "ENGINE");
    strcpy(conclt[8], "ENGINE");
    strcpy(conclt[9], "AC");
    strcpy(conclt[10], "AC");
    strcpy(conclt[11], "BATTERY");
    strcpy(conclt[12], "BATTERY");
    strcpy(conclt[13], "BATTERY");
    strcpy(conclt[14], "TIRE");
    strcpy(conclt[15], "TIRE");
    strcpy(conclt[16], "SMOKE");
    strcpy(conclt[17], "SMOKE");
    strcpy(conclt[18], "SMOKE");
    strcpy(conclt[19], "SMOKE");
    strcpy(conclt[20], "SMOKE");
    strcpy(conclt[21], "SMOKE");
    strcpy(conclt[22], "SMOKE");
    strcpy(conclt[23], "SMOKE");
    strcpy(conclt[24], "SMOKE");
    strcpy(conclt[25], "SMOKE");
    strcpy(conclt[26], "SMOKE");
    strcpy(conclt[27], "ENGINE");
    strcpy(conclt[28], "ENGINE");
    strcpy(conclt[29], "ENGINE");
    strcpy(conclt[30], "ENGINE");
    strcpy(conclt[31], "ENGINE");
    strcpy(conclt[32], "ENGINE");
    strcpy(conclt[33], "ENGINE");
    strcpy(conclt[34], "ENGINE");
    strcpy(conclt[35], "ACCELERATION");
    strcpy(conclt[36], "ACCELERATION");
    strcpy(conclt[37], "ACCELERATION");
    strcpy(conclt[38], "ACCELERATION");
    strcpy(conclt[39], "ACCELERATION");
    strcpy(conclt[40], "ACCELERATION");
    
    cout << "*** CAR PROBLEM SYMPTOM LIST ***" << endl;
    
    for (int i = 1; i < 41; i++)
        cout << "SYMPTOM " << i << " " << conclt[i] << endl;
    
    cout << "HIT RETURN TO CONTINUE";
    cin.getline(buff, sizeof buff);
    
    cout << endl << "*** CHECKING POINTS LIST ***" << endl;
    
    strcpy(varlt[1], "WHL_BAL");
    strcpy(varlt[2], "SQK_UB");
    strcpy(varlt[3], "BRKPD_FD");
    strcpy(varlt[4], "ENG_PROB");
    strcpy(varlt[5], "THRMST_FLT");
    strcpy(varlt[6], "CLNT_LK");
    strcpy(varlt[7], "HOSE_LK");
    strcpy(varlt[8], "BATT_NEW");
    strcpy(varlt[9], "BATT_LD_TST");
    strcpy(varlt[10], "TIRE_LK");
    strcpy(varlt[11], "EXST_SMK_CL");
    strcpy(varlt[12], "SMK_OCR");
    strcpy(varlt[13], "PCV_OK");
    strcpy(varlt[14], "TRBO_WRK");
    strcpy(varlt[15], "FL_ODR_TLPIPE");
    strcpy(varlt[16], "DRTY_ARFLTR");
    strcpy(varlt[17], "CRBN_BUILDUP");
    strcpy(varlt[18], "PREIGN_NOISE");
    strcpy(varlt[19], "SCND_SPT_NOISE");
    strcpy(varlt[20], "COMPR_RATIO");
    strcpy(varlt[21], "NOISE_SOUND");
    strcpy(varlt[22], "ARFLW_SNSR_MLFNCTN");
    strcpy(varlt[23], "OX_SNSR_MLFNCTN");
    strcpy(varlt[24], "THRTL_SNSR_MLFNCTN");
    strcpy(varlt[25], "CLG_FL_FLTR");
    
    for(int i = 1; i < 26; i++)
        cout << "CHECKING POINTS " << i << " " << varlt[i] << endl;
    
    cout << "HIT RETURN KEY TO CONTINUE" << endl;
    
    cin.getline(buff, sizeof buff);;
    
    cout << endl << "*** CHECKING POINTS BY SYMPTOMS ***" << endl;
    
    strcpy(clvarlt[1], "WHL_BAL");
    strcpy(clvarlt[2], "WHL_BAL");
    strcpy(clvarlt[3], "SQK_UB");
    strcpy(clvarlt[4], "SQK_UB");
    strcpy(clvarlt[5], "BRKPD_FD");
    strcpy(clvarlt[6], "SQK_UB");
    strcpy(clvarlt[7], "BRKPD_FD");
    strcpy(clvarlt[8], "ENG_PROB");
    strcpy(clvarlt[9], "THRMST_FLT");
    strcpy(clvarlt[10], "ENG_PROB");
    strcpy(clvarlt[11], "THRMST_FLT");
    strcpy(clvarlt[12], "CLNT_LK");
    strcpy(clvarlt[13], "ENG_PROB");
    strcpy(clvarlt[14], "THRMST_FLT");
    strcpy(clvarlt[15], "CLNT_LK");
    strcpy(clvarlt[16], "HOSE_LK");
    strcpy(clvarlt[17], "HOSE_LK");
    strcpy(clvarlt[18], "BATT_NEW");
    strcpy(clvarlt[19], "BATT_NEW");
    strcpy(clvarlt[20], "BATT_LD_TST");
    strcpy(clvarlt[21], "BATT_NEW");
    strcpy(clvarlt[22], "BATT_LD_TST");
    strcpy(clvarlt[23], "TIRE_LK");
    strcpy(clvarlt[24], "TIRE_LK");
    strcpy(clvarlt[25], "EXST_SMK_CL");
    strcpy(clvarlt[26], "CLNT_LK");
    strcpy(clvarlt[27], "EXST_SMK_CL");
    strcpy(clvarlt[28], "CLNT_LK");
    strcpy(clvarlt[29], "EXST_SMK_CL");
    strcpy(clvarlt[30], "SMK_OCR");
    strcpy(clvarlt[31], "EXST_SMK_CL");
    strcpy(clvarlt[32], "SMK_OCR");
    strcpy(clvarlt[33], "EXST_SMK_CL");
    strcpy(clvarlt[34], "SMK_OCR");
    strcpy(clvarlt[35], "PCV_OK");
    strcpy(clvarlt[36], "TRBO_WRK");
    strcpy(clvarlt[37], "EXST_SMK_CL");
    strcpy(clvarlt[38], "SMK_OCR");
    strcpy(clvarlt[39], "PCV_OK");
    strcpy(clvarlt[40], "TRBO_WRK");
    strcpy(clvarlt[41], "EXST_SMK_CL");
    strcpy(clvarlt[42], "SMK_OCR");
    strcpy(clvarlt[43], "PCV_OK");
    strcpy(clvarlt[44], "EXST_SMK_CL");
    strcpy(clvarlt[45], "FL_ODR_TLPIPE");
    strcpy(clvarlt[46], "EXST_SMK_CL");
    strcpy(clvarlt[47], "FL_ODR_TLPIPE");
    strcpy(clvarlt[48], "DRTY_ARFLTR");
    strcpy(clvarlt[49], "EXST_SMK_CL");
    strcpy(clvarlt[50], "FL_ODR_TLPIPE");
    strcpy(clvarlt[51], "DRTY_ARFLTR");
    strcpy(clvarlt[52], "CRBN_BUILDUP");
    strcpy(clvarlt[53], "EXST_SMK_CL");
    strcpy(clvarlt[54], "FL_ODR_TLPIPE");
    strcpy(clvarlt[55], "DRTY_ARFLTR");
    strcpy(clvarlt[56], "CRBN_BUILDUP");
    strcpy(clvarlt[57], "ENG_PROB");
    strcpy(clvarlt[58], "PREIGN_NOISE");
    strcpy(clvarlt[59], "SCND_SPT_NOISE");
    strcpy(clvarlt[60], "ENG_PROB");
    strcpy(clvarlt[61], "PREIGN_NOISE");
    strcpy(clvarlt[62], "SCND_SPT_NOISE");
    strcpy(clvarlt[63], "COMPR_RATIO");
    strcpy(clvarlt[64], "ENG_PROB");
    strcpy(clvarlt[65], "PREIGN_NOISE");
    strcpy(clvarlt[66], "SCND_SPT_NOISE");
    strcpy(clvarlt[67], "COMPR_RATIO");
    strcpy(clvarlt[68], "ENG_PROB");
    strcpy(clvarlt[69], "PREIGN_NOISE");
    strcpy(clvarlt[70], "NOISE_SOUND");
    strcpy(clvarlt[71], "ENG_PROB");
    strcpy(clvarlt[72], "PREIGN_NOISE");
    strcpy(clvarlt[73], "NOISE_SOUND");
    strcpy(clvarlt[74], "ENG_PROB");
    strcpy(clvarlt[75], "PREIGN_NOISE");
    strcpy(clvarlt[76], "NOISE_SOUND");
    strcpy(clvarlt[77], "ENG_PROB");
    strcpy(clvarlt[78], "PREIGN_NOISE");
    strcpy(clvarlt[79], "NOISE_SOUND");
    strcpy(clvarlt[80], "ENG_PROB");
    strcpy(clvarlt[81], "PREIGN_NOISE");
    strcpy(clvarlt[82], "NOISE_SOUND");
    strcpy(clvarlt[83], "ARFLW_SNSR_MLFNCTN");
    strcpy(clvarlt[84], "ARFLW_SNSR_MLFNCTN");
    strcpy(clvarlt[85], "OX_SNSR_MLFNCTN");
    strcpy(clvarlt[86], "ARFLW_SNSR_MLFNCTN");
    strcpy(clvarlt[87], "OX_SNSR_MLFNCTN");
    strcpy(clvarlt[88], "THRTL_SNSR_MLFNCTN");
    strcpy(clvarlt[89], "ARFLW_SNSR_MLFNCTN");
    strcpy(clvarlt[90], "OX_SNSR_MLFNCTN");
    strcpy(clvarlt[91], "THRTL_SNSR_MLFNCTN");
    strcpy(clvarlt[92], "CLG_FL_FLTR");
    strcpy(clvarlt[93], "ARFLW_SNSR_MLFNCTN");
    strcpy(clvarlt[94], "OX_SNSR_MLFNCTN");
    strcpy(clvarlt[95], "THRTL_SNSR_MLFNCTN");
    strcpy(clvarlt[96], "CLG_FL_FLTR");
    strcpy(clvarlt[97], "DRTY_ARFLTR");
    strcpy(clvarlt[98], "ARFLW_SNSR_MLFNCTN");
    strcpy(clvarlt[99], "OX_SNSR_MLFNCTN");
    strcpy(clvarlt[100], "THRTL_SNSR_MLFNCTN");
    strcpy(clvarlt[101], "CLG_FL_FLTR");
    strcpy(clvarlt[102], "DRTY_ARFLTR");
    
    for(int i = 1; i < 41; i++)
    {
        cout << "** CAR FAULTS " << i << endl;
        
        for(int j = offset[i - 1]; j < offset[i]; j++)
        {
            cout << "CHECKING POINTS " << j - offset[i - 1] + 1 << " " << clvarlt[j + 1] << endl;
        }
        
        if (i == 20)
        {
            cout << "HIT RETURN KEY TO CONTINUE";
            cin.getline(buff, sizeof buff);;
        }
    }
    cout << endl;
    
}

int determine_member_concl_list(int f, char varble[20], char conclt[41][13])
{
    int n = 0;
    int i = f;
    while((strcmp(varble, conclt[i]) != 0) && (i < 41))
        i = i + 1;
    if (strcmp(varble, conclt[i]) == 0)
        n = i;
    cout << "DEBUG  n:" << n << "  (determine_member_concl_list)";
    return n;
}

int push_on_stack(int sn, int sp, int statsk[], int clausk[])
{
    sp = sp - 1;
    statsk[sp] = sn;
    clausk[sp] = 1;
    return sp;
}

void backward_instantiate(char varble[20], char varlt[26][20], int instlt[], char WHL_BAL[4], char SQK_UB[4], char BRKPD_FD[4], char ENG_PROB[10], char THRMST_FLT[4], char CLNT_LK[4], char HOSE_LK[4], char BATT_NEW[4], char TIRE_LK[4], char EXST_SMK_CL[6], char SMK_OCR[15], char PCV_OK[4], char TRBO_WRK[4], char FL_ODR_TLPIPE[4], char DRTY_ARFLTR[4], char CRBN_BUILDUP[4], char PREIGN_NOISE[4], char SCND_SPT_NOISE[4], char NOISE_SOUND[40], char ARFLW_SNSR_MLFNCTN[4], char OX_SNSR_MLFNCTN[4], char THRTL_SNSR_MLFNCTN[4], char CLG_FL_FLTR[4], float BATT_LD_TST, float CMPR_RATIO)
{
    int i = 1;
    while((strcmp(varble, varlt[i]) != 0) && (i < 26))
        i = i + 1;
    
    cout << "DEBUG      varlt[" << i << "]:" << varlt[i] << endl;
    cout << "DEBUG      instlt[" << i <<"]:" << instlt[i] << endl;
    
    if((strcmp(varble, varlt[i]) == 0) && (instlt[i] != 1))
    {
        instlt[i] = 1;
        switch (i)
        {
            case 1: cout << "INPUT YES OR NO FOR WHEEL BALANCE? ";
                cin.getline(WHL_BAL, 4);
                break;
            case 2: cout << "INPUT YES OR NO FOR SQUEAK UNDER THE BONNET? ";
                cin.getline(SQK_UB, 4);
                break;
            case 3: cout << "INPUT YES OR NO FOR BRAKE PAD FADED? ";
                cin.getline(BRKPD_FD, 4);
                break;
            case 4: cout << "INPUT OVERHEAT OR NOISE FOR ENGINE PROBLEM? ";
                cin.getline(ENG_PROB, 10);
                break;
            case 5: cout << "INPUT YES OR NO FOR THERMOSTAT FAULT? ";
                cin.getline(THRMST_FLT, 4);
                break;
            case 6: cout << "INPUT YES OR NO FOR COOLANT LEAKING? ";
                cin.getline(CLNT_LK, 4);
                break;
            case 7: cout << "INPUT YES OR NO FOR AC HOSE LEAKING? ";
                cin.getline(HOSE_LK, 4);
                break;
            case 8: cout << "INPUT YES OR NO FOR NEW BATTERY? ";
                cin.getline(BATT_NEW, 4);
                break;
            case 9: cout << "INPUT A REAL NUMBER FOR BATTERY LOAD TEST IN VOLTS? ";
                cin >> BATT_LD_TST;
                getchar();
                break;
            case 10: cout << "INPUT YES OR NO FOR PUNCTURE OR LEAK IN THE TIRE? ";
                cin.getline(TIRE_LK, 4);
                break;
            case 11: cout << "INPUT WHITE OR BLUE OR BLACK FOR THE COLOR OF EXHAUST SMOKE? ";
                cin.getline(EXST_SMK_CL, 6);
                break;
            case 12: cout << "INPUT BEFORE OR AFTER OR ALL TIME FOR WHEN THE SMOKE OCCUR? ";
                cin.getline(SMK_OCR, 15);
                break;
            case 13: cout << "INPUT YES OR NO FOR WHETHER PCV VALVE WELL PERFORMING? ";
                cin.getline(PCV_OK, 4);
                break;
            case 14: cout << "INPUT YES OR NO FOR WHETHER TURBO WELL PERFORMING? ";
                cin.getline(TRBO_WRK, 4);
                break;
            case 15: cout << "INPUT YES OR NO FOR FOUL ODOR FROM TAILPIPE? ";
                cin.getline(FL_ODR_TLPIPE, 4);
                break;
            case 16: cout << "INPUT YES OR NO FOR DIRTY AIR FILTER? ";
                cin.getline(DRTY_ARFLTR, 4);
                break;
            case 17: cout << "INPUT YES OR NO FOR CARBON BUILDUP IN INTAKE MANIFOLD? ";
                cin.getline(CRBN_BUILDUP, 4);
                break;
            case 18: cout << "INPUT YES OR NO FOR DENOTATION/PRE-IGNITION NOISE? ";
                cin.getline(PREIGN_NOISE, 4);
                break;
            case 19: cout << "INPUT YES OR NO FOR SECOND SPOT NOISE? ";
                cin.getline(SCND_SPT_NOISE, 4);
                break;
            case 20: cout << "INPUT A REAL NUMBER FOR COMPRESSION RATIO? ";
                cin >> CMPR_RATIO;
                getchar();
                break;
            case 21: cout << "INPUT CLICKING OR KNOCKING OR BELL OR RUMBLING OR RATTLING FOR NOISE YOU HEARD? ";
                cin.getline(NOISE_SOUND, 40);
                break;
            case 22: cout << "INPUT YES OR NO FOR MALFUNCTIONED MASS AIR FLOW SENSOR? ";
                cin.getline(ARFLW_SNSR_MLFNCTN, 4);
                break;
            case 23: cout << "INPUT YES OR NO FOR MALFUNCTIONED OXYGEN SENSOR? ";
                cin.getline(OX_SNSR_MLFNCTN, 4);
                break;
            case 24: cout << "INPUT YES OR NO FOR MALFUNCTIONED THROTTLE POSITION SENSOR? ";
                cin.getline(THRTL_SNSR_MLFNCTN, 4);
                break;
            case 25: cout << "INPUT YES OR NO FOR DIRTY/CLOGGED FUEL FILTER? ";
                cin.getline(CLG_FL_FLTR, 4);
                break;
        }
    }
}
