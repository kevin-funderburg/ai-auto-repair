#include <QtGui>

#include "repair.h"

Repair::Repair(QWidget *parent)
    : QWidget(parent)
{
    init();

    errorMessageDialog = new QErrorMessage(this);

    int frameStyle = QFrame::Sunken | QFrame::Panel;

    itemLabel = new QLabel;
    itemLabel->setFrameStyle(frameStyle);
    QPushButton *itemButton = new QPushButton(tr("Click to Choose the Symptom"));

    symptomLabel = new QLabel;
    symptomLabel->setFrameStyle(frameStyle);
    QPushButton *symptomButton = new QPushButton(tr("Click to Enter Symptom"));

    repairLabel = new QLabel;
    repairLabel->setFrameStyle(frameStyle);
    QPushButton *repairButton = new QPushButton(tr("What to Repair"));

    connect(itemButton, SIGNAL(clicked()), this, SLOT(setItem()));
    connect(symptomButton, SIGNAL(clicked()), this, SLOT(setText()));
    connect(repairButton, SIGNAL(clicked()), this, SLOT(setText()));

    native = new QCheckBox(this);
    native->setText("Use native file dialog.");
    native->setChecked(true);

    QGridLayout *layout = new QGridLayout;
    layout->setColumnStretch(1, 1);
    layout->setColumnMinimumWidth(1, 250);
    layout->addWidget(itemButton, 2, 0);
    layout->addWidget(itemLabel, 2, 1);
    layout->addWidget(repairButton, 4, 0);
    layout->addWidget(repairLabel, 4, 1);

    layout->addWidget(native, 15, 0);
// #if defined(Q_OS_SYMBIAN) || defined(Q_WS_MAEMO_5) || defined(Q_WS_SIMULATOR)
//     QWidget *widget = new QWidget;
//     widget->setLayout(layout);

//     QScrollArea *scrollArea = new QScrollArea(this);
//     scrollArea->setWidget(widget);

//     QHBoxLayout *mainLayout = new QHBoxLayout;
//     mainLayout->addWidget(scrollArea);
//     setLayout(mainLayout);
// #else
// #endif
    setLayout(layout);

    setWindowTitle(tr("REPAIR"));
}


void Repair::init()
{
    // initialize caluse variable list
    for (i=0;i < CLS_VAR_LIST_SIZE; i++)
        clvarlt[i] = "FAULT";

    print_structures(3);

}


void Repair::inference()
{
    // cout << "Options for Fault:1/2/3" << endl;
    fault = instantiate("FAULT"); 
    cnvarq.enqueue("FAULT");
    print_structures(2);
    while (!cnvarq.empty())
    {
        v = cnvarq.head();
        cnvarq.dequeue();
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

//==========================================================================
// Routine to instantiate a variable (v) if it isn't already.
// The instantiate indication (instlt) is a 0 if not, a 1 if it is.
// The vriable list (varlt) contains the variable (v) 
bool Repair::check_instantiation(QString key)
{
    // return varlt.contains(key);
    QMap<QString, QString>::const_iterator i = varlt.constBegin();
    
    while (i != varlt.constEnd())
    {
        if ((i.key() == key) && (i.value() != ""))
            return true;
    }
    return false;
        
}


// void Repair::search(QString key)
// {

// }


QString Repair::instantiate(QString key)
{
    QString value;
    if (!check_instantiation(key))
    {
        // cout << "Enter value for " << key << endl;
        // cin >> value;
        varlt.insert(key, value);
    }
    return value;
}


void Repair::print_structures(int option)
{
    QMap<QString, QString>::const_iterator i = varlt.constBegin();

    if (option & 1)
    {
        printf("**CLAUSE VARIABLE LIST**\n");
        for (int i = 0; i < CLS_VAR_LIST_SIZE; ++i)
        {
            qDebug() << "CLAUSE VARIABLE " << i << clvarlt[i];
            // qDebug() << ("CLAUSE VARIABLE [%d] %s \n", i, clvarlt[i].c_str());
        }
    }
     
    if (option & 2)
    {
        printf("**VARIABLE LIST**\n");
        while (i != varlt.constEnd())
            qDebug() << '\t' << i.key() << '\t' << i.value();    
    }

}


// QString Repair::yesOrNo(QString msg)
// {
//     QMessageBox::StandardButton reply;
//     reply = QMessageBox::question(this, tr("Additional Information"), msg,
//                                     QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
//     if (reply == QMessageBox::Yes)
//         return "YES";
//     else if (reply == QMessageBox::No)
//         return "NO";
//     else
//         return "Cancel";
// }


void Repair::check_clauses(int snum)
{
    for (int i = 0; i < VAR_LST_SIZE; ++i)
    {
        instantiate(clvarlt[snum*VAR_LST_SIZE+i]);
    }
}

bool Repair::present(QString var, int snum)
{
    for (int i = 0; i < VAR_LST_SIZE; ++i)
    {
        if(clvarlt[snum*VAR_LST_SIZE+i] == var)
            return true;
    }
    return false;
}


bool Repair::check_rule(int snum)
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


void Repair::execute_then(int snum)
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
    qDebug() << "Suggested Repair: " << repair << endl;
    cnvarq.enqueue("REPAIR");
}
