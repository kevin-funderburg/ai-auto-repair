# include <iostream>
# include <string>

#define CLS_VAR_LIST_SIZE 76

/*  conclusion list */
char conclt[41][13];

/*

NOTES

- where is conclusion variable queue?
- where is clause variable pointer?

*/

char varlt[35][20];

char varble[20];
char buff[128];

char cndvar[10][3];
char varlt[10][20];                     /* variable list*/
char clvarlt[CLS_VAR_LIST_SIZE][20];    /* clause var list */
char c[3], vp[3];                       /* condition variable */  
char v[3];                              /* variable */
char FAULT[100];                        /* fault */

int instlt[132];    /* instantiated list */

int fp;             /* front pointer */
int bp;             /* back pointer */
int sn;             /* statement number */
int cn;             /* clause number */

int f, i, j, k, s;  /* loop vars */

void search(void);
void check_instantiation(void);
void instantiate(void);

int main()
{
    /******** INITIALIZATION SECTION ***********/
    fp=1;
    bp=1;

    for (i=1;i < CLS_VAR_LIST_SIZE; i++)
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
    strcpy(varlt[1], "FAULT");      //our variable list only contains 1 variable, FAULT

    
    printf("*** VARIABLE LIST ***\n");
    for (i=1;i < 11; i++)
        printf("ENTER VARIABLE   %d   %s\n", i, varlt[i]);
    printf("HIT RETURN TO CONTINUE");
    getchar();

    /* enter variables as they appear in the IF clauses, Up to 3 
    variables per IF statement. If no more variables left, just
    hit return key */
    /****** comment 407, 408 *************/
    
    // FLT is an abbreviated system response for FAULT, this is what the example does
    strcpy(clvarlt[1], "FLT");
    strcpy(clvarlt[3], "FLT");
    strcpy(clvarlt[5], "FLT");
    strcpy(clvarlt[7], "FLT");
    strcpy(clvarlt[8], "FLT");
    strcpy(clvarlt[9], "FLT");
    strcpy(clvarlt[11], "FLT");
    strcpy(clvarlt[15], "FLT");
    strcpy(clvarlt[17], "FLT");
    strcpy(clvarlt[19], "FLT");
    strcpy(clvarlt[21], "FLT");
    strcpy(clvarlt[23], "FLT");
    strcpy(clvarlt[25], "FLT");
    strcpy(clvarlt[27], "FLT");
    strcpy(clvarlt[29], "FLT");
    strcpy(clvarlt[31], "FLT");
    strcpy(clvarlt[33], "FLT");
    strcpy(clvarlt[35], "FLT");
    strcpy(clvarlt[37], "FLT");
    strcpy(clvarlt[39], "FLT");
    strcpy(clvarlt[41], "FLT");
    strcpy(clvarlt[43], "FLT");
    strcpy(clvarlt[45], "FLT");
    strcpy(clvarlt[47], "FLT");
    strcpy(clvarlt[49], "FLT");
    strcpy(clvarlt[51], "FLT");
    strcpy(clvarlt[53], "FLT");
    strcpy(clvarlt[55], "FLT");
    strcpy(clvarlt[57], "FLT");
    strcpy(clvarlt[59], "FLT");
    strcpy(clvarlt[61], "FLT");
    strcpy(clvarlt[63], "FLT");
    strcpy(clvarlt[65], "FLT");
    strcpy(clvarlt[67], "FLT");
    strcpy(clvarlt[69], "FLT");
    strcpy(clvarlt[71], "FLT");
    strcpy(clvarlt[73], "FLT");
    strcpy(clvarlt[75], "FLT");

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
        case 1: if (strcmp(fault, "FAULTY STEERING") == 0) s=1;
            break;
        case 2: if (strcmp(fault, "UNBALANCED WHEELS") == 0) s=1;
            break;
        case 3: if (strcmp(fault, "SERPENTINE BELT SLIPPING") == 0) s=1;
            break;
        case 4: if (strcmp(fault, "FADED BRAKE PADS") == 0) s=1;
            break;
        case 5: if (strcmp(fault, "DUST ON DISKS/DRUMS") == 0) s=1;
            break;
        case 6: if (strcmp(fault, "FAULTY THERMOSTAT") == 0) s=1;
            break;
        case 7: if (strcmp(fault, "COOLANT LEAKING") == 0) s=1;
            break;
        case 8: if (strcmp(fault, "LOW COOLANT LEVEL") == 0) s=1;
            break;
        case 9: if (strcmp(fault, "AC HOSE LEAKING") == 0) s=1;
            break;
        case 10: if (strcmp(fault, "LOW REFRIGERANT") == 0) s=1;
            break;
        case 11: if (strcmp(fault, "FAULTY ALTERNATOR") == 0) s=1;
            break;
        case 12: if (strcmp(fault, "LOOSE BATTERY CONNECTION") == 0) s=1;
            break;
        case 13: if (strcmp(fault, "DEAD BATTERY") == 0) s=1;
            break;
        case 14: if (strcmp(fault, "BROKEN TIRE") == 0) s=1;
            break;
        case 15: if (strcmp(fault, "LOW TIRE PRESSURE") == 0) s=1;
            break;
        case 16: if (strcmp(fault, "FAULTY GASKET") == 0) s=1;
            break;
        case 17: if (strcmp(fault, "WORN VALVE SEALS") == 0) s=1;
            break;
        case 18: if (strcmp(fault, "WORN PISTON RING") == 0) s=1;
            break;
        case 19: if (strcmp(fault, "TRANSMISSION FLUID LOSS") == 0) s=1;
            break;
        case 20: if (strcmp(fault, "BLOWN TURBO") == 0) s=1;
            break;
        case 21: if (strcmp(fault, "STUCK PCV VALVE") == 0) s=1;
            break;
        case 22: if (strcmp(fault, "MALFUNCTIONING FUEL INJECTOR") == 0) s=1;
            break;
        case 23: if (strcmp(fault, "CLOGGED AIR FILTER") == 0) s=1;
            break;
        case 24: if (strcmp(fault, "BLOCKED INTAKE MANIFOLD") == 0) s=1;
            break;
        case 25: if (strcmp(fault, "LOW CYLINDER COMPRESSION") == 0) s=1;
            break;
        case 26: if (strcmp(fault, "DIRTY ENGINE CYLINDER") == 0) s=1;
            break;
        case 27: if (strcmp(fault, "HIGH COMPRESSION RATIO") == 0) s=1;
            break;
        case 28: if (strcmp(fault, "ENGINE COOLANT SYSTEM PROBLEM") == 0) s=1;
            break;
        case 29: if (strcmp(fault, "VALVE AND HYDRAULIC LIFTER PROBLEM") == 0) s=1;
            break;
        case 30: if (strcmp(fault, "PISTON PIN PROBLEM") == 0) s=1;
            break;
        case 31: if (strcmp(fault, "PISTON SLAP PROBLEM") == 0) s=1;
            break;
        case 32: if (strcmp(fault, "CRANKSHAFT BEARING PROBLEM") == 0) s=1;
            break;
        case 33: if (strcmp(fault, "LOOSE TIMING CHAIN") == 0) s=1;
            break;
        case 34: if (strcmp(fault, "MASS AIR FLOW SENSOR MALFUNCTION") == 0) s=1;
            break;
        case 35: if (strcmp(fault, "OXYGEN SENSOR PROBLEM") == 0) s=1;
            break;
        case 36: if (strcmp(fault, "THROTTLE POSITION SENSOR PROBLEM") == 0) s=1;
            break;
        case 37: if (strcmp(fault, "CLOGGED FUEL FILTER") == 0) s=1;
            break;
        case 6: if (strcmp(fault, "FAILING OR BROKEN TIMING BELT") == 0) s=1;
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

//==========================================================================
/* Routine to instantiate a variable (v) if it isn't already.
The instantiate indication (instlt) is a 0 if not, a 1 if it is.
The vriable list (varlt) contains the variable (v) */
void check_instantiation()
{
    i=1;

    /* find variable in the variable list */
    while ((strcmp(v, varlt[i]) != 0) && (i <= 10)) i = i+1;

    /* check if already instantiated */
    if (instlt[i] != 1)
    {
        /* mark instantiated */
        instlt[i] = 1;
        /* the designer of this knowledge base places the input
        statements to instantiate the variables in this case
        statement */

        switch (i)
        {
            /* input statements for sample position knowledge base */
        case 1:
            printf("RISE OR FALL FOR DO? ");
            gets(dollar);
            break;
        case 2:
            printf("RISE OR FALL FOR FT? ");
            gets(fedint);
            break;
        case 3:
            printf("ADD OR SUBTRACT FOR FM? ");
            gets(fedmon);
            break;
        case 4:
            printf("RISE OR FALL FOR IN? ");
            gets(interest);
            break;
        case 5:
            printf("RISE OR FALL FOR ST? ");
            gets(stock);
            break;
        }
    }
    /* end of input statements for the position knowledge base */
}

//==========================================================================
/* Search clause variable list for a varialbe (clvarlt) equal to the
one in front of the conclusion queue (cndvar). Return the statement
number (sn). If there is no match, i.e., sn=0, the first statement
for the space is f. */
void search()
{
    flag = 0;
    sn = f;

    while ((flag == 0) && (sn <= 10))
    {
        cn=1;
        k = (sn-1)*4+cn;
        while ((strcmp(clvarlt[k], cndvar[fp]) != 0) && (cn < 4))
        {
            cn = cn+1;
            k = (sn-1)*4+cn;
        }

        if (strcmp(clvarlt[k], cndvar[fp]) == 0) flag = 1;
        if (flag == 0) sn = sn+1;
    }
    if (flag == 0) sn=0;
}

//==========================================================================
/* Routine to instantiate a varialbe (v) and then place it on the
back of the queu (cndvar[bp]), if it is not already there. */
void instantiate()
{
    i=1;
    /* find varialbe in the varialbe list (varlt) */
    while ((strcmp(v, varlt[i]) != 0) && (i <= 10)) i=i+1;

    /* instantiate it */
    instlt[i] = 1;
    i = 1;

    /* determine if (v) is or already has been on the queue (cndvar) */
    while ((strcmp(v, cndvar[i] != 0) && (i <= 10)) i=i+1;
    /* variable has not been on the queue. Store it in the back of the queue */
    if (strcmp(v, cndvar[i]) != 0)
    {
        strcpy(cndvar[bp], v);
        bp=bp+1;
    }
}