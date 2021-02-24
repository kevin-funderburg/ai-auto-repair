# include <iostream>
# include <string>

/*  conclusion list */
char conclt[41][13];
/*  variable list */
char varlt[35][20];
/*  clause vairable list */
char clvarlt[280][20];
char varble[20];
char /*vibrating steering wheel*/ VIB_STR_WHL[4], /*wheel balanced*/ WHL_BAL[4];
char /*squeak sound*/ SQK[4], /*squeak sound under bonnet*/ SQK_UB[4], /*brake pad faded*/ BRKPD_FD[4];
char /*engine overheat*/ ENG_OVHT[4], /*thermostat fault*/ THRMST_FLT[4], /*coolant leaking*/ CLNT_LK[4];
char /*AC not working*/ AC_NTWRK[4], /*AC hose leak*/ HOSE_LK[4];
char /*battery not working*/ BATT_NTWRK[4], /*battery new*/ BATT_NEW[4];
char /*flat tire*/ FLT_TIRE[4], /*tire leak*/ TIRE_LK[4];
char /*exhaust smoke*/ EXST_SMK[4], /*smoke color*/ EXST_SMK_CL[6], /*smoke occur*/ SMK_OCR[15], /*pcv valve ok*/ PCV_OK[4], /*turbo works well*/ TRBO_WRK[4], /*foul odor from tailpipe*/ FL_ODR_TLPIPE[4], /*dirty air filter*/ DRTY_ARFLTR[4], /*carbon buildup*/ CRBN_BUILDUP[4];
char /*engine noise*/ ENG_NOISE[4], /*denotation, preignition noise*/ PREIGN_NOISE[4], /*second spot noise*/ SCND_SPT_NOISE[4], /*noise sound like*/ NOISE_SOUND[40];
char /*fail to accelerate*/ FAIL_ACC[4], /*air flow sensor malfunctioned*/ ARFLW_SNSR_MLFNCTN[4], /*oxygen sensor malfunctioned*/ OX_SNSR_MLFNCTN[4], /*throttle position sensor malfunctioned*/ THRTL_SNSR_MLFNCTN[4], /* clogged fuel filter*/ CLG_FL_FLTR[4];
char /*fault*/ FAULT[100];
char buff[128];

/* instantiated list */
int instlt[132];
/* statement stack */
int statsk[132];
int /* clause stack */ clausk[132], sn, f, i, j, s, k, /*stack pointer */ sp;
float /*battery load test (higher than 12.45 volt)*/ BATT_LD_TST, /*compression ratio (over 14)*/ CMPR_RATIO;

void determine_member_concl_list(void);
void push_on_stack(void);
void instantiate(void);

int main()
{
    /***** initialization section ******/
    sp = 132;
    for (i = 1; i < 132; i++)
    {
        strcpy(conclt[i], "");
        strcpy(varlt[i], "");
        instlt[i] = 0;
        statsk[i] = 0;
        clausk[i] = 0;
    }
    for (i = 1; i < 281; i++)
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
    
    /*** comment 305 *****/
    printf("*** CONCLUSION LIST ***\n");
    for (i = 1; i < 41; i++)
        printf("CONCLUSION %d %s\n", i, conclt[i]);
    
    printf("HIT RETURN TO CONTINUE");
    gets(buff);
    
    printf("*** VARIABLE LIST *\n");
    /**** comment 367 *****/
    strcpy(varlt[1], "VIB_STR_WHL");
    strcpy(varlt[2], "WHL_BAL");
    strcpy(varlt[3], "SQK");
    strcpy(varlt[4], "SQK_UB");
    strcpy(varlt[5], "BRKPD_FD");
    strcpy(varlt[6], "ENG_OVHT");
    strcpy(varlt[7], "THRMST_FLT");
    strcpy(varlt[8], "CLNT_LK");
    strcpy(varlt[9], "AC_NTWRK");
    strcpy(varlt[10], "HOSE_LK");
    strcpy(varlt[11], "BATT_NTWRK");
    strcpy(varlt[12], "BATT_NEW");
    strcpy(varlt[13], "BATT_LD_TST");
    strcpy(varlt[14], "FLT_TIRE");
    strcpy(varlt[15], "TIRE_LK");
    strcpy(varlt[16], "EXST_SMK");
    strcpy(varlt[17], "EXST_SMK_CL");
    strcpy(varlt[18], "SMK_OCR");
    strcpy(varlt[19], "PCV_OK");
    strcpy(varlt[20], "TRBO_WRK");
    strcpy(varlt[21], "FL_ODR_TLPIPE");
    strcpy(varlt[22], "DRTY_ARFLTR");
    strcpy(varlt[23], "CRBN_BUILDUP");
    strcpy(varlt[24], "ENG_NOISE");
    strcpy(varlt[25], "PREIGN_NOISE");
    strcpy(varlt[26], "SCND_SPT_NOISE");
    strcpy(varlt[27], "COMPR_RATIO");
    strcpy(varlt[28], "NOISE_SOUND");
    strcpy(varlt[29], "FAIL_ACC");
    strcpy(varlt[30], "ARFLW_SNSR_MLFNCTN");
    strcpy(varlt[31], "OX_SNSR_MLFNCTN");
    strcpy(varlt[32], "THRTL_SNSR_MLFNCTN");
    strcpy(varlt[33], "CLG_FL_FLTR");
    
    for(i = 1; i < 35; i++)
        printf("VARIABLE %d %s\n", i, varlt[i]);
    
    printf("HIT RETURN KEY TO CONTINUE");
    
    gets(buff);
    
    printf("*** CLAUSE VARIABLE LIST ***\n");
    /***** comment 407 through 409 ***/
    strcpy(clvarlt[1], "VIB_STR_WHL");
    strcpy(clvarlt[2], "WHL_BAL");
    strcpy(clvarlt[8], "VIB_STR_WHL");
    strcpy(clvarlt[9], "WHL_BAL");
    strcpy(clvarlt[15], "SQK");
    strcpy(clvarlt[16], "SQK_UB");
    strcpy(clvarlt[22], "SQK");
    strcpy(clvarlt[23], "SQK_UB");
    strcpy(clvarlt[24], "BRKPD_FD");
    strcpy(clvarlt[29], "SQK");
    strcpy(clvarlt[30], "SQK_UB");
    strcpy(clvarlt[31], "BRKPD_FD");
    strcpy(clvarlt[36], "ENG_OVHT");
    strcpy(clvarlt[37], "THRMST_FLT");
    strcpy(clvarlt[43], "ENG_OVHT");
    strcpy(clvarlt[44], "THRMST_FLT");
    strcpy(clvarlt[45], "CLNT_LK");
    strcpy(clvarlt[50], "ENG_OVHT");
    strcpy(clvarlt[51], "THRMST_FLT");
    strcpy(clvarlt[52], "CLNT_LK");
    strcpy(clvarlt[57], "AC_NTWRK");
    strcpy(clvarlt[58], "HOSE_LK");
    strcpy(clvarlt[64], "AC_NTWRK");
    strcpy(clvarlt[65], "HOSE_LK");
    strcpy(clvarlt[71], "BATT_NTWRK");
    strcpy(clvarlt[72], "BATT_NEW");
    strcpy(clvarlt[78], "BATT_NTWRK");
    strcpy(clvarlt[79], "BATT_NEW");
    strcpy(clvarlt[80], "BATT_LD_TST");
    strcpy(clvarlt[85], "BATT_NTWRK");
    strcpy(clvarlt[86], "BATT_NEW");
    strcpy(clvarlt[87], "BATT_LD_TST");
    strcpy(clvarlt[92], "FLT_TIRE");
    strcpy(clvarlt[93], "TIRE_LK");
    strcpy(clvarlt[99], "FLT_TIRE");
    strcpy(clvarlt[100], "TIRE_LK");
    strcpy(clvarlt[106], "EXST_SMK");
    strcpy(clvarlt[107], "EXST_SMK_CL");
    strcpy(clvarlt[108], "CLNT_LK");
    strcpy(clvarlt[113], "EXST_SMK");
    strcpy(clvarlt[114], "EXST_SMK_CL");
    strcpy(clvarlt[115], "CLNT_LK");
    strcpy(clvarlt[120], "EXST_SMK");
    strcpy(clvarlt[121], "EXST_SMK_CL");
    strcpy(clvarlt[122], "SMK_OCR");
    strcpy(clvarlt[127], "EXST_SMK");
    strcpy(clvarlt[128], "EXST_SMK_CL");
    strcpy(clvarlt[129], "SMK_OCR");
    strcpy(clvarlt[134], "EXST_SMK");
    strcpy(clvarlt[135], "EXST_SMK_CL");
    strcpy(clvarlt[136], "SMK_OCR");
    strcpy(clvarlt[137], "PCV_OK");
    strcpy(clvarlt[138], "TRBO_WRK");
    strcpy(clvarlt[141], "EXST_SMK");
    strcpy(clvarlt[142], "EXST_SMK_CL");
    strcpy(clvarlt[143], "SMK_OCR");
    strcpy(clvarlt[144], "PCV_OK");
    strcpy(clvarlt[145], "TRBO_WRK");
    strcpy(clvarlt[148], "EXST_SMK");
    strcpy(clvarlt[149], "EXST_SMK_CL");
    strcpy(clvarlt[150], "SMK_OCR");
    strcpy(clvarlt[151], "PCV_OK");
    strcpy(clvarlt[155], "EXST_SMK");
    strcpy(clvarlt[156], "EXST_SMK_CL");
    strcpy(clvarlt[157], "FL_ODR_TLPIPE");
    strcpy(clvarlt[162], "EXST_SMK");
    strcpy(clvarlt[163], "EXST_SMK_CL");
    strcpy(clvarlt[164], "FL_ODR_TLPIPE");
    strcpy(clvarlt[165], "DRTY_ARFLTR");
    strcpy(clvarlt[169], "EXST_SMK");
    strcpy(clvarlt[170], "EXST_SMK_CL");
    strcpy(clvarlt[171], "FL_ODR_TLPIPE");
    strcpy(clvarlt[172], "DRTY_ARFLTR");
    strcpy(clvarlt[173], "CRBN_BUILDUP");
    strcpy(clvarlt[176], "EXST_SMK");
    strcpy(clvarlt[177], "EXST_SMK_CL");
    strcpy(clvarlt[178], "FL_ODR_TLPIPE");
    strcpy(clvarlt[179], "DRTY_ARFLTR");
    strcpy(clvarlt[180], "CRBN_BUILDUP");
    strcpy(clvarlt[183], "ENG_NOISE");
    strcpy(clvarlt[184], "PREIGN_NOISE");
    strcpy(clvarlt[185], "SCND_SPT_NOISE");
    strcpy(clvarlt[190], "ENG_NOISE");
    strcpy(clvarlt[191], "PREIGN_NOISE");
    strcpy(clvarlt[192], "SCND_SPT_NOISE");
    strcpy(clvarlt[193], "COMPR_RATIO");
    strcpy(clvarlt[197], "ENG_NOISE");
    strcpy(clvarlt[198], "PREIGN_NOISE");
    strcpy(clvarlt[199], "SCND_SPT_NOISE");
    strcpy(clvarlt[200], "COMPR_RATIO");
    strcpy(clvarlt[204], "ENG_NOISE");
    strcpy(clvarlt[205], "PREIGN_NOISE");
    strcpy(clvarlt[206], "NOISE_SOUND");
    strcpy(clvarlt[211], "ENG_NOISE");
    strcpy(clvarlt[212], "PREIGN_NOISE");
    strcpy(clvarlt[213], "NOISE_SOUND");
    strcpy(clvarlt[218], "ENG_NOISE");
    strcpy(clvarlt[219], "PREIGN_NOISE");
    strcpy(clvarlt[220], "NOISE_SOUND");
    strcpy(clvarlt[225], "ENG_NOISE");
    strcpy(clvarlt[226], "PREIGN_NOISE");
    strcpy(clvarlt[227], "NOISE_SOUND");
    strcpy(clvarlt[232], "ENG_NOISE");
    strcpy(clvarlt[233], "PREIGN_NOISE");
    strcpy(clvarlt[234], "NOISE_SOUND");
    strcpy(clvarlt[239], "FAIL_ACC");
    strcpy(clvarlt[240], "ARFLW_SNSR_MLFNCTN");
    strcpy(clvarlt[246], "FAIL_ACC");
    strcpy(clvarlt[247], "ARFLW_SNSR_MLFNCTN");
    strcpy(clvarlt[248], "OX_SNSR_MLFNCTN");
    strcpy(clvarlt[253], "FAIL_ACC");
    strcpy(clvarlt[254], "ARFLW_SNSR_MLFNCTN");
    strcpy(clvarlt[255], "OX_SNSR_MLFNCTN");
    strcpy(clvarlt[256], "THRTL_SNSR_MLFNCTN");
    strcpy(clvarlt[260], "FAIL_ACC");
    strcpy(clvarlt[261], "ARFLW_SNSR_MLFNCTN");
    strcpy(clvarlt[262], "OX_SNSR_MLFNCTN");
    strcpy(clvarlt[263], "THRTL_SNSR_MLFNCTN");
    strcpy(clvarlt[264], "CLG_FL_FLTR");
    strcpy(clvarlt[267], "FAIL_ACC");
    strcpy(clvarlt[268], "ARFLW_SNSR_MLFNCTN");
    strcpy(clvarlt[269], "OX_SNSR_MLFNCTN");
    strcpy(clvarlt[270], "THRTL_SNSR_MLFNCTN");
    strcpy(clvarlt[271], "CLG_FL_FLTR");
    strcpy(clvarlt[272], "DRTY_ARFLTR");
    strcpy(clvarlt[274], "FAIL_ACC");
    strcpy(clvarlt[275], "ARFLW_SNSR_MLFNCTN");
    strcpy(clvarlt[276], "OX_SNSR_MLFNCTN");
    strcpy(clvarlt[277], "THRTL_SNSR_MLFNCTN");
    strcpy(clvarlt[278], "CLG_FL_FLTR");
    strcpy(clvarlt[279], "DRTY_ARFLTR");
    
    for(i = 1; i < 41; i++)
    {
        printf("** CLAUSE %d\n", i);
        
        for(j = 1; j < 8; j++)
        {
            k = 7 * (i - 1) + j;
            printf("VARIABLE %d  %s\n", j, clvarlt[k]);
        }
        
        
        if (i == 20)
        {
            printf("HIT RETURN KEY TO CONTINUE");
            gets(buff);
        }
    }
    /****** inference section *****/
    printf("** ENTER CONCLUSION ? ");
    gets(varble);
    
b520: f = 1;
    determine_member_concl_list();
    if (sn != 0){
        do
        /* push statement number (sn) and clause number=1 on
         goal
         stack which is composed of the statement stack
         (statsk)
         and clause stack (clausk) */
        {
            push_on_stack();
            do
            {
                /* calculate clause location in clause-variable
                 list */
            b545: i = (statsk[sp] - 1) * 7 + clausk[sp];
                /* clause variable */
                strcpy(varble, clvarlt[i]);
                
                if(strcmp(varble, "") != 0) {
                    /*is this clause variable a conclusion? */
                    f = 1;
                    determine_member_concl_list();
                    if(sn != 0)
                    /* it is a conclusion push it */
                        goto b520;
                    /* check instantiation of this clause */
                    instantiate();
                    clausk[sp] = clausk[sp] + 1;
                }
            } while(strcmp(varble, "") != 0); /*do-while*/
            /*no more clauses check if part of statement */
            sn = statsk[sp];
            s = 0;
            /**** if then statements ****/
            /* sample if parts of if then statements from
             the position knowledge base */
            switch (sn) {
                    /* if part of statement 1 */
                    /****** comment 1500 ****/
                case 1:
                    if((strcmp(VIB_STR_WHL, "YES") == 0) && (strcmp(WHL_BAL, "YES") == 0))
                        s = 1;
                    break;
                    /* if part of statement 2 */
                    /***** comment 1510 ******/
                case 2:
                    if((strcmp(VIB_STR_WHL, "YES") == 0) && (strcmp(WHL_BAL, "NO") == 0))
                        s = 1;
                    break;
                    /* if part of statement 3 */
                case 3:
                    if((strcmp(SQK, "YES") == 0) && (strcmp(SQK_UB, "YES") == 0))
                        s = 1;
                    break;
                    /* if part of statement 4 */
                    /******** comment 1560 ******/
                case 4:
                    if((strcmp(SQK, "YES") == 0) && (strcmp(SQK_UB, "NO") == 0) && (strcmp(BRKPD_FD, "YES") == 0))
                        s = 1;
                    break;
                    /******** comment 1570 ********/
                    /* if part of statement 5 */
                case 5:
                    if((strcmp(SQK, "YES") == 0) && (strcmp(SQK_UB, "NO") == 0) && (strcmp(BRKPD_FD, "NO") == 0))
                        s = 1;
                    break;
                    /* if part of statement 6 */
                case 6:
                    if((strcmp(ENG_OVHT, "YES") == 0) && (strcmp(THRMST_FLT, "YES") == 0))
                        s = 1;
                    break;
                case 7:
                    if((strcmp(ENG_OVHT, "YES") == 0) && (strcmp(THRMST_FLT, "NO") == 0) && (strcmp(CLNT_LK, "YES") == 0))
                        s = 1;
                    break;
                case 8:
                    if((strcmp(ENG_OVHT, "YES") == 0) && (strcmp(THRMST_FLT, "NO") == 0) && (strcmp(CLNT_LK, "NO") == 0))
                        s = 1;
                    break;
                case 9:
                    if((strcmp(AC_NTWRK, "YES") == 0) && (strcmp(HOSE_LK, "YES") == 0))
                        s = 1;
                    break;
                case 10:
                    if((strcmp(AC_NTWRK, "YES") == 0) && (strcmp(HOSE_LK, "NO") == 0))
                        s = 1;
                    break;
                case 11:
                    if((strcmp(BATT_NTWRK, "YES") == 0) && (strcmp(BATT_NEW, "YES") == 0))
                        s = 1;
                    break;
                case 12:
                    if((strcmp(BATT_NTWRK, "YES") == 0) && (strcmp(BATT_NEW, "NO") == 0) && (BATT_LD_TST > 12.45))
                        s = 1;
                    break;
                case 13:
                    if((strcmp(BATT_NTWRK, "YES") == 0) && (strcmp(BATT_NEW, "NO") == 0) && (BATT_LD_TST <= 12.45))
                        s = 1;
                    break;
                case 14:
                    if((strcmp(FLT_TIRE, "YES") == 0) && (strcmp(TIRE_LK, "YES") == 0))
                        s = 1;
                    break;
                case 15:
                    if((strcmp(FLT_TIRE, "YES") == 0) && (strcmp(TIRE_LK, "NO") == 0))
                        s = 1;
                    break;
                case 16:
                    if((strcmp(EXST_SMK, "YES") == 0) && (strcmp(EXST_SMK_CL, "WHITE") == 0) && (strcmp(CLNT_LK, "YES") == 0))
                        s = 1;
                    break;
                case 17:
                    if((strcmp(EXST_SMK, "YES") == 0) && (strcmp(EXST_SMK_CL, "WHITE") == 0) && (strcmp(CLNT_LK, "NO") == 0))
                        s = 1;
                    break;
                case 18:
                    if((strcmp(EXST_SMK, "YES") == 0) && (strcmp(EXST_SMK_CL, "BLUE") == 0) && (strcmp(SMK_OCR, "BEFORE") == 0))
                        s = 1;
                    break;
                case 19:
                    if((strcmp(EXST_SMK, "YES") == 0) && (strcmp(EXST_SMK_CL, "BLUE") == 0) && (strcmp(SMK_OCR, "AFTER") == 0))
                        s = 1;
                    break;
                case 20:
                    if((strcmp(EXST_SMK, "YES") == 0) && (strcmp(EXST_SMK_CL, "BLUE") == 0) && (strcmp(SMK_OCR, "ALL TIME") == 0) && strcmp(PCV_OK, "YES") && strcmp(TRBO_WRK, "YES"))
                        s = 1;
                    break;
                case 21:
                    if((strcmp(EXST_SMK, "YES") == 0) && (strcmp(EXST_SMK_CL, "BLUE") == 0) && (strcmp(SMK_OCR, "ALL TIME") == 0) && strcmp(PCV_OK, "YES") && strcmp(TRBO_WRK, "NO"))
                        s = 1;
                    break;
                case 22:
                    if((strcmp(EXST_SMK, "YES") == 0) && (strcmp(EXST_SMK_CL, "BLUE") == 0) && (strcmp(SMK_OCR, "ALL TIME") == 0) && strcmp(PCV_OK, "NO"))
                        s = 1;
                    break;
                case 23:
                    if((strcmp(EXST_SMK, "YES") == 0) && (strcmp(EXST_SMK_CL, "BLACK") == 0) && (strcmp(FL_ODR_TLPIPE, "YES") == 0))
                        s = 1;
                    break;
                case 24:
                    if((strcmp(EXST_SMK, "YES") == 0) && (strcmp(EXST_SMK_CL, "BLACK") == 0) && (strcmp(FL_ODR_TLPIPE, "NO") == 0) && strcmp(DRTY_ARFLTR, "YES"))
                        s = 1;
                    break;
                case 25:
                    if((strcmp(EXST_SMK, "YES") == 0) && (strcmp(EXST_SMK_CL, "BLACK") == 0) && (strcmp(FL_ODR_TLPIPE, "NO") == 0) && strcmp(DRTY_ARFLTR, "NO") && strcmp(CRBN_BUILDUP, "YES"))
                        s = 1;
                    break;
                case 26:
                    if((strcmp(EXST_SMK, "YES") == 0) && (strcmp(EXST_SMK_CL, "BLACK") == 0) && (strcmp(FL_ODR_TLPIPE, "NO") == 0) && strcmp(DRTY_ARFLTR, "NO") && strcmp(CRBN_BUILDUP, "NO"))
                        s = 1;
                    break;
                case 27:
                    if((strcmp(ENG_NOISE, "YES") == 0) && (strcmp(PREIGN_NOISE, "YES") == 0) && (strcmp(SCND_SPT_NOISE, "YES") == 0))
                        s = 1;
                    break;
                case 28:
                    if((strcmp(ENG_NOISE, "YES") == 0) && (strcmp(PREIGN_NOISE, "YES") == 0) && (strcmp(SCND_SPT_NOISE, "NO") == 0) && (CMPR_RATIO > 14))
                        s = 1;
                    break;
                case 29:
                    if((strcmp(ENG_NOISE, "YES") == 0) && (strcmp(PREIGN_NOISE, "YES") == 0) && (strcmp(SCND_SPT_NOISE, "NO") == 0) && (CMPR_RATIO <= 14))
                        s = 1;
                    break;
                case 30:
                    if((strcmp(ENG_NOISE, "YES") == 0) && (strcmp(PREIGN_NOISE, "NO") == 0) && (strcmp(NOISE_SOUND, "CLICKING") == 0))
                        s = 1;
                    break;
                case 31:
                    if((strcmp(ENG_NOISE, "YES") == 0) && (strcmp(PREIGN_NOISE, "NO") == 0) && (strcmp(NOISE_SOUND, "KNOCKING") == 0))
                        s = 1;
                    break;
                case 32:
                    if((strcmp(ENG_NOISE, "YES") == 0) && (strcmp(PREIGN_NOISE, "NO") == 0) && (strcmp(NOISE_SOUND, "BELL") == 0))
                        s = 1;
                    break;
                case 33:
                    if((strcmp(ENG_NOISE, "YES") == 0) && (strcmp(PREIGN_NOISE, "NO") == 0) && (strcmp(NOISE_SOUND, "RUMBLING") == 0))
                        s = 1;
                    break;
                case 34:
                    if((strcmp(ENG_NOISE, "YES") == 0) && (strcmp(PREIGN_NOISE, "NO") == 0) && (strcmp(NOISE_SOUND, "RATTLING") == 0))
                        s = 1;
                    break;
                case 35:
                    if((strcmp(FAIL_ACC, "YES") == 0) && (strcmp(ARFLW_SNSR_MLFNCTN, "YES") == 0))
                        s = 1;
                    break;
                case 36:
                    if((strcmp(FAIL_ACC, "YES") == 0) && (strcmp(ARFLW_SNSR_MLFNCTN, "NO") == 0) && strcmp(OX_SNSR_MLFNCTN, "YES"))
                        s = 1;
                    break;
                case 37:
                    if((strcmp(FAIL_ACC, "YES") == 0) && (strcmp(ARFLW_SNSR_MLFNCTN, "NO") == 0) && strcmp(OX_SNSR_MLFNCTN, "NO") && strcmp(THRTL_SNSR_MLFNCTN, "YES"))
                        s = 1;
                    break;
                case 38:
                    if((strcmp(FAIL_ACC, "YES") == 0) && (strcmp(ARFLW_SNSR_MLFNCTN, "NO") == 0) && strcmp(OX_SNSR_MLFNCTN, "NO") && strcmp(THRTL_SNSR_MLFNCTN, "NO") && strcmp(CLG_FL_FLTR, "YES"))
                        s = 1;
                    break;
                case 39:
                    if((strcmp(FAIL_ACC, "YES") == 0) && (strcmp(ARFLW_SNSR_MLFNCTN, "NO") == 0) && strcmp(OX_SNSR_MLFNCTN, "NO") && strcmp(THRTL_SNSR_MLFNCTN, "NO") && strcmp(CLG_FL_FLTR, "NO") && strcmp(DRTY_ARFLTR, "YES"))
                        s = 1;
                    break;
                case 40:
                    if((strcmp(FAIL_ACC, "YES") == 0) && (strcmp(ARFLW_SNSR_MLFNCTN, "NO") == 0) && strcmp(OX_SNSR_MLFNCTN, "NO") && strcmp(THRTL_SNSR_MLFNCTN, "NO") && strcmp(CLG_FL_FLTR, "NO") && strcmp(DRTY_ARFLTR, "NO"))
                        s = 1;
                    break;
                    /********* comment 1680 ******/
            }
            /* see if the then part should be invoked */
            if( s != 1) {
                /* failed..search rest of statements for
                 same conclusion */
                /* get conclusion */
                i = statsk[sp];
                strcpy(varble, conclt[i]);
                /* search for conclusion starting at the
                 next statement number */
                f = statsk[sp] + 1;
                determine_member_concl_list();
                sp = sp + 1;
            }
            /* pop old conclusion and put on new one */
        } while((s != 1) && (sn !=0));  /* outer do-while loop */
        
        if(sn != 0){
            /* if part true invoke then part */
            /* then part of if-then statements from the
             position knowledge base */
            switch (sn) {
                    /* then part of statement 1 */
                    /******* comment 1500 *******/
                case 1: strcpy(FAULT, "YES");
                    printf("FAULT = FAULTY STEERING\n");
                    break;
                    /* then part of statement 2 */
                    /****** comment 1510 ******/
                case 2: strcpy(FAULT, "YES");
                    printf("FAULT = UNBALANCED WHEELS\n");
                    break;
                    /* then part of statement 3 */
                case 3: strcpy(FAULT, "YES");
                    printf("FAULT = SERPENTINE BELT SLIPPING\n");
                    break;
                    /* then part of statement 4 */
                    /******** comment 1560 ******/
                case 4: strcpy(FAULT, "YES");
                    printf("FAULT = FADED BRAKE PADS\n");
                    break;
                    /* then part of statement 5 */
                    /****** comment 1570 *****/
                case 5: strcpy(FAULT, "YES");
                    printf("FAULT = DUST ON DISKS/DRUMS\n");
                    break;
                    /* then part of statement 6 */
                case 6: strcpy(FAULT, "YES");
                    printf("FAULT = FAULTY THERMOSTAT\n");
                    break;
                    /****** comment 1680 ********/
                case 7: strcpy(FAULT, "YES");
                    printf("FAULT = COOLANT LEAKING\n");
                    break;
                case 8: strcpy(FAULT, "YES");
                    printf("FAULT = LOW COOLANT LEVEL\n");
                    break;
                case 9: strcpy(FAULT, "YES");
                    printf("FAULT = AC HOSE LEAKING\n");
                    break;
                case 10: strcpy(FAULT, "YES");
                    printf("FAULT = LOW REFRIGERANT\n");
                    break;
                case 11: strcpy(FAULT, "YES");
                    printf("FAULT = FAULTY ALTERNATOR\n");
                    break;
                case 12: strcpy(FAULT, "YES");
                    printf("FAULT = LOOSE BATTERY CONNECTION\n");
                    break;
                case 13: strcpy(FAULT, "YES");
                    printf("FAULT = DEAD BATTERY\n");
                    break;
                case 14: strcpy(FAULT, "YES");
                    printf("FAULT = BROKEN TIRE\n");
                    break;
                case 15: strcpy(FAULT, "YES");
                    printf("FAULT = LOW TIRE PRESSURE\n");
                    break;
                case 16: strcpy(FAULT, "YES");
                    printf("FAULT = COOLANT LEAKING\n");
                    break;
                case 17: strcpy(FAULT, "YES");
                    printf("FAULT = FAULTY GASKET\n");
                    break;
                case 18: strcpy(FAULT, "YES");
                    printf("FAULT = WORN VALVE SEALS\n");
                    break;
                case 19: strcpy(FAULT, "YES");
                    printf("FAULT = WORN PISTON RING\n");
                    break;
                case 20: strcpy(FAULT, "YES");
                    printf("FAULT = TRANSMISSION FLUID LOSS\n");
                    break;
                case 21: strcpy(FAULT, "YES");
                    printf("FAULT = BLOWN TURBO\n");
                    break;
                case 22: strcpy(FAULT, "YES");
                    printf("FAULT = STUCK PCV VALVE\n");
                    break;
                case 23: strcpy(FAULT, "YES");
                    printf("FAULT = MALFUNCTIONING FUEL INJECTOR\n");
                    break;
                case 24: strcpy(FAULT, "YES");
                    printf("FAULT = CLOGGED AIR FILTER\n");
                    break;
                case 25: strcpy(FAULT, "YES");
                    printf("FAULT = BLOCKED INTAKE MANIFOLD\n");
                    break;
                case 26: strcpy(FAULT, "YES");
                    printf("FAULT = LOW CYLINDER COMPRESSION\n");
                    break;
                case 27: strcpy(FAULT, "YES");
                    printf("FAULT = DIRTY ENGINE CYLINDER\n");
                    break;
                case 28: strcpy(FAULT, "YES");
                    printf("FAULT = HIGH COMPRESSION RATIO\n");
                    break;
                case 29: strcpy(FAULT, "YES");
                    printf("FAULT = ENGINE COOLANT SYSTEM PROBLEM\n");
                    break;
                case 30: strcpy(FAULT, "YES");
                    printf("FAULT = VALVE AND HYDRAULIC LIFTER PROBLEM\n");
                    break;
                case 31: strcpy(FAULT, "YES");
                    printf("FAULT = PISTON PIN PROBLEM\n");
                    break;
                case 32: strcpy(FAULT, "YES");
                    printf("FAULT = PISTON SLAP PROBLEM\n");
                    break;
                case 33: strcpy(FAULT, "YES");
                    printf("FAULT = CRANKSHAFT BEARING PROBLEM\n");
                    break;
                case 34: strcpy(FAULT, "YES");
                    printf("FAULT = LOOSE TIMING CHAIN\n");
                    break;
                case 35: strcpy(FAULT, "YES");
                    printf("FAULT = MASS AIR FLOW SENSOR MALFUNCTION\n");
                    break;
                case 36: strcpy(FAULT, "YES");
                    printf("FAULT = OXYGEN SENSOR PROBLEM\n");
                    break;
                case 37: strcpy(FAULT, "YES");
                    printf("FAULT = THROTTLE POSSITION SENSOR PROBLEM\n");
                    break;
                case 38: strcpy(FAULT, "YES");
                    printf("FAULT = DIRTY/CLOGGED FUEL FILTER\n");
                    break;
                case 39: strcpy(FAULT, "YES");
                    printf("FAULT = DIRTY OR CLOGGED AIR FILTER\n");
                    break;
                case 40: strcpy(FAULT, "YES");
                    printf("FAULT = FAILING OR BROKEN TIMING BELT\n");
                    break;
            }
            /* pop the stack */
            sp = sp + 1;
            if(sp >= 132)
            /* finished */
                printf("*** SUCCESS\n");
            else {
                /* stack is not empty */
                /* get next clause then continue */
                clausk[sp] = clausk[sp] + 1;
                goto b545;
            }
        }
    }
}

void determine_member_concl_list() {
    /* initially set to not a member */
    sn = 0;
    /* member of conclusion list to be searched is f */
    i = f;
    while((strcmp(varble, conclt[i]) != 0) && (i < 41))
    /* test for membership */
        i = i + 1;
    if (strcmp(varble, conclt[i]) == 0)
        sn = i;  /* a member */
    
    //printf("sn = %d\n", sn);
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
    /* find variable in the list */
    while((strcmp(varble, varlt[i]) != 0) && (i < 34))
        i = i + 1;
    
    if((strcmp(varble, varlt[i]) == 0) && (instlt[i] != 1))
    /*found variable and not already instantiated */
    {
        instlt[i] = 1; /*mark instantiated */
        /* the designer of the
         knowledge base places the input statements to
         instantiate the variables below in the case statement */
        switch (i)
        {
                /***** input statement *****/
                /* input statements for sample position knowledge
                 base */
                /***** comment 1700 ******/
            case 1: printf("INPUT YES OR NO FOR VIBRATING STEERING WHEEL? ");
                gets(VIB_STR_WHL);
                break;
            case 2: printf("INPUT YES OR NO FOR WHEEL BALANCE? ");
                gets(WHL_BAL);
                break;
            case 3: printf("INPUT YES OR NO FOR SQUEAK SOUND? ");
                gets(SQK);
                break;
            case 4: printf("INPUT YES OR NO FOR SQUEAK UNDER THE BONNET? ");
                gets(SQK_UB);
                break;
            case 5: printf("INPUT YES OR NO FOR BRAKE PAD FADED? ");
                gets(BRKPD_FD);
                break;
            case 6: printf("INPUT YES OR NO FOR ENGINE OVERHEATING? ");
                gets(ENG_OVHT);
                break;
            case 7: printf("INPUT YES OR NO FOR THERMOSTAT FAULT? ");
                gets(THRMST_FLT);
                break;
            case 8: printf("INPUT YES OR NO FOR COOLANT LEAKING? ");
                gets(CLNT_LK);
                break;
            case 9: printf("INPUT YES OR NO FOR AC FAILS WORKING? ");
                gets(AC_NTWRK);
                break;
            case 10: printf("INPUT YES OR NO FOR AC HOSE LEAKING? ");
                gets(HOSE_LK);
                break;
            case 11: printf("INPUT YES OR NO FOR BATTERY FAILS WORKING? ");
                gets(BATT_NTWRK);
                break;
            case 12: printf("INPUT YES OR NO FOR NEW BATTERY? ");
                gets(BATT_NEW);
                break;
            case 13: printf("INPUT A REAL NUMBER FOR BATTERY LOAD TEST IN VOLTS? ");
                scanf("%f", &BATT_LD_TST);
                getchar();
                break;
            case 14: printf("INPUT YES OR NO FOR FLAT TIRE? ");
                gets(FLT_TIRE);
                break;
            case 15: printf("INPUT YES OR NO FOR PUNCTURE OR LEAK IN THE TIRE? ");
                gets(TIRE_LK);
                break;
            case 16: printf("INPUT YES OR NO FOR EXHAUST SMOKE? ");
                gets(EXST_SMK);
                break;
            case 17: printf("INPUT WHITE OR BLUE OR BLACK FOR THE COLOR OF EXHAUST SMOKE? ");
                gets(EXST_SMK_CL);
                break;
            case 18: printf("INPUT BEFORE OR AFTER OR ALL TIME FOR WHEN THE SMOKE OCCUR? ");
                gets(SMK_OCR);
                break;
            case 19: printf("INPUT YES OR NO FOR WHETHER PCV VALVE WELL PERFORMING? ");
                gets(PCV_OK);
                break;
            case 20: printf("INPUT YES OR NO FOR WHETHER TURBO WELL PERFORMING? ");
                gets(TRBO_WRK);
                break;
            case 21: printf("INPUT YES OR NO FOR FOUL ODOR FROM TAILPIPE? ");
                gets(FL_ODR_TLPIPE);
                break;
            case 22: printf("INPUT YES OR NO FOR DIRTY AIR FILTER? ");
                gets(DRTY_ARFLTR);
                break;
            case 23: printf("INPUT YES OR NO FOR CARBON BUILDUP IN INTAKE MANIFOLD? ");
                gets(CRBN_BUILDUP);
                break;
            case 24: printf("INPUT YES OR NO FOR ENGINE NOISE? ");
                gets(ENG_NOISE);
                break;
            case 25: printf("INPUT YES OR NO FOR DENOTATION/PRE-IGNITION NOISE? ");
                gets(PREIGN_NOISE);
                break;
            case 26: printf("INPUT YES OR NO FOR SECOND SPOT NOISE? ");
                gets(SCND_SPT_NOISE);
                break;
            case 27: printf("INPUT A REAL NUMBER FOR COMPRESSION RATIO? ");
                scanf("%f", &CMPR_RATIO);
                getchar();
                break;
            case 28: printf("INPUT CLICKING OR KNOCKING OR BELL OR RUMBLING OR RATTLING FOR NOISE YOU HEARD? ");
                gets(NOISE_SOUND);
                break;
            case 29: printf("INPUT YES OR NO FOR ACCELERATING FAILURE? ");
                gets(FAIL_ACC);
                break;
            case 30: printf("INPUT YES OR NO FOR MALFUNCTIONED MASS AIR FLOW SENSOR? ");
                gets(ARFLW_SNSR_MLFNCTN);
                break;
            case 31: printf("INPUT YES OR NO FOR MALFUNCTIONED OXYGEN SENSOR? ");
                gets(OX_SNSR_MLFNCTN);
                break;
            case 32: printf("INPUT YES OR NO FOR MALFUNCTIONED THROTTLE POSITION SENSOR? ");
                gets(THRTL_SNSR_MLFNCTN);
                break;
            case 33: printf("INPUT YES OR NO FOR DIRTY/CLOGGED FUEL FILTER? ");
                gets(CLG_FL_FLTR);
                break;
                /***** comment 1715 ****/
        }
        /* end of inputs statements for sample position knowledge base */
    }
}
