# include <iostream>
#include <string>
#include <map>
#include <queue>

#define CLS_VAR_LIST_SIZE 38
#define VAR_LST_SIZE 1

using namespace std;
/*  conclusion list */
// FIXME Verify Later // char conclt[41][13];

/*

NOTES

- where is conclusion variable queue?
- where is clause variable pointer?

*/
map<string, string> varlt; // variable list
// char varble[20];
// char buff[128];

queue <string> cnvarq; // conclusion variable queue

string clvarlt[CLS_VAR_LIST_SIZE];    // clause var list 
// FIXME char c[3], vp[3];                       // condition variable   

// NOTE: v is a global variable, and the prompt says to discourage the use of these, consider
// changing this later
string v;                          // variable 
string fault;                        // fault 
string repair;                       // repair 


int fp;             // front pointer 
int bp;             // back pointer 
int sn;             // statement number 
int cn;             // clause number 

int f, i, j, k, s;  // loop vars 

void search(string var);
bool check_instantiation(string key);
void instantiate(string key, string value);
void print_structures(void);

int main()
{
    std::cout << "Hello WOrld" << std::endl;

    // ******** INITIALIZATION SECTION **********
    fp=1;
    bp=1;

    for (i=0;i < CLS_VAR_LIST_SIZE; i++)
        clvarlt[i] = "FAULT";
    // for (i=1;i < 11; i++)
       //  cndvar.push("");
    // for (i=1;i < 11; i++)
       // strcpy(instlt[i], "");
    // for (i=1;i <= VAR_LST_SIZE; i++)
       // strcpy(varlt[i], "FAULT");

    // FIXME verify thisvarlt.insert(pair<string, string>(fault, "")); 
    
    // enter variables which are in the IF part, 1 at a time in
    //the exact order that they occur. Up to 3 variables per
    //IF statement. Do not duplicate any variable names. Any
    //name is used only once. If no more variables left, just
    //hit return key 
    // ****** comment 367 ************
    // strcpy(varlt[1], "FAULT");      //our variable list only contains 1 variable, FAULT

    print_structures();

    // enter variables as they appear in the IF clauses, Up to 3 
    // variables per IF statement. If no more variables left, just
    // hit return key 
    // **** comment 407, 408 *************
    

    // ****** INFERENCE SECTION ****************
    printf("What is the fault?\n");
    cin >> fault;

    if (!check_instantiation(fault))
    {
        varlt.insert(pair<string, string> ("FAULT", fault));
    }
        print_structures();

}
/*
    // place condition variable c on condition var queue cndvar 
    cnvarq.push("FAULT");


    // set the condition variable pointer consisting of the 
    // statement number (sn) and the clause number (cn) 
    sn = 0; cn = 0;
    // find the next statement number containing the condition variable
    // which is in front of the queue (cndvar), this statement number
    // is located in the clause variable list (clvarlt) 
    // start at the beginning 
    f=1;
b496: search();
    // point to first clause in statement 
    cn=0;
    if (sn != -1) // FIND THE ASSIGNMENT
        // more statements 
    {
        // locate the clause 
        i = cn/VAR_LST_SIZE + 1;
        // clause variable 
        strcpy(v, clvarlt[i]);
        // are there any more clauses for this statement 
        while (strcmp(v, ""))
            // more clauses 
        {
            // check instantiation of this clause 
            check_instantiation();
            cn = cn+1;
            // check next clause 
            i = 2 * (sn-1) + cn;
            strcpy(v, clvarlt[i]);
        }

        // no more clauses - check IF part of statement 
        s = 0;
        // sample IF-THEN statements from the position knowledge base 
        // FIXME change FAULT to fault and compare using c++ format
        switch(sn)
        {
        case 1: if (strcmp(FAULT, "FAULTY STEERING") == 0) s=1;
            break;
        case 2: if (strcmp(FAULT, "UNBALANCED WHEELS") == 0) s=1;
            break;
        case 3: if (strcmp(FAULT, "SERPENTINE BELT SLIPPING") == 0) s=1;
            break;
        case 4: if (strcmp(FAULT, "FADED BRAKE PADS") == 0) s=1;
            break;
        case 5: if (strcmp(FAULT, "DUST ON DISKS/DRUMS") == 0) s=1;
            break;
        case 6: if (strcmp(FAULT, "FAULTY THERMOSTAT") == 0) s=1;
            break;
        case 7: if (strcmp(FAULT, "COOLANT LEAKING") == 0) s=1;
            break;
        case 8: if (strcmp(FAULT, "LOW COOLANT LEVEL") == 0) s=1;
            break;
        case 9: if (strcmp(FAULT, "AC HOSE LEAKING") == 0) s=1;
            break;
        case 10: if (strcmp(FAULT, "LOW REFRIGERANT") == 0) s=1;
            break;
        case 11: if (strcmp(FAULT, "FAULTY ALTERNATOR") == 0) s=1;
            break;
        case 12: if (strcmp(FAULT, "LOOSE BATTERY CONNECTION") == 0) s=1;
            break;
        case 13: if (strcmp(FAULT, "DEAD BATTERY") == 0) s=1;
            break;
        case 14: if (strcmp(FAULT, "BROKEN TIRE") == 0) s=1;
            break;
        case 15: if (strcmp(FAULT, "LOW TIRE PRESSURE") == 0) s=1;
            break;
        case 16: if (strcmp(FAULT, "FAULTY GASKET") == 0) s=1;
            break;
        case 17: if (strcmp(FAULT, "WORN VALVE SEALS") == 0) s=1;
            break;
        case 18: if (strcmp(FAULT, "WORN PISTON RING") == 0) s=1;
            break;
        case 19: if (strcmp(FAULT, "TRANSMISSION FLUID LOSS") == 0) s=1;
            break;
        case 20: if (strcmp(FAULT, "BLOWN TURBO") == 0) s=1;
            break;
        case 21: if (strcmp(FAULT, "STUCK PCV VALVE") == 0) s=1;
            break;
        case 22: if (strcmp(FAULT, "MALFUNCTIONING FUEL INJECTOR") == 0) s=1;
            break;
        case 23: if (strcmp(FAULT, "CLOGGED AIR FILTER") == 0) s=1;
            break;
        case 24: if (strcmp(FAULT, "BLOCKED INTAKE MANIFOLD") == 0) s=1;
            break;
        case 25: if (strcmp(FAULT, "LOW CYLINDER COMPRESSION") == 0) s=1;
            break;
        case 26: if (strcmp(FAULT, "DIRTY ENGINE CYLINDER") == 0) s=1;
            break;
        case 27: if (strcmp(FAULT, "HIGH COMPRESSION RATIO") == 0) s=1;
            break;
        case 28: if (strcmp(FAULT, "ENGINE COOLANT SYSTEM PROBLEM") == 0) s=1;
            break;
        case 29: if (strcmp(FAULT, "VALVE AND HYDRAULIC LIFTER PROBLEM") == 0) s=1;
            break;
        case 30: if (strcmp(FAULT, "PISTON PIN PROBLEM") == 0) s=1;
            break;
        case 31: if (strcmp(FAULT, "PISTON SLAP PROBLEM") == 0) s=1;
            break;
        case 32: if (strcmp(FAULT, "CRANKSHAFT BEARING PROBLEM") == 0) s=1;
            break;
        case 33: if (strcmp(FAULT, "LOOSE TIMING CHAIN") == 0) s=1;
            break;
        case 34: if (strcmp(FAULT, "MASS AIR FLOW SENSOR MALFUNCTION") == 0) s=1;
            break;
        case 35: if (strcmp(FAULT, "OXYGEN SENSOR PROBLEM") == 0) s=1;
            break;
        case 36: if (strcmp(FAULT, "THROTTLE POSITION SENSOR PROBLEM") == 0) s=1;
            break;
        case 37: if (strcmp(FAULT, "CLOGGED FUEL FILTER") == 0) s=1;
            break;
        case 38: if (strcmp(FAULT, "FAILING OR BROKEN TIMING BELT") == 0) s=1;
            break;
            // **** comment 1610 ****
        }

        // see if the THEN part should be inovked, i.e., s=1 
        if (s != 1)
        {
            f = sn + 1;
            goto b496;
        }

        // invoke THEN part 
        switch (sn)
        {
            // ********** comment 1500 **********
            // put variable on the conclusion variable queue 
        case 1:
            strcpy(REPAIR, "CHANGE STEERING");
            printf("FLT=CHANGE STEERING\n");
            strcpy(v, "FLT");
            instantiate();
            break;
            // ********** comment 1510 **********
            // put variable on the conclusion variable queue 
        case 2:
            strcpy(REPAIR, "BALANCE THE WHEELS");
            printf("FLT=BALANCE THE WHEELS\n");
            strcpy(v, "FLT");
            instantiate();
            break;
            // ********** comment 1540 **********
            // put variable on the conclusion variable queue 
        case 3:
            strcpy(REPAIR, "REPLACE THE SERPENTINE BELT");
            printf("FLT=REPLACE THE SERPENTINE BELT\n");
            strcpy(v, "FLT");
            instantiate();
            break;
            // ********** comment 1550 **********
            // put variable on the conclusion variable queue 
        case 4:
            strcpy(REPAIR, "REPLACE BRAKE PADS");
            printf("FLT=REPLACE BRAKE PADS\n");
            strcpy(v, "FLT");
            instantiate();
            break;
            // put variable on the conclusion variable queue 
        case 5:
            strcpy(REPAIR, "CLEAN THE DISK OR DRUMS");
            printf("FLT=CLEAN THE DISK OR DRUMS\n");
            strcpy(v, "FLT");
            instantiate();
            break;
        case 6:
            strcpy(REPAIR, "REPLACE THERMOSTAT");
            printf("FLT=REPLACE THERMOSTAT\n");
            strcpy(v, "FLT");
            instantiate();
            break;
        case 7:
            strcpy(REPAIR, "SEAL THE COOLANT LEAK WITH SEALANT");
            printf("FLT=SEAL THE COOLANT LEAK WITH SEALANT\n");
            strcpy(v, "FLT");
            instantiate();
            break;
        case 8:
            strcpy(REPAIR, "FILL COOLANT TO THE REQUIRED LEVEL");
            printf("FLT=FILL COOLANT TO THE REQUIRED LEVEL\n");
            strcpy(v, "FLT");
            instantiate();
            break;
        case 9:
            strcpy(REPAIR, "FIX THE LEAK IN THE AC HOSE");
            printf("FLT=FIX THE LEAK IN THE AC HOSE\n");
            strcpy(v, "FLT");
            instantiate();
            break;
        case 10:
            strcpy(REPAIR, "FILL THE REFRIGERANT TO THE REQUIRED LEVEL");
            printf("FLT=FILL THE REFRIGERANT TO THE REQUIRED LEVEL\n");
            strcpy(v, "FLT");
            instantiate();
            break;
        case 11:
            strcpy(REPAIR, "REPLACE THE ALTERNATOR");
            printf("FLT=REPLACE THE ALTERNATOR\n");
            strcpy(v, "FLT");
            instantiate();
            break;
        case 12:
            strcpy(REPAIR, "RECONNECT THE LOOSE CABLE");
            printf("FLT=RECONNECT THE LOOSE CABLE\n");
            strcpy(v, "FLT");
            instantiate();
            break;
        case 13:
            strcpy(REPAIR, "REPLACE BATTERY");
            printf("FLT=REPLACE BATTERY\n");
            strcpy(v, "FLT");
            instantiate();
            break;
        case 14:
            strcpy(REPAIR, "SEAL THE TIRE LEAK");
            printf("FLT=SEAL THE TIRE LEAK\n");
            strcpy(v, "FLT");
            instantiate();
            break;
        case 15:
            strcpy(REPAIR, "FILL UP THE TIRE");
            printf("FLT=FILL UP THE TIRE\n");
            strcpy(v, "FLT");
            instantiate();
            break;
        case 16:
            strcpy(REPAIR, "REPLACE THE GASKET");
            printf("FLT=REPLACE THE GASKET\n");
            strcpy(v, "FLT");
            instantiate();
            break;
        case 17:
            strcpy(REPAIR, "REPLACE THE VALVE SEALS");
            printf("FLT=REPLACE THE VALVE SEALS\n");
            strcpy(v, "FLT");
            instantiate();
            break;
        case 18:
            strcpy(REPAIR, "REPLACE PISTON RING");
            printf("FLT=REPLACE PISTON RING\n");
            strcpy(v, "FLT");
            instantiate();
            break;
        case 19:
            strcpy(REPAIR, "FIX TRANSMISSION MODULATOR");
            printf("FLT=FIX TRANSMISSION MODULATOR\n");
            strcpy(v, "FLT");
            instantiate();
            break;
        case 20:
            strcpy(REPAIR, "REPLACE THE TURBO");
            printf("FLT=REPLACE THE TURBO\n");
            strcpy(v, "FLT");
            instantiate();
            break;
        case 21:
            strcpy(REPAIR, "REPLACE THE PCV VALVE");
            printf("FLT=REPLACE THE PCV VALVE\n");
            strcpy(v, "FLT");
            instantiate();
            break;
        case 22:
            strcpy(REPAIR, "REPLACE FUEL INJECTOR");
            printf("FLT=REPLACE FUEL INJECTOR\n");
            strcpy(v, "FLT");
            instantiate();
            break;
        case 23:
            strcpy(REPAIR, "REPLACE AIR FILTER");
            printf("FLT=REPLACE AIR FILTER\n");
            strcpy(v, "FLT");
            instantiate();
            break;
        case 24:
            strcpy(REPAIR, "CLEAN THE INTAKE MANIFOLD");
            printf("FLT=CLEAN THE INTAKE MANIFOLD\n");
            strcpy(v, "FLT");
            instantiate();
            break;
        case 25:
            strcpy(REPAIR, "REPLACE THE LEAKING PART IN CYLINDER");
            printf("FLT=REPLACE THE LEAKING PART IN CYLINDER\n");
            strcpy(v, "FLT");
            instantiate();
            break;
        case 26:
            strcpy(REPAIR, "CLEAN THE ENGINE CYLINDER");
            printf("FLT=CLEAN THE ENGINE CYLINDER\n");
            strcpy(v, "FLT");
            instantiate();
            break;
        case 27:
            strcpy(REPAIR, "REDUCE COMPRESSION RATIO VIA VCR SYSTEM");
            printf("FLT=REDUCE COMPRESSION RATIO VIA VCR SYSTEM\n");
            strcpy(v, "FLT");
            instantiate();
            break;
        case 28:
            strcpy(REPAIR, "FIX ENGINE COOLANT SYSTEM AND ADD COOLANT");
            printf("FLT=FIX ENGINE COOLANT SYSTEM AND ADD COOLANT\n");
            strcpy(v, "FLT");
            instantiate();
            break;
        case 29:
            strcpy(REPAIR, "REPLACE WORN LIFTERS");
            printf("FLT=REPLACE WORN LIFTERS\n");
            strcpy(v, "FLT");
            instantiate();
            break;
        case 30:
            strcpy(REPAIR, "REPLACE THE PISTON PIN BUSHES");
            printf("FLT=REPLACE THE PISTON PIN BUSHES\n");
            strcpy(v, "FLT");
            instantiate();
            break;
        case 31:
            strcpy(REPAIR, "REPLACE THE PISTON");
            printf("FLT=REPLACE THE PISTON\n");
            strcpy(v, "FLT");
            instantiate();
            break;
        case 32:
            strcpy(REPAIR, "REPLACE THE BEARINGS");
            printf("FLT=REPLACE THE BEARINGS\n");
            strcpy(v, "FLT");
            instantiate();
            break;
        case 33:
            strcpy(REPAIR, "TIGHTEN THE TIMING CHAIN");
            printf("FLT=TIGHTEN THE TIMING CHAIN\n");
            strcpy(v, "FLT");
            instantiate();
            break;
        case 34:
            strcpy(REPAIR, "CLEAN THE MASS AIR FLOW SENSOR");
            printf("FLT=CLEAN THE MASS AIR FLOW SENSOR\n");
            strcpy(v, "FLT");
            instantiate();
            break;
        case 35:
            strcpy(REPAIR, "REPLACE THE OXYGEN SENSOR");
            printf("FLT=REPLACE THE OXYGEN SENSOR\n");
            strcpy(v, "FLT");
            instantiate();
            break;
        case 36:
            strcpy(REPAIR, "REPLACE THE THROTTLE POSITION SENSOR");
            printf("FLT=REPLACE THE THROTTLE POSITION SENSOR\n");
            strcpy(v, "FLT");
            instantiate();
            break;
        case 37:
            strcpy(REPAIR, "REPLACE THE FUEL FILTER");
            printf("FLT=REPLACE THE FUEL FILTER\n");
            strcpy(v, "FLT");
            instantiate();
            break;
        case 38:
            strcpy(REPAIR, "REPLACE THE TIMING BELT");
            printf("FLT=REPLACE THE TIMING BELT\n");
            strcpy(v, "FLT");
            instantiate();
            break;
            // ********** comment 1610 **********
        }
        f = sn + 1;
        goto b496;
    }

    // no more clauses in the clause variable list (clvarlt)
    containing the variable in front of the queue (cndvar(fp))
    then remove front variable (cndvar(fp)) and replace it by
    the next variable (cndvar(fp+1)). If no more variables are
    at the front of the queue, stop. 
    // next queue variable 
    fp=fp+1;
    if (fp < bp)
    {
        // check out the condition variable 
        f = 1;
        goto b496;
    }
    // no more conclusion variables on queue 
}

*/
//==========================================================================
// Routine to instantiate a variable (v) if it isn't already.
// The instantiate indication (instlt) is a 0 if not, a 1 if it is.
// The vriable list (varlt) contains the variable (v) 
bool check_instantiation(string key)
{
        map<string, string>::iterator itr; 
            for (itr = varlt.begin(); itr != varlt.end(); ++itr) { 
        if ((itr->first == key) and (itr->second != ""))
        return true;

    }
        return false;
    // end of input statements for the position knowledge base 
}
/*
//==========================================================================
// Search clause variable list for a varialbe (clvarlt) equal to the
// one in front of the conclusion queue (cndvar). Return the statement
// number (sn). If there is no match, i.e., sn=0, the first statement
// for the space is f. 
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
// Routine to instantiate a varialbe (v) and then place it on the
// back of the queu (cndvar[bp]), if it is not already there. 
void instantiate()
{
    i=1;
    // find varialbe in the varialbe list (varlt) 
    while ((strcmp(v, varlt[i]) != 0) && (i <= 10)) i=i+1;

    // instantiate it 
    instlt[i] = 1;
    i = 1;

    // determine if (v) is or already has been on the queue (cndvar) 
    while ((strcmp(v, cndvar[i] != 0) && (i <= 10)) i=i+1;
    // variable has not been on the queue. Store it in the back of the queue 
    if (strcmp(v, cndvar[i]) != 0)
    {
        strcpy(cndvar[bp], v);
        bp=bp+1;
    }
}


*/

void print_structures()
{
    map<string, string>::iterator itr; 

    printf("**CLAUSE VARIABLE LIST**\n");
    for (int i = 0; i < CLS_VAR_LIST_SIZE; ++i)
    {
        printf("clvarlt[%d] = %s \n", i, clvarlt[i].c_str());
    }

    printf("**VARIABLE LIST**\n");
    for (itr = varlt.begin(); itr != varlt.end(); ++itr) { 
        cout << '\t' << itr->first 
             << '\t' << itr->second << '\n'; 
    } 
    

}