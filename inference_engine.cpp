# include <iostream>
# include <string>

#define CLS_VAR_LIST_SIZE 280

/*  conclusion list */
char conclt[41][13];
/*  variable list */
char varlt[35][20];

char varble[20];
char buff[128];

char cndvar[10][3];
char varlt[10][3];                      /* variable list*/
char clvarlt[CLS_VAR_LIST_SIZE][20];    /* clause var list */
char c[3], vp[3];                       /* condition variable */  
char v[3];                              /* variable */
char FAULT[100];                        /* fault */

int instlt[132];        /* instantiated list */

int fp;                 /* front pointer */
int bp;                 /* back pointer */
int sn;                 /* statement number */
int cn;                 /* clause number */

int f, i, j, k, s;      /* loop vars */

void search(void);
void check_instantiation(void);
void instantiate(void);

int main()
{
    /******** INITIALIZATION SECTION ***********/
    fp=1;
    bp=1;

    for (i=0;i < CLS_VAR_LIST_SIZE; i++)
        strcpy(clvarlt[i], "");
    for (i=1;i < 11; i++)
        strcpy(cndvar[i], "");
    for (i=1;i < 11; i++)
        strcpy(instlt[i], "");
    for (i=1;i < 11; i++)
        strcpy(varlt[i], "");
    for (i=1;i < 11; I++)
    {
        strcpy(cndvar[i], "");
        strcpy(varlt[i], "");
        strcpy (instlt[i], "");
    }
    
    /* enter variables which are in the IF part, 1 at a time in
    the exact order that they occur. Up to 3 variables per
    IF statement. Do not duplicate any variable names. Any
    name is used only once. If no more variables left, just
    hit return key */
    /****** comment 367 *************/
    strcpy(varlt[1], "DO");
    strcpy(varlt[2], "FT");
    strcpy(varlt[3], "FM");
    strcpy(varlt[4], "IN");
    strcpy(varlt[5], "ST");

    
    printf("*** VARIABLE LIST ***\n");
    for (i=1;i < 11; i++)
        printf("ENTER VARIABLE   %d   %s\n", i, varlt[i]);
    printf("HIT RETURN TO CONTINUE");
    getchar();

    /* enter variables as they appear in the IF clauses, Up to 3 
    variables per IF statement. If no more variables left, just
    hit return key */
    /****** comment 407, 408 *************/
    strcpy(clvarlt[1], "IN");
    strcpy(clvarlt[5], "IN");
    strcpy(clvarlt[9], "DO");
    strcpy(clvarlt[13], "DO");
    strcpy(clvarlt[17], "FT");
    strcpy(clvarlt[18], "FM");
    printf("*** CLAUSE-VARIABLE LIST ***\n");
    for (i = 1; i < 9; i++)
    {
        printf("** CLAUSE %d\n", i);
        for (j = 1; j < 5; j++)
        {
            k = 4 * (i - 1) + j;
            printf("VARIABLE %d  %s\n", j, clvarlt[k]);
        }

        if (i==4)
        {
            printf("HIT RETURN TO CONTINUE");
            getchar();
        }
    }

    /****** INFERENCE SECTION *****************/
    printf("ENTER CONDITION VARIABLE? ");
    gets(c);
    /* place condition variable c on condition var queue cndvar */
    strcpy(cndvar[bp], c);
    /* move backpointer (bp) to back */
    bp = bp + 1;
    /* set the condition variable pointer consisting of the 
    statement number (sn) and the clause number (cn) */
    sn = 1; cn = 1;
    /* find the next statement number containing the condition variable
    which is in front of the queue (cndvar), this statement number
    is located in the clause variable list (clvarlt) */
    /* start at the beginning */
    f=1;
b496: search();
    /* point to first clause in statement */
    cn=1;
    if (sn != 0)
        /* more statements */
    {
        /* locate the clause */
        i = 4 * (sn-1) + cn;
        /* clause variable */
        strcpy(v, clvarlt[i]);
        /* are there any more clauses for this statement */
        while (strcmp(v, ""))
            /* more clauses */
        {
            /* check instantiation of this clause */
            check_instantiation();
            cn = cn+1;
            /* check next clause */
            i = 4 * (sn-1) + cn;
            strcpy(v, clvarlt[i]);
        }

        /* no more clauses - check IF part of statement */
        s = 0;
        /* sample IF-THEN statements from the position knowledge base */
        switch(sn)
        {
            /* statement 1 */
            /***** comment 1500 *****/
        case 1: if (strcmp(fault, "FAULTY STEERING") == 0) s=1;
            break;
            /* statement 2 */
            /***** comment 1510 *****/
        case 2: if (strcmp(fault, "UNBALANCED WHEELS") == 0) s=1;
            break;
            /* statement 3 */
            /***** comment 1540 *****/
        case 3: if (strcmp(dollar, "FALL") == 0) s=1;
            break;
            /* statement 4 */
            /***** comment 1550 *****/
        case 4: if (strcmp(dollar, "RISE") == 0) s=1;
            break;
            /* statement 5 */
        case 5: if ((strcmp(fedint, "FALL") == 0) &&
                    (strcmp(fedmon, "ADD")) == 0) s=1;
            break;
            /* statement 6 */
        case 6: if ((strcmp(qu, "YES") == 0) && (gr >= 3.5) == 0) s=1;
            break;
            /***** comment 1610 *****/
        }

        /* see if the THEN part should be inovked, i.e., s=1 */
        if (s != 1)
        {
            f = sn + 1;
            goto b496;
        }

        /* invoke THEN part */
        switch (sn)
        {
            /*********** comment 1500 ***********/
            /* put variable on the conclusion variable queue */
        case 1:
            strcpy(stock, "RISE");
            printf("ST=RISE\n");
            strcpy(v, "ST");
            instantiate();
            break;
            /*********** comment 1510 ***********/
            /* put variable on the conclusion variable queue */
        case 2:
            strcpy(stock, "FALL");
            printf("ST=FALL\n");
            strcpy(v, "ST");
            instantiate();
            break;
            /*********** comment 1540 ***********/
            /* put variable on the conclusion variable queue */
        case 3:
            strcpy(interest, "RISE");
            printf("IN=RISE\n");
            strcpy(v, "IN");
            instantiate();
            break;
            /*********** comment 1550 ***********/
            /* put variable on the conclusion variable queue */
        case 4:
            strcpy(interest, "FALL");
            printf("IN=FALL\n");
            strcpy(v, "IN");
            instantiate();
            break;
            /* put variable on the conclusion variable queue */
        case 5:
            strcpy(interest, "FALL");
            printf("IN=FALL\n");
            strcpy(v, "IN");
            instantiate();
            break;
        case 6:
            strcpy(po, "YES");
            printf("PO=YES\n");
            break;
            /*********** comment 1610 ***********/
        }
        f = sn + 1;
        goto b496;
    }

    /* no more clauses in the clause variable list (clvarlt)
    containing the variable in front of the queue (cndvar(fp))
    then remove front variable (cndvar(fp)) and replace it by
    the next variable (cndvar(fp+1)). If no more variables are
    at the front of the queue, stop. */
    /* next queue variable */
    fp=fp+1;
    if (fp < bp)
    {
        /* check out the condition variable */
        f = 1;
        goto b496;
    }
    /* no more conclusion variables on queue */
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
