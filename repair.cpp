#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

#define CONC_LIST_SIZE 40
#define VAR_LIST_SIZE 35
#define CLS_VAR_LIST_SIZE 280

string concLst[CONC_LIST_SIZE];         //conclusion list
string varLst[VAR_LIST_SIZE];           //variable list
string clsVarLst[CLS_VAR_LIST_SIZE];    //clause variable list

string vibStrWhl, whlBal, sqk, sqkUb, sqkWb, 
       brkpdFd, engOvht, thrmstFlt, clntPrb, clntLk, 
       acNtwrk, hoseLk, battNtwrk, battNew,
       fltTire, tireLk, exstSmk, exstSmkCl, smkOcr,
       pcvOk, trboWrk, flOdrTlpipe, drtyArfltr, crbnBuildup,
       engNoise, preignNoise, scndSpotNoise, comprRatio, noise,
       failAcc, arflwSnsrMalfnctn, oxSnsrMlfnctn, thrtlSnsrMlfnctn,
       clgFuelFltr;

float battLdTst;

//TODO: unsure what number should be for these
int instLst[11];    //instantiated list
int stateStk[11];   //statement stack
int clauseStk[11];  //clause stack
int sp;             //stack pointer
int sn, f, i, j, s, k;  //TODO: not sure what these vars are for yet


void determine_member_concl_list(); 
void push_on_stack(); 
void instantiate(); 


int main()
{
    /***** initialization section ******/ 
    /* stack space is 10 we initially place stack space at 10+1 */ 
    sp=11; 
    for (i=1; i<11; i++) 
    { 
        concLst[i]="";
        varLst[i]="";
        instLst[i]=0; 
        stateStk[i]=0; 
        clauseStk[i]=0; 
    }
    for (i=0; i<CLS_VAR_LIST_SIZE; i++) clsVarLst[i]="";

    /* enter conclusions which are the variables in the then part, 1 at 
    a time. enter the conclusions in exact order starting at the 1st 
    if-then. after last conclusion hit return key for rest of 
    conclusions */ 
    for (i=0; i<CONC_LIST_SIZE; i++) concLst[i] = "FAULT";

    cout << "*** CONCLUSION LIST ***\n"; 
    for (i=0; i<11; i++) 
        cout << "CONCLUSION " << i << " " << concLst[i] << endl;

    cout << "HIT RETURN TO CONTINUE";
}

int repair() {
    
    return 0;
}


int diagnosis() {
    
    return 0;
}



