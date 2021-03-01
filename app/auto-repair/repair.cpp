#include "repair.h"

Repair::Repair(QWidget *parent)
    : QWidget(parent)
{
    // init();

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
#if defined(Q_OS_SYMBIAN) || defined(Q_WS_MAEMO_5) || defined(Q_WS_SIMULATOR)
    QWidget *widget = new QWidget;
    widget->setLayout(layout);

    QScrollArea *scrollArea = new QScrollArea(this);
    scrollArea->setWidget(widget);

    QHBoxLayout *mainLayout = new QHBoxLayout;
    mainLayout->addWidget(scrollArea);
    setLayout(mainLayout);
#else
    setLayout(layout);
#endif

    setWindowTitle(tr("REPAIR"));
}


void Repair::inference()
{

}

//==========================================================================
// Routine to instantiate a variable (v) if it isn't already.
// The instantiate indication (instlt) is a 0 if not, a 1 if it is.
// The vriable list (varlt) contains the variable (v) 
bool Repair::check_instantiation(QString key)
{
    return varlt.contains(key);
}


void Repair::search(QString key)
{

}


void Repair::instantiate(QString key, QString val)
{

}


void Repair::print_structures()
{
    // map<string, string>::iterator itr; 

    // printf("**CLAUSE VARIABLE LIST**\n");
    // for (int i = 0; i < CLS_VAR_LIST_SIZE; ++i)
    // {
    //     printf("clvarlt[%d] = %s \n", i, clvarlt[i].c_str());
    // }

    // printf("**VARIABLE LIST**\n");
    // for (itr = varlt.begin(); itr != varlt.end(); ++itr) { 
    //     cout << '\t' << itr->first 
    //          << '\t' << itr->second << '\n'; 
    // } 
    
}


QString Repair::yesOrNo(QString msg)
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("Additional Information"), msg,
                                    QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
    if (reply == QMessageBox::Yes)
        return "YES";
    else if (reply == QMessageBox::No)
        return "NO";
    else
        return "Cancel";
}