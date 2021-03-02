#include "inference_engine.h"

// instantiates a variable to the given value
string Inference_engine::instantiate(string key)
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


// returns true if the variable has already been instantiated, else returns false
bool Inference_engine::check_instantiation(string key)
{
    map<string, string>::iterator itr; 
    for (itr = varlt.begin(); itr != varlt.end(); ++itr) { 
        if ((itr->first == key) and (itr->second != ""))
            return true;

    }
    return false;
}


// prints clause variable list if option = 1 or 3, prints variable list if option = 2 or 3
void Inference_engine::print_structures(int option)
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


// checks if all he clauses of the given rule are instantiated. Instantiates the clause in case it's not
void Inference_engine::check_clauses(int snum)
{
    for (int i = 0; i < VAR_LST_SIZE; ++i)
    {
            instantiate(clvarlt[snum*VAR_LST_SIZE+i]);
    }

}


// returns true if a variable matches any of the clauses in the given rule number
bool Inference_engine::present(string var, int snum)
{
    for (int i = 0; i < VAR_LST_SIZE; ++i)
    {
        if(clvarlt[snum*VAR_LST_SIZE+i] == var)
            return true;
    }
    return false;
}


// returns true if the condition variable matches the value of fault in the given rule
bool Inference_engine::check_rule(int snum)
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

// returns the value of repair for the given fault
void Inference_engine::execute_then(int snum)
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

int main()
{
    int i; // loop variable
    string v; // condition variable
    Inference_engine inference; 

    // initialize caluse variable list
    for (i=0;i < CLS_VAR_LIST_SIZE; i++)
        inference.clvarlt[i] = "FAULT";
    

    inference.print_structures(1); // prints the clause variable list


    // does the machine need a repair?
    cout << "Was there an issue diagnosed for the vehicle? Y/N" << endl;
    cin >> v;
    if (v == "N" | v == "n")
        cout << "Thank you for using the app. Good Bye." << endl;
    else if (v == "Y" | v == "y")
     {   
        cout << "Options for Fault:" << endl // asking for the value of fault
            << "FAULTY_STEERING" << endl
            << "UNBALANCED_WHEELS" << endl
            << "SERPENTINE_BELT_SLIPPING" << endl
            << "FADED_BRAKE_PADS" << endl
            << "DUST_ON_DISKS/DRUMS" << endl
            << "FAULTY_THERMOSTAT" << endl
            << "COOLANT_LEAKING" <<endl
            << "LOW_COOLANT_LEVEL" << endl
            << "AC_HOSE_LEAKING" << endl
            << "LOW_REFRIGERANT" << endl
            << "FAULTY_ALTERNATOR" << endl
            << "LOOSE_BATTERY_CONNECTION" << endl
            << "DEAD_BATTERY" << endl
            << "BROKEN_TIRE" << endl
            << "LOW_TIRE_PRESSURE" << endl
            << "FAULTY_GASKET" << endl
            << "WORN_VALVE_SEALS" << endl
            << "WORN_PISTON_RING" << endl
            << "TRANSMISSION_FLUID_LOSS" << endl
            << "BLOWN_TURBO" << endl
            << "STUCK_PCV_VALVE" << endl
            << "MALFUNCTIONING_FUEL_INJECTOR" << endl
            << "CLOGGED_AIR_FILTER" << endl
            << "BLOCKED_INTAKE_MANIFOLD" << endl
            << "LOW_CYLINDER_COMPRESSION" << endl
            << "DIRTY_ENGINE_CYLINDER" << endl
            << "HIGH_COMPRESSION_RATIO" << endl
            << "ENGINE_COOLANT_SYSTEM_PROBLEM" << endl
            << "VALVE_AND_HYDRAULIC_LIFTER_PROBLEM" << endl
            << "PISTON_PIN_PROBLEM" << endl
            << "PISTON_SLAP_PROBLEM" << endl
            << "CRANKSHAFT_BEARING_PROBLEM" << endl
            << "LOOSE_TIMING_CHAIN" << endl
            << "MASS_AIR_FLOW_SENSOR_MALFUNCTION" << endl
            << "OXYGEN_SENSOR_PROBLEM" << endl
            << "THROTTLE_POSITION_SENSOR_PROBLEM" << endl
            << "CLOGGED_FUEL_FILTER" << endl
            << "FAILING_OR_BROKEN_TIMING_BELT" << endl;
        inference.fault = inference.instantiate("FAULT"); 
        inference.cnvarq.push("FAULT"); // push to conclusion variable queue
        inference.print_structures(2);  // prints only the variable list
        while (!inference.cnvarq.empty()) 
        {
            v = inference.cnvarq.front();
            inference.cnvarq.pop();
            for (int i = 0; i < NUM_STATEMENTS; ++i)
            {
                if(inference.present(v, i)) 
                {
                    inference.check_clauses(i);
                    if(inference.check_rule(i))
                    {
                        inference.execute_then(i);
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

