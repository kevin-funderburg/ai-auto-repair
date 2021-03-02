#include <QApplication>
#include <QHBoxLayout>
#include <QSlider>
#include <QSpinBox>
#include <QDial>
#include <QLCDNumber>
#include <QPushButton>
#include <QRadioButton>
#include <QWidget>
#include <QString>
#include <QLabel>
#include <QSignalMapper>
#include <QDebug>


#include "symptom.h"


Symptom::Symptom(QWidget *parent) : QWidget(parent)
{
    // Quit
    qDebug() << "building symptom";

    QGridLayout *grid = new QGridLayout;
    
    QPushButton *quit = new QPushButton(tr("Exit"));
    quit->setFont(QFont("Helvetica", 18, QFont::Bold));
    // Connect the signal of the button click to the quit action
    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));

    // QMap<QString, QString> btnInfo;
    // btnInfo.insert("WHEEL", "imgs/wheel.png"); 
    // btnInfo.insert("SQUEAK", "imgs/listen.png"); 
    // btnInfo.insert("ENGINE", "imgs/engine.png"); 
    // btnInfo.insert("AC", "imgs/ac.png"); 
    // btnInfo.insert("BATTERY", "imgs/car-battery.png"); 
    // btnInfo.insert("TIRE", "imgs/flat-tire.png"); 
    // btnInfo.insert("SMOKE", "imgs/smoke.png"); 
    // btnInfo.insert("ACCELERATION", "imgs/slowDown.png"); 


    // QSignalMapper *signalMapper = new QSignalMapper;

    // QMapIterator<QString, int> i(btnInfo);
    // while (i.hasNext()) {
    //     i.next();
    //     QPushButton *btn = newButton(i.key(), i.value());
    //     btn->setIconSize(QSize(65, 65));

    //     signalMapper->setMapping(btn, i.key());
    //     connect(btn, SIGNAL(clicked()),
    //         signalMapper, SLOT (map()));
    // }

    QPushButton *whlBtn = new QPushButton(QIcon("imgs/wheel.png"), tr("WHEEL"));
    QPushButton *sqkBtn = new QPushButton(QIcon("imgs/listen.png"), tr("SQUEAK"));
    QPushButton *engnBtn = new QPushButton(QIcon("imgs/engine.png"), tr("ENGINE"));
    QPushButton *acBtn = new QPushButton(QIcon("imgs/ac.png"), tr("AC"));
    QPushButton *batBtn = new QPushButton(QIcon("imgs/car-battery.png"), tr("BATTERY"));
    QPushButton *tireBtn = new QPushButton(QIcon("imgs/flat-tire.png"), tr("TIRE"));
    QPushButton *smkBtn = new QPushButton(QIcon("imgs/smoke.png"), tr("SMOKE"));
    QPushButton *accelBtn = new QPushButton(QIcon("imgs/slowDown.png"), tr("ACCELERATION"));

    whlBtn->setIconSize(QSize(65, 65));    
    sqkBtn->setIconSize(QSize(65, 65));
    engnBtn->setIconSize(QSize(65, 65));
    acBtn->setIconSize(QSize(65, 65));
    batBtn->setIconSize(QSize(65, 65));
    tireBtn->setIconSize(QSize(65, 65));
    smkBtn->setIconSize(QSize(65, 65));
    accelBtn->setIconSize(QSize(65, 65));

    QSignalMapper *signalMapper = new QSignalMapper;
    signalMapper->setMapping(whlBtn, QString("WHEEL"));
    signalMapper->setMapping(sqkBtn, QString("SQUEAK"));
    signalMapper->setMapping(engnBtn, QString("ENGINE"));
    signalMapper->setMapping(acBtn, QString("AC"));
    signalMapper->setMapping(batBtn, QString("BATTERY"));
    signalMapper->setMapping(tireBtn, QString("TIRE"));
    signalMapper->setMapping(smkBtn, QString("SMOKE"));
    signalMapper->setMapping(accelBtn, QString("ACCELERATION"));


    connect(whlBtn, SIGNAL(clicked()),
        signalMapper, SLOT (map()));
    connect(sqkBtn, SIGNAL(clicked()),
        signalMapper, SLOT (map()));
    connect(engnBtn, SIGNAL(clicked()),
        signalMapper, SLOT (map()));
    connect(acBtn, SIGNAL(clicked()),
        signalMapper, SLOT (map()));
    connect(batBtn, SIGNAL(clicked()),
        signalMapper, SLOT (map()));
    connect(tireBtn, SIGNAL(clicked()),
        signalMapper, SLOT (map()));
    connect(smkBtn, SIGNAL(clicked()),
        signalMapper, SLOT (map()));
    connect(accelBtn, SIGNAL(clicked()),
        signalMapper, SLOT (map()));


    connect(signalMapper, SIGNAL(mapped(QString)),
        this, SIGNAL(sendSymp(QString)));

    // for (int i = 0; i < 8; i++)
    // {
    //     for(int j = 0; j < 2; j++)
    //         grid->addWidget(whlBtn,  0, 0);
    // }
    grid->addWidget(whlBtn,  0, 0);
    grid->addWidget(sqkBtn,  0, 1);
    grid->addWidget(engnBtn, 1, 0);
    grid->addWidget(acBtn,   1, 1);
    grid->addWidget(batBtn,  2, 0);
    grid->addWidget(tireBtn, 2, 1);
    grid->addWidget(smkBtn,  3, 0);
    grid->addWidget(accelBtn, 3, 1);
    
    // Add labels to the sliders so you can tell which slider does what
    QLabel *promptLbl = new QLabel("Choose the symptom you are having.");
    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(promptLbl);
    layout->addLayout(grid);
    layout->addWidget(quit);
    setLayout(layout);
}


// QPushButton Symptom::newButton(QString name, QString path)
// {
//     QPushButton *btn = new QPushButton(QIcon(path), name);
//     return btn; 
// }