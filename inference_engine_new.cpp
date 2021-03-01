# include <iostream>
#include <string>
#include <map>
#include <queue>

#define VAR_LST_SIZE 1
#define NUM_STATEMENTS 38
#define CLS_VAR_LIST_SIZE NUM_STATEMENTS * VAR_LST_SIZE


using namespace std;

map<string, string> varlt; // variable list

queue <string> cnvarq; // conclusion variable queue

string clvarlt[CLS_VAR_LIST_SIZE];    // clause var list 

struct clsVarPtr   // clause variable pointer
{
    int rnum;       // rule number
    int cnum;       // clause number
}; 

// NOTE: v is a global variable, and the prompt says to discourage the use of these, consider
// changing this later

string v;           // variable 
string fault;       // fault - to be considered our condition variable?
string repair;      // repair 

int i, j;  // loop vars 

// helper functions
bool check_instantiation(string key);
string instantiate(string key);
void print_structures(int option);
void execute_then(int snum);
bool check_rule(int snum);
void check_clauses(int snum);
bool present(string v, int snum);

int main()
{
    std::cout << "Hello WOrld" << std::endl;

    // ******** INITIALIZATION SECTION **********

    // initialize caluse variable list
    for (i=0;i < CLS_VAR_LIST_SIZE; i++)
        clvarlt[i] = "FAULT";
    // for (i=1;i < 11; i++)
       //  cndvar.push("");

    // FIXME verify thisvarlt.insert(pair<string, string>(fault, "")); 
    
    // enter variables which are in the IF part, 1 at a time in
    //the exact order that they occur. Up to 3 variables per
    //IF statement. Do not duplicate any variable names. Any
    //name is used only once. If no more variables left, just
    //hit return key 
    // ****** comment 367 ************
    // strcpy(varlt[1], "FAULT");      //our variable list only contains 1 variable, FAULT

    print_structures(3);

    // enter variables as they appear in the IF clauses, Up to 3 
    // variables per IF statement. If no more variables left, just
    // hit return key 
    // **** comment 407, 408 *************
    

    // ****** INFERENCE SECTION ****************

    cout << "Was there an issue diagnosed for the vehicle? Y/N" << endl;
    cin >> v;
    if (v == "N")
        cout << "Thank you for using the app. Good Bye." << endl;
    else if (v == "Y")
     {   
        cout << "Options for Fault:1/2/3" << endl;
        fault = instantiate("FAULT"); 
        cnvarq.push("FAULT");
        print_structures(2);
        while (!cnvarq.empty())
        {
            v = cnvarq.front();
            cnvarq.pop();
            for (int i = 0; i < NUM_STATEMENTS; ++i)
            {
                if(present(v, i)) 
                {
                    check_clauses(i);
                    if(check_rule(i))
                    {
                        execute_then(i);
                    }

                }
            }
        }

    }

    else
    {
        cout << "Invalid Option. Try Again" << endl;
    }

}

//==========================================================================
// Search clause variable list for a varialbe (clvarlt) equal to the
// one in front of the conclusion queue (cndvar). Return the statement
// number (sn). If there is no match, i.e., sn=0, the first statement
// for the space is f. 

// instantiate a variable to the given value
string instantiate(string key)
{
    string value;
    if (!check_instantiation(key))
    {
        cout << "Enter value for " << key << endl;
        cin >> value;
        varlt.insert(pair<string, string> (key, value));
    }
    return value;
}
//==========================================================================
// Routine to instantiate a variable (v) if it isn't already.
// The instantiate indication (instlt) is a 0 if not, a 1 if it is.
// The vriable list (varlt) contains the variable (v) 

//
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

void print_structures(int option)
{
    map<string, string>::iterator itr;

    if (option & 1)
    {
        printf("**CLAUSE VARIABLE LIST**\n");
    for (int i = 0; i < CLS_VAR_LIST_SIZE; ++i)
    {
        printf("CLAUSE VARIABLE [%d] %s \n", i, clvarlt[i].c_str());
    }
    cout << "PRESS ENTER TO CONTINUE" << endl;
    cin.get();

    }
     
    if (option & 2)
    {
        printf("**VARIABLE LIST**\n");
    for (itr = varlt.begin(); itr != varlt.end(); ++itr) { 
        cout << '\t' << itr->first 
             << '\t' << itr->second << '\n'; 
    } 
    cout << "PRESS ENTER TO CONTINUE" << endl;
    cin.get();
    }
}

void check_clauses(int snum)
{
    for (int i = 0; i < VAR_LST_SIZE; ++i)
    {
            instantiate(clvarlt[snum*VAR_LST_SIZE+i]);
    }

}

bool present(string var, int snum)
{
    for (int i = 0; i < VAR_LST_SIZE; ++i)
    {
        if(clvarlt[snum*VAR_LST_SIZE+i] == var)
            return true;
    }
    return false;
}



bool check_rule(int snum)
{
    switch(snum)
        {
        case 0: if (fault == "FAULTY_STEERING") return true; break;
        case 1: if (fault == "UNBALANCED_WHEELS") return true; break;
        case 2: if (fault == "SERPENTINE_BELT_SLIPPING") return true; break;
        case 3: if (fault == "FADED_BRAKE_PADS") return true; break;
        case 4: if (fault == "DUST_ON_DISKS/DRUMS") return true; break;
        case 5: if (fault == "FAULTY_THERMOSTAT") return true; break;
        case 6: if (fault == "COOLANT_LEAKING") return true; break;
        case 7: if (fault == "LOW_COOLANT_LEVEL") return true; break;
        case 8: if (fault == "AC_HOSE_LEAKING") return true; break;
        case 9: if (fault == "LOW_REFRIGERANT") return true; break;
        case 10: if (fault == "FAULTY_ALTERNATOR") return true; break;
        case 11: if (fault == "LOOSE_BATTERY_CONNECTION") return true; break;
        case 12: if (fault == "DEAD_BATTERY") return true; break;
        case 13: if (fault == "BROKEN_TIRE") return true; break;
        case 14: if (fault == "LOW_TIRE_PRESSURE") return true; break;
        case 15: if (fault == "FAULTY_GASKET") return true; break;
        case 16: if (fault == "WORN_VALVE_SEALS") return true; break;
        case 17: if (fault == "WORN_PISTON_RING") return true; break;
        case 18: if (fault == "TRANSMISSION_FLUID_LOSS") return true; break;
        case 19: if (fault == "BLOWN_TURBO") return true; break; break;
        case 20: if (fault == "STUCK_PCV_VALVE") return true; break;
        case 21: if (fault == "MALFUNCTIONING_FUEL_INJECTOR") return true; break;
        case 22: if (fault == "CLOGGED_AIR_FILTER") return true; break;
        case 23: if (fault == "BLOCKED_INTAKE_MANIFOLD") return true; break;
        case 24: if (fault == "LOW_CYLINDER_COMPRESSION") return true; break;
        case 25: if (fault == "DIRTY_ENGINE_CYLINDER") return true; break;
        case 26: if (fault == "HIGH_COMPRESSION_RATIO") return true; break;
        case 27: if (fault == "ENGINE_COOLANT_SYSTEM_PROBLEM") return true; break;
        case 28: if (fault == "VALVE_AND_HYDRAULIC_LIFTER_PROBLEM") return true; break;
        case 29: if (fault == "PISTON_PIN_PROBLEM") return true; break;
        case 30: if (fault == "PISTON_SLAP_PROBLEM") return true; break;
        case 31: if (fault == "CRANKSHAFT_BEARING_PROBLEM") return true; break;
        case 32: if (fault == "LOOSE_TIMING_CHAIN") return true; break;
        case 33: if (fault == "MASS_AIR_FLOW_SENSOR_MALFUNCTION") return true; break;
        case 34: if (fault == "OXYGEN_SENSOR_PROBLEM") return true; break;
        case 35: if (fault == "THROTTLE_POSITION_SENSOR_PROBLEM") return true; break;
        case 36: if (fault == "CLOGGED_FUEL_FILTER") return true; break;
        case 37: if (fault == "FAILING_OR_BROKEN_TIMING_BELT") return true; break;
    }
    return false;
}


void execute_then(int snum)
{
     switch (snum)
        {
        case 0:
            repair = "CHANGE STEERING";
            break;
        case 1:
            repair = "BALANCE THE WHEELS";
            break;
        case 2:
            repair = "REPLACE THE SERPENTINE BELT";
            break;
        case 3:
            repair = "REPLACE BRAKE PADS";
            break;
        case 4:
            repair = "CLEAN THE DISK OR DRUMS";
            break;
        case 5:
            repair = "REPLACE THERMOSTAT";
            break;
        case 6:
            repair = "SEAL THE COOLANT LEAK WITH SEALANT";
            break;
        case 7:
            repair = "FILL COOLANT TO THE REQUIRED LEVEL";
            break;
        case 8:
            repair = "FIX THE LEAK IN THE AC HOSE";
            break;
        case 9:
            repair = "FILL THE REFRIGERANT TO THE REQUIRED LEVEL";
            break;
        case 10:
            repair = "REPLACE THE ALTERNATOR";
            break;
        case 11:
            repair = "RECONNECT THE LOOSE CABLE";
            break;
        case 12:
            repair = "REPLACE BATTERY";
            break;
        case 13:
            repair = "SEAL THE TIRE LEAK";
            break;
        case 14:
            repair = "FILL UP THE TIRE";
            break;
        case 15:
            repair = "REPLACE THE GASKET";
            break;
        case 16:
            repair = "REPLACE THE VALVE SEALS";
            break;
        case 17:
            repair = "REPLACE PISTON RING";
            break;
        case 18:
            repair = "FIX TRANSMISSION MODULATOR";
            break;
        case 19:
            repair = "REPLACE THE TURBO";
            break;
        case 20:
            repair = "REPLACE THE PCV VALVE";
            break;
        case 21:
            repair = "REPLACE FUEL INJECTOR";
            break;
        case 22:
            repair = "REPLACE AIR FILTER";
            break;
        case 23:
            repair = "CLEAN THE INTAKE MANIFOLD";
            break;
        case 24:
            repair = "REPLACE THE LEAKING PART IN CYLINDER";
            break;
        case 25:
            repair = "CLEAN THE ENGINE CYLINDER";
            break;
        case 26:
            repair = "REDUCE COMPRESSION RATIO VIA VCR SYSTEM";
            break;
        case 27:
            repair = "FIX ENGINE COOLANT SYSTEM AND ADD COOLANT";
            break;
        case 28:
            repair = "REPLACE WORN LIFTERS";
            break;
        case 29:
            repair = "REPLACE THE PISTON PIN BUSHES";
            break;
        case 30:
            repair = "REPLACE THE PISTON";
            break;
        case 31:
            repair = "REPLACE THE BEARINGS";
            break;
        case 32:
            repair = "TIGHTEN THE TIMING CHAIN";
            break;
        case 33:
            repair = "CLEAN THE MASS AIR FLOW SENSOR";
            break;
        case 34:
            repair = "REPLACE THE OXYGEN SENSOR";
            break;
        case 35:
            repair = "REPLACE THE THROTTLE POSITION SENSOR";
            break;
        case 36:
            repair = "REPLACE THE FUEL FILTER";
            break;
        case 37:
            repair = "REPLACE THE TIMING BELT";
            break;
    }      
cout << "Suggested Repair: " << repair << endl;
cnvarq.push("REPAIR");
}


