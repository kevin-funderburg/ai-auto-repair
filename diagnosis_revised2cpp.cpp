# include <iostream>
# include <string>
using namespace std;

/*  conclusion list */
char conclt[41][13];
/*  variable list */
char varlt[26][20];
/*  clause vairable list */
char clvarlt[240][20];
char varble[20];
char /*wheel balanced*/ WHL_BAL[4];
char /*squeak sound under bonnet*/ SQK_UB[4], /*brake pad faded*/ BRKPD_FD[4];
char /*engine problem*/ ENG_PROB[10], /*thermostat fault*/ THRMST_FLT[4], /*coolant leaking*/ CLNT_LK[4];
char /*AC hose leak*/ HOSE_LK[4];
char /*battery new*/ BATT_NEW[4];
char /*tire leak*/ TIRE_LK[4];
char /*smoke color*/ EXST_SMK_CL[6], /*smoke occur*/ SMK_OCR[15], /*pcv valve ok*/ PCV_OK[4], /*turbo works well*/ TRBO_WRK[4], /*foul odor from tailpipe*/ FL_ODR_TLPIPE[4], /*dirty air filter*/ DRTY_ARFLTR[4], /*carbon buildup*/ CRBN_BUILDUP[4];
char /*denotation, preignition noise*/ PREIGN_NOISE[4], /*second spot noise*/ SCND_SPT_NOISE[4], /*noise sound like*/ NOISE_SOUND[40];
char /*air flow sensor malfunctioned*/ ARFLW_SNSR_MLFNCTN[4], /*oxygen sensor malfunctioned*/ OX_SNSR_MLFNCTN[4], /*throttle position sensor malfunctioned*/ THRTL_SNSR_MLFNCTN[4], /* clogged fuel filter*/ CLG_FL_FLTR[4];
char /*fault*/ FAULT[100];
char buff[128];

/* instantiated list */
int instlt[103];
/* statement stack */
int statsk[103];
int /* clause stack */ clausk[103], sn, f, i, j, s, k, /*stack pointer */ sp;
float /*battery load test (higher than 12.45 volt)*/ BATT_LD_TST, /*compression ratio (over 14)*/ CMPR_RATIO;

void determine_member_concl_list(void);
void push_on_stack(void);
void instantiate(void);

int main()
{
    /***** initialization section ******/
    sp = 103;
    for (i = 1; i < 103; i++)
    {
        strcpy(conclt[i], "");
        strcpy(varlt[i], "");
        instlt[i] = 0;
        statsk[i] = 0;
        clausk[i] = 0;
    }
    for (i = 1; i < 240; i++)
        strcpy(clvarlt[i], "");
    
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
    
    cout << "*** CAR FAULT LIST ***" << endl;
    
    for (i = 1; i < 41; i++)
        cout << "CAR FAULT " << i << " " << conclt[i] << endl;
    
    cout << "HIT RETURN TO CONTINUE";
    cin.getline(buff, sizeof buff);
    
    cout << "*** CHECKING POINTS LIST ***" << endl;
    
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
    
    for(i = 1; i < 26; i++)
        cout << "CHECKING POINTS" << i << " " << varlt[i] << endl;
    
    cout << "HIT RETURN KEY TO CONTINUE";
    
    cin.getline(buff, sizeof buff);;
    
    cout << "*** CHECKING POINTS BY CAR FAULTS ***" << endl;
    
    strcpy(clvarlt[1], "WHL_BAL");
    strcpy(clvarlt[7], "WHL_BAL");
    strcpy(clvarlt[13], "SQK_UB");
    strcpy(clvarlt[19], "SQK_UB");
    strcpy(clvarlt[20], "BRKPD_FD");
    strcpy(clvarlt[25], "SQK_UB");
    strcpy(clvarlt[26], "BRKPD_FD");
    strcpy(clvarlt[31], "ENG_PROB");
    strcpy(clvarlt[32], "THRMST_FLT");
    strcpy(clvarlt[37], "ENG_PROB");
    strcpy(clvarlt[38], "THRMST_FLT");
    strcpy(clvarlt[39], "CLNT_LK");
    strcpy(clvarlt[43], "ENG_PROB");
    strcpy(clvarlt[44], "THRMST_FLT");
    strcpy(clvarlt[45], "CLNT_LK");
    strcpy(clvarlt[49], "HOSE_LK");
    strcpy(clvarlt[55], "HOSE_LK");
    strcpy(clvarlt[61], "BATT_NEW");
    strcpy(clvarlt[67], "BATT_NEW");
    strcpy(clvarlt[68], "BATT_LD_TST");
    strcpy(clvarlt[73], "BATT_NEW");
    strcpy(clvarlt[74], "BATT_LD_TST");
    strcpy(clvarlt[79], "TIRE_LK");
    strcpy(clvarlt[85], "TIRE_LK");
    strcpy(clvarlt[91], "EXST_SMK_CL");
    strcpy(clvarlt[92], "CLNT_LK");
    strcpy(clvarlt[97], "EXST_SMK_CL");
    strcpy(clvarlt[98], "CLNT_LK");
    strcpy(clvarlt[103], "EXST_SMK_CL");
    strcpy(clvarlt[104], "SMK_OCR");
    strcpy(clvarlt[109], "EXST_SMK_CL");
    strcpy(clvarlt[110], "SMK_OCR");
    strcpy(clvarlt[115], "EXST_SMK_CL");
    strcpy(clvarlt[116], "SMK_OCR");
    strcpy(clvarlt[117], "PCV_OK");
    strcpy(clvarlt[118], "TRBO_WRK");
    strcpy(clvarlt[121], "EXST_SMK_CL");
    strcpy(clvarlt[122], "SMK_OCR");
    strcpy(clvarlt[123], "PCV_OK");
    strcpy(clvarlt[124], "TRBO_WRK");
    strcpy(clvarlt[127], "EXST_SMK_CL");
    strcpy(clvarlt[128], "SMK_OCR");
    strcpy(clvarlt[129], "PCV_OK");
    strcpy(clvarlt[133], "EXST_SMK_CL");
    strcpy(clvarlt[134], "FL_ODR_TLPIPE");
    strcpy(clvarlt[139], "EXST_SMK_CL");
    strcpy(clvarlt[140], "FL_ODR_TLPIPE");
    strcpy(clvarlt[141], "DRTY_ARFLTR");
    strcpy(clvarlt[145], "EXST_SMK_CL");
    strcpy(clvarlt[146], "FL_ODR_TLPIPE");
    strcpy(clvarlt[147], "DRTY_ARFLTR");
    strcpy(clvarlt[148], "CRBN_BUILDUP");
    strcpy(clvarlt[151], "EXST_SMK_CL");
    strcpy(clvarlt[152], "FL_ODR_TLPIPE");
    strcpy(clvarlt[153], "DRTY_ARFLTR");
    strcpy(clvarlt[154], "CRBN_BUILDUP");
    strcpy(clvarlt[157], "ENG_PROB");
    strcpy(clvarlt[158], "PREIGN_NOISE");
    strcpy(clvarlt[159], "SCND_SPT_NOISE");
    strcpy(clvarlt[163], "ENG_PROB");
    strcpy(clvarlt[164], "PREIGN_NOISE");
    strcpy(clvarlt[165], "SCND_SPT_NOISE");
    strcpy(clvarlt[166], "COMPR_RATIO");
    strcpy(clvarlt[169], "ENG_PROB");
    strcpy(clvarlt[170], "PREIGN_NOISE");
    strcpy(clvarlt[171], "SCND_SPT_NOISE");
    strcpy(clvarlt[172], "COMPR_RATIO");
    strcpy(clvarlt[175], "ENG_PROB");
    strcpy(clvarlt[176], "PREIGN_NOISE");
    strcpy(clvarlt[177], "NOISE_SOUND");
    strcpy(clvarlt[181], "ENG_PROB");
    strcpy(clvarlt[182], "PREIGN_NOISE");
    strcpy(clvarlt[183], "NOISE_SOUND");
    strcpy(clvarlt[187], "ENG_PROB");
    strcpy(clvarlt[188], "PREIGN_NOISE");
    strcpy(clvarlt[189], "NOISE_SOUND");
    strcpy(clvarlt[193], "ENG_PROB");
    strcpy(clvarlt[194], "PREIGN_NOISE");
    strcpy(clvarlt[195], "NOISE_SOUND");
    strcpy(clvarlt[199], "ENG_PROB");
    strcpy(clvarlt[200], "PREIGN_NOISE");
    strcpy(clvarlt[201], "NOISE_SOUND");
    strcpy(clvarlt[205], "ARFLW_SNSR_MLFNCTN");
    strcpy(clvarlt[211], "ARFLW_SNSR_MLFNCTN");
    strcpy(clvarlt[212], "OX_SNSR_MLFNCTN");
    strcpy(clvarlt[217], "ARFLW_SNSR_MLFNCTN");
    strcpy(clvarlt[218], "OX_SNSR_MLFNCTN");
    strcpy(clvarlt[219], "THRTL_SNSR_MLFNCTN");
    strcpy(clvarlt[223], "ARFLW_SNSR_MLFNCTN");
    strcpy(clvarlt[224], "OX_SNSR_MLFNCTN");
    strcpy(clvarlt[225], "THRTL_SNSR_MLFNCTN");
    strcpy(clvarlt[226], "CLG_FL_FLTR");
    strcpy(clvarlt[229], "ARFLW_SNSR_MLFNCTN");
    strcpy(clvarlt[230], "OX_SNSR_MLFNCTN");
    strcpy(clvarlt[231], "THRTL_SNSR_MLFNCTN");
    strcpy(clvarlt[232], "CLG_FL_FLTR");
    strcpy(clvarlt[233], "DRTY_ARFLTR");
    strcpy(clvarlt[235], "ARFLW_SNSR_MLFNCTN");
    strcpy(clvarlt[236], "OX_SNSR_MLFNCTN");
    strcpy(clvarlt[237], "THRTL_SNSR_MLFNCTN");
    strcpy(clvarlt[238], "CLG_FL_FLTR");
    strcpy(clvarlt[239], "DRTY_ARFLTR");
    
    for(i = 1; i < 41; i++)
    {
        cout << "** CAR FAULTS " << i << endl;
        
        for(j = 1; j < 7; j++)
        {
            k = 6 * (i - 1) + j;
            cout << "CHECKING POINTS " << j << " " << clvarlt[k] << endl;
        }
        
        
        if (i == 20)
        {
            cout << "HIT RETURN KEY TO CONTINUE";
            cin.getline(buff, sizeof buff);;
        }
    }
    /****** inference section *****/
    cout << "** ENTER CAR PROBLEM? (PLEASE CHOOSE FROM WHEEL, SQUEAK, ENGINE, AC, BATTERY, TIRE, SMOKE, OR ACCELERATION" << endl;
    cin.getline(varble, sizeof varble);
    
    f = 1;
    
    do
    {
        determine_member_concl_list();
       
        if (sn != 0)
            push_on_stack();
        
        do
        {
            i = (statsk[sp] - 1) * 6 + clausk[sp];
            strcpy(varble, clvarlt[i]);
            if(strcmp(varble, "") != 0) {
                instantiate();
                clausk[sp] = clausk[sp] + 1;
            }
        } while(strcmp(varble, "") != 0);
        
        sn = statsk[sp];
        s = 0;
        switch (sn) {
            case 1:
                if((strcmp(WHL_BAL, "YES") == 0))
                    s = 1;
                break;
            case 2:
                if((strcmp(WHL_BAL, "NO") == 0))
                    s = 1;
                break;
            case 3:
                if((strcmp(SQK_UB, "YES") == 0))
                    s = 1;
                break;
            case 4:
                if((strcmp(SQK_UB, "NO") == 0) && (strcmp(BRKPD_FD, "YES") == 0))
                    s = 1;
                break;
            case 5:
                if((strcmp(SQK_UB, "NO") == 0) && (strcmp(BRKPD_FD, "NO") == 0))
                    s = 1;
                break;
            case 6:
                if((strcmp(ENG_PROB, "OVERHEAT") == 0) && (strcmp(THRMST_FLT, "YES") == 0))
                    s = 1;
                break;
            case 7:
                if((strcmp(ENG_PROB, "OVERHEAT") == 0) && (strcmp(THRMST_FLT, "NO") == 0) && (strcmp(CLNT_LK, "YES") == 0))
                    s = 1;
                break;
            case 8:
                if((strcmp(ENG_PROB, "OVERHEAT") == 0) && (strcmp(THRMST_FLT, "NO") == 0) && (strcmp(CLNT_LK, "NO") == 0))
                    s = 1;
                break;
            case 9:
                if((strcmp(HOSE_LK, "YES") == 0))
                    s = 1;
                break;
            case 10:
                if((strcmp(HOSE_LK, "NO") == 0))
                    s = 1;
                break;
            case 11:
                if((strcmp(BATT_NEW, "YES") == 0))
                    s = 1;
                break;
            case 12:
                if((strcmp(BATT_NEW, "NO") == 0) && (BATT_LD_TST > 12.45))
                    s = 1;
                break;
            case 13:
                if((strcmp(BATT_NEW, "NO") == 0) && (BATT_LD_TST <= 12.45))
                    s = 1;
                break;
            case 14:
                if((strcmp(TIRE_LK, "YES") == 0))
                    s = 1;
                break;
            case 15:
                if((strcmp(TIRE_LK, "NO") == 0))
                    s = 1;
                break;
            case 16:
                if((strcmp(EXST_SMK_CL, "WHITE") == 0) && (strcmp(CLNT_LK, "YES") == 0))
                    s = 1;
                break;
            case 17:
                if((strcmp(EXST_SMK_CL, "WHITE") == 0) && (strcmp(CLNT_LK, "NO") == 0))
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
                if((strcmp(EXST_SMK_CL, "BLUE") == 0) && (strcmp(SMK_OCR, "ALL TIME") == 0) && strcmp(PCV_OK, "YES") && strcmp(TRBO_WRK, "YES"))
                    s = 1;
                break;
            case 21:
                if((strcmp(EXST_SMK_CL, "BLUE") == 0) && (strcmp(SMK_OCR, "ALL TIME") == 0) && strcmp(PCV_OK, "YES") && strcmp(TRBO_WRK, "NO"))
                    s = 1;
                break;
            case 22:
                if((strcmp(EXST_SMK_CL, "BLUE") == 0) && (strcmp(SMK_OCR, "ALL TIME") == 0) && strcmp(PCV_OK, "NO"))
                    s = 1;
                break;
            case 23:
                if((strcmp(EXST_SMK_CL, "BLACK") == 0) && (strcmp(FL_ODR_TLPIPE, "YES") == 0))
                    s = 1;
                break;
            case 24:
                if((strcmp(EXST_SMK_CL, "BLACK") == 0) && (strcmp(FL_ODR_TLPIPE, "NO") == 0) && strcmp(DRTY_ARFLTR, "YES"))
                    s = 1;
                break;
            case 25:
                if((strcmp(EXST_SMK_CL, "BLACK") == 0) && (strcmp(FL_ODR_TLPIPE, "NO") == 0) && strcmp(DRTY_ARFLTR, "NO") && strcmp(CRBN_BUILDUP, "YES"))
                    s = 1;
                break;
            case 26:
                if((strcmp(EXST_SMK_CL, "BLACK") == 0) && (strcmp(FL_ODR_TLPIPE, "NO") == 0) && strcmp(DRTY_ARFLTR, "NO") && strcmp(CRBN_BUILDUP, "NO"))
                    s = 1;
                break;
            case 27:
                if((strcmp(ENG_PROB, "NOISE") == 0) && (strcmp(PREIGN_NOISE, "YES") == 0) && (strcmp(SCND_SPT_NOISE, "YES") == 0))
                    s = 1;
                break;
            case 28:
                if((strcmp(ENG_PROB, "NOISE") == 0) && (strcmp(PREIGN_NOISE, "YES") == 0) && (strcmp(SCND_SPT_NOISE, "NO") == 0) && (CMPR_RATIO > 14))
                    s = 1;
                break;
            case 29:
                if((strcmp(ENG_PROB, "NOISE") == 0) && (strcmp(PREIGN_NOISE, "YES") == 0) && (strcmp(SCND_SPT_NOISE, "NO") == 0) && (CMPR_RATIO <= 14))
                    s = 1;
                break;
            case 30:
                if((strcmp(ENG_PROB, "NOISE") == 0) && (strcmp(PREIGN_NOISE, "NO") == 0) && (strcmp(NOISE_SOUND, "CLICKING") == 0))
                    s = 1;
                break;
            case 31:
                if((strcmp(ENG_PROB, "NOISE") == 0) && (strcmp(PREIGN_NOISE, "NO") == 0) && (strcmp(NOISE_SOUND, "KNOCKING") == 0))
                    s = 1;
                break;
            case 32:
                if((strcmp(ENG_PROB, "NOISE") == 0) && (strcmp(PREIGN_NOISE, "NO") == 0) && (strcmp(NOISE_SOUND, "BELL") == 0))
                    s = 1;
                break;
            case 33:
                if((strcmp(ENG_PROB, "NOISE") == 0) && (strcmp(PREIGN_NOISE, "NO") == 0) && (strcmp(NOISE_SOUND, "RUMBLING") == 0))
                    s = 1;
                break;
            case 34:
                if((strcmp(ENG_PROB, "NOISE") == 0) && (strcmp(PREIGN_NOISE, "NO") == 0) && (strcmp(NOISE_SOUND, "RATTLING") == 0))
                    s = 1;
                break;
            case 35:
                if((strcmp(ARFLW_SNSR_MLFNCTN, "YES") == 0))
                    s = 1;
                break;
            case 36:
                if((strcmp(ARFLW_SNSR_MLFNCTN, "NO") == 0) && strcmp(OX_SNSR_MLFNCTN, "YES"))
                    s = 1;
                break;
            case 37:
                if((strcmp(ARFLW_SNSR_MLFNCTN, "NO") == 0) && strcmp(OX_SNSR_MLFNCTN, "NO") && strcmp(THRTL_SNSR_MLFNCTN, "YES"))
                    s = 1;
                break;
            case 38:
                if((strcmp(ARFLW_SNSR_MLFNCTN, "NO") == 0) && strcmp(OX_SNSR_MLFNCTN, "NO") && strcmp(THRTL_SNSR_MLFNCTN, "NO") && strcmp(CLG_FL_FLTR, "YES"))
                    s = 1;
                break;
            case 39:
                if((strcmp(ARFLW_SNSR_MLFNCTN, "NO") == 0) && strcmp(OX_SNSR_MLFNCTN, "NO") && strcmp(THRTL_SNSR_MLFNCTN, "NO") && strcmp(CLG_FL_FLTR, "NO") && strcmp(DRTY_ARFLTR, "YES"))
                    s = 1;
                break;
            case 40:
                if((strcmp(ARFLW_SNSR_MLFNCTN, "NO") == 0) && strcmp(OX_SNSR_MLFNCTN, "NO") && strcmp(THRTL_SNSR_MLFNCTN, "NO") && strcmp(CLG_FL_FLTR, "NO") && strcmp(DRTY_ARFLTR, "NO"))
                    s = 1;
                break;
        }
        if( s != 1) {
            i = statsk[sp];
            strcpy(varble, conclt[i]);
            f = statsk[sp] + 1;
            determine_member_concl_list();
            sp = sp + 1;
        }
    } while((s != 1) && (sn !=0));
    
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
    }
    sp = sp + 1;
    if(sp >= 103) {
        cout << "*** SUCCESS ***" << endl;
        }
    else {
        cout << "*** CANNOT DETECT FAULT ***" << endl;
        }
}

void determine_member_concl_list() {
    sn = 0;
    i = f;
    while((strcmp(varble, conclt[i]) != 0) && (i < 41))
        i = i + 1;
    if (strcmp(varble, conclt[i]) == 0)
        sn = i;
}

void push_on_stack()
{
    sp = sp - 1;
    statsk[sp] = sn;
    clausk[sp] = 1;
}

void instantiate()
{
    i = 1;
    while((strcmp(varble, varlt[i]) != 0) && (i < 26))
        i = i + 1;
    
    if((strcmp(varble, varlt[i]) == 0) && (instlt[i] != 1))
    {
        instlt[i] = 1;
        switch (i)
        {
            case 1: cout << "INPUT YES OR NO FOR WHEEL BALANCE? ";
                cin.getline(WHL_BAL, sizeof WHL_BAL);
                break;
            case 2: cout << "INPUT YES OR NO FOR SQUEAK UNDER THE BONNET? ";
                cin.getline(SQK_UB, sizeof WHL_BAL);
                break;
            case 3: cout << "INPUT YES OR NO FOR BRAKE PAD FADED? ";
                cin.getline(BRKPD_FD, sizeof BRKPD_FD);
                break;
            case 4: cout << "INPUT OVERHEAT OR NOISE FOR ENGINE PROBLEM? ";
                cin.getline(ENG_PROB, sizeof ENG_PROB);
                break;
            case 5: cout << "INPUT YES OR NO FOR THERMOSTAT FAULT? ";
                cin.getline(THRMST_FLT, sizeof THRMST_FLT);
                break;
            case 6: cout << "INPUT YES OR NO FOR COOLANT LEAKING? ";
                cin.getline(CLNT_LK, sizeof CLNT_LK);
                break;
            case 7: cout << "INPUT YES OR NO FOR AC HOSE LEAKING? ";
                cin.getline(HOSE_LK, sizeof HOSE_LK);
                break;
            case 8: cout << "INPUT YES OR NO FOR NEW BATTERY? ";
                cin.getline(BATT_NEW, sizeof BATT_NEW);
                break;
            case 9: cout << "INPUT A REAL NUMBER FOR BATTERY LOAD TEST IN VOLTS? ";
                cin >> BATT_LD_TST;
                getchar();
                break;
            case 10: cout << "INPUT YES OR NO FOR PUNCTURE OR LEAK IN THE TIRE? ";
                cin.getline(TIRE_LK, sizeof TIRE_LK);
                break;
            case 11: cout << "INPUT WHITE OR BLUE OR BLACK FOR THE COLOR OF EXHAUST SMOKE? ";
                cin.getline(EXST_SMK_CL, sizeof EXST_SMK_CL);
                break;
            case 12: cout << "INPUT BEFORE OR AFTER OR ALL TIME FOR WHEN THE SMOKE OCCUR? ";
                cin.getline(SMK_OCR, sizeof SMK_OCR);
                break;
            case 13: cout << "INPUT YES OR NO FOR WHETHER PCV VALVE WELL PERFORMING? ";
                cin.getline(PCV_OK, sizeof PCV_OK);
                break;
            case 14: cout << "INPUT YES OR NO FOR WHETHER TURBO WELL PERFORMING? ";
                cin.getline(TRBO_WRK, sizeof TRBO_WRK);
                break;
            case 15: cout << "INPUT YES OR NO FOR FOUL ODOR FROM TAILPIPE? ";
                cin.getline(FL_ODR_TLPIPE, sizeof FL_ODR_TLPIPE);
                break;
            case 16: cout << "INPUT YES OR NO FOR DIRTY AIR FILTER? ";
                cin.getline(DRTY_ARFLTR, sizeof DRTY_ARFLTR);
                break;
            case 17: cout << "INPUT YES OR NO FOR CARBON BUILDUP IN INTAKE MANIFOLD? ";
                cin.getline(CRBN_BUILDUP, sizeof CRBN_BUILDUP);
                break;
            case 18: cout << "INPUT YES OR NO FOR DENOTATION/PRE-IGNITION NOISE? ";
                cin.getline(PREIGN_NOISE, sizeof PREIGN_NOISE);
                break;
            case 19: cout << "INPUT YES OR NO FOR SECOND SPOT NOISE? ";
                cin.getline(SCND_SPT_NOISE, sizeof SCND_SPT_NOISE);
                break;
            case 20: cout << "INPUT A REAL NUMBER FOR COMPRESSION RATIO? ";
                cin >> CMPR_RATIO;
                getchar();
                break;
            case 21: cout << "INPUT CLICKING OR KNOCKING OR BELL OR RUMBLING OR RATTLING FOR NOISE YOU HEARD? ";
                cin.getline(NOISE_SOUND, sizeof NOISE_SOUND);
                break;
            case 22: cout << "INPUT YES OR NO FOR MALFUNCTIONED MASS AIR FLOW SENSOR? ";
                cin.getline(ARFLW_SNSR_MLFNCTN, sizeof ARFLW_SNSR_MLFNCTN);
                break;
            case 23: cout << "INPUT YES OR NO FOR MALFUNCTIONED OXYGEN SENSOR? ";
                cin.getline(OX_SNSR_MLFNCTN, sizeof OX_SNSR_MLFNCTN);
                break;
            case 24: cout << "INPUT YES OR NO FOR MALFUNCTIONED THROTTLE POSITION SENSOR? ";
                cin.getline(THRTL_SNSR_MLFNCTN, sizeof THRTL_SNSR_MLFNCTN);
                break;
            case 25: cout << "INPUT YES OR NO FOR DIRTY/CLOGGED FUEL FILTER? ";
                cin.getline(CLG_FL_FLTR, sizeof CLG_FL_FLTR);
                break;
        }
    }
}
