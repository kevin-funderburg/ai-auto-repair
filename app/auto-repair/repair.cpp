#include <QtGui>

#include "repair.h"

Repair::Repair(QString diag) : diagnosis(diag)
{   
    // initialize caluse variable list
    for (int i=0;i < CLS_VAR_LIST_SIZE; i++)
        clvarlt[i] = "FAULT";

    print_structures(CLS_VAR_LIST);
}


QString Repair::getResult() { return result; }


void Repair::inference()
{
    QString v;
    instantiate("FAULT"); 
    cnvarq.enqueue("FAULT");    // push to conclusion variable queue
    print_structures(VAR_LIST);
    while (!cnvarq.empty())
    {
        v = cnvarq.head();
        cnvarq.dequeue();
        for (int i = 0; i < NUM_STATEMENTS; ++i)
        {
            if (present(v, i)) 
            {
                check_clauses(i);
                if(check_rule(i))
                    execute_then(i);
            }
        }
    }
    qDebug() << "*** done ***";
}


//==========================================================================
// Routine to instantiate a variable (v) if it isn't already.
// The instantiate indication (instlt) is a 0 if not, a 1 if it is.
// The vriable list (varlt) contains the variable (v) 
bool Repair::check_instantiation(QString key)
{
    if (!varlt.contains(key)) return false;
    return varlt.value(key) == "";
}


void Repair::instantiate(QString key)
{
    if (!check_instantiation(key))
        varlt.insert(key, diagnosis);
}


void Repair::print_structures(printOptions option)
{
    QMap<QString, QString>::const_iterator i = varlt.constBegin();

    if (option == CLS_VAR_LIST || option == ALL)
    {
        qDebug() << "\n\n**CLAUSE VARIABLE LIST**";
        for (int i = 0; i < CLS_VAR_LIST_SIZE; ++i)
            qDebug() << "CLAUSE VARIABLE " << i << clvarlt[i];
    }
    if (option == VAR_LIST || option == ALL)
    {
        qDebug() << "\n\n**VARIABLE LIST**";
        while (i != varlt.constEnd())
        {
            qDebug() << '\t' << i.key() << '\t' << i.value(); 
            i++;
        }
    }
}


// checks if all the clauses of the given rule are instantiated. Instantiates the clause in case it's not
void Repair::check_clauses(int snum)
{
    for (int i = 0; i < VAR_LST_SIZE; ++i)
        instantiate(clvarlt[snum*VAR_LST_SIZE+i]);

}


// returns true if a variable matches any of the clauses in the given rule number
bool Repair::present(QString var, int snum)
{
    for (int i = 0; i < VAR_LST_SIZE; ++i)
        if(clvarlt[snum*VAR_LST_SIZE+i] == var)
            return true;
    return false;
}


bool Repair::check_rule(int snum)
{
    switch(snum)
    {
        case 0: if (diagnosis == "FAULTY_STEERING") return true; break;
        case 1: if (diagnosis == "UNBALANCED_WHEELS") return true; break;
        case 2: if (diagnosis == "SERPENTINE_BELT_SLIPPING") return true; break;
        case 3: if (diagnosis == "FADED_BRAKE_PADS") return true; break;
        case 4: if (diagnosis == "DUST_ON_DISKS/DRUMS") return true; break;
        case 5: if (diagnosis == "FAULTY_THERMOSTAT") return true; break;
        case 6: if (diagnosis == "COOLANT_LEAKING") return true; break;
        case 7: if (diagnosis == "LOW_COOLANT_LEVEL") return true; break;
        case 8: if (diagnosis == "AC_HOSE_LEAKING") return true; break;
        case 9: if (diagnosis == "LOW_REFRIGERANT") return true; break;
        case 10: if (diagnosis == "FAULTY_ALTERNATOR") return true; break;
        case 11: if (diagnosis == "LOOSE_BATTERY_CONNECTION") return true; break;
        case 12: if (diagnosis == "DEAD_BATTERY") return true; break;
        case 13: if (diagnosis == "BROKEN_TIRE") return true; break;
        case 14: if (diagnosis == "LOW_TIRE_PRESSURE") return true; break;
        case 15: if (diagnosis == "FAULTY_GASKET") return true; break;
        case 16: if (diagnosis == "WORN_VALVE_SEALS") return true; break;
        case 17: if (diagnosis == "WORN_PISTON_RING") return true; break;
        case 18: if (diagnosis == "TRANSMISSION_FLUID_LOSS") return true; break;
        case 19: if (diagnosis == "BLOWN_TURBO") return true; break; break;
        case 20: if (diagnosis == "STUCK_PCV_VALVE") return true; break;
        case 21: if (diagnosis == "MALFUNCTIONING_FUEL_INJECTOR") return true; break;
        case 22: if (diagnosis == "CLOGGED_AIR_FILTER") return true; break;
        case 23: if (diagnosis == "BLOCKED_INTAKE_MANIFOLD") return true; break;
        case 24: if (diagnosis == "LOW_CYLINDER_COMPRESSION") return true; break;
        case 25: if (diagnosis == "DIRTY_ENGINE_CYLINDER") return true; break;
        case 26: if (diagnosis == "HIGH_COMPRESSION_RATIO") return true; break;
        case 27: if (diagnosis == "ENGINE_COOLANT_SYSTEM_PROBLEM") return true; break;
        case 28: if (diagnosis == "VALVE_AND_HYDRAULIC_LIFTER_PROBLEM") return true; break;
        case 29: if (diagnosis == "PISTON_PIN_PROBLEM") return true; break;
        case 30: if (diagnosis == "PISTON_SLAP_PROBLEM") return true; break;
        case 31: if (diagnosis == "CRANKSHAFT_BEARING_PROBLEM") return true; break;
        case 32: if (diagnosis == "LOOSE_TIMING_CHAIN") return true; break;
        case 33: if (diagnosis == "MASS_AIR_FLOW_SENSOR_MALFUNCTION") return true; break;
        case 34: if (diagnosis == "OXYGEN_SENSOR_PROBLEM") return true; break;
        case 35: if (diagnosis == "THROTTLE_POSITION_SENSOR_PROBLEM") return true; break;
        case 36: if (diagnosis == "CLOGGED_FUEL_FILTER") return true; break;
        case 37: if (diagnosis == "FAILING_OR_BROKEN_TIMING_BELT") return true; break;
    }
    return false;
}


void Repair::execute_then(int snum)
{
     switch (snum)
    {
        case 0:
            result = "CHANGE STEERING";
            break;
        case 1:
            result = "BALANCE THE WHEELS";
            break;
        case 2:
            result = "REPLACE THE SERPENTINE BELT";
            break;
        case 3:
            result = "REPLACE BRAKE PADS";
            break;
        case 4:
            result = "CLEAN THE DISK OR DRUMS";
            break;
        case 5:
            result = "REPLACE THERMOSTAT";
            break;
        case 6:
            result = "SEAL THE COOLANT LEAK WITH SEALANT";
            break;
        case 7:
            result = "FILL COOLANT TO THE REQUIRED LEVEL";
            break;
        case 8:
            result = "FIX THE LEAK IN THE AC HOSE";
            break;
        case 9:
            result = "FILL THE REFRIGERANT TO THE REQUIRED LEVEL";
            break;
        case 10:
            result = "REPLACE THE ALTERNATOR";
            break;
        case 11:
            result = "RECONNECT THE LOOSE CABLE";
            break;
        case 12:
            result = "REPLACE BATTERY";
            break;
        case 13:
            result = "SEAL THE TIRE LEAK";
            break;
        case 14:
            result = "FILL UP THE TIRE";
            break;
        case 15:
            result = "REPLACE THE GASKET";
            break;
        case 16:
            result = "REPLACE THE VALVE SEALS";
            break;
        case 17:
            result = "REPLACE PISTON RING";
            break;
        case 18:
            result = "FIX TRANSMISSION MODULATOR";
            break;
        case 19:
            result = "REPLACE THE TURBO";
            break;
        case 20:
            result = "REPLACE THE PCV VALVE";
            break;
        case 21:
            result = "REPLACE FUEL INJECTOR";
            break;
        case 22:
            result = "REPLACE AIR FILTER";
            break;
        case 23:
            result = "CLEAN THE INTAKE MANIFOLD";
            break;
        case 24:
            result = "REPLACE THE LEAKING PART IN CYLINDER";
            break;
        case 25:
            result = "CLEAN THE ENGINE CYLINDER";
            break;
        case 26:
            result = "REDUCE COMPRESSION RATIO VIA VCR SYSTEM";
            break;
        case 27:
            result = "FIX ENGINE COOLANT SYSTEM AND ADD COOLANT";
            break;
        case 28:
            result = "REPLACE WORN LIFTERS";
            break;
        case 29:
            result = "REPLACE THE PISTON PIN BUSHES";
            break;
        case 30:
            result = "REPLACE THE PISTON";
            break;
        case 31:
            result = "REPLACE THE BEARINGS";
            break;
        case 32:
            result = "TIGHTEN THE TIMING CHAIN";
            break;
        case 33:
            result = "CLEAN THE MASS AIR FLOW SENSOR";
            break;
        case 34:
            result = "REPLACE THE OXYGEN SENSOR";
            break;
        case 35:
            result = "REPLACE THE THROTTLE POSITION SENSOR";
            break;
        case 36:
            result = "REPLACE THE FUEL FILTER";
            break;
        case 37:
            result = "REPLACE THE TIMING BELT";
            break;
    }      
    qDebug() << "Suggested Repair: " << result << endl;
    // cnvarq.enqueue("REPAIR");
}
