//***************************************
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


#include "radio.h"
#include "ranges.h"

LCDRange::LCDRange(QWidget *parent)
        : QWidget(parent)
{
    QLCDNumber *lcd = new QLCDNumber(2);
    lcd->setSegmentStyle(QLCDNumber::Filled);

    slider = new QSlider(Qt::Horizontal);
    // Connect the signal change of the slider to the LCD output
    connect(slider, SIGNAL(valueChanged(int)),
            lcd, SLOT(display(int)));
    // Connect the signal change of the slider to object itself
    connect(slider, SIGNAL(valueChanged(int)),
            this, SIGNAL(valueChanged(int)));

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(lcd);
    layout->addWidget(slider);
    setLayout(layout);
}

// Public function to get the value of a LCD/slider combo
int LCDRange::value() const { return slider->value(); }

// Public function to adjust the value of a LCD/slider combo
void LCDRange::setValue(int value) { slider->setValue(value); }

void LCDRange::setRange(int minValue, int maxValue)
{
    if (minValue < 0 || maxValue > 99 || minValue > maxValue) {
        qWarning("LCDRange::setRange(%d, %d)\n"
                 "\tRange must be 0..99\n"
                 "\tand minValue must not be greater than maxValue",
                 minValue, maxValue);
        return;
    }
    slider->setRange(minValue, maxValue);
}


DialRange::DialRange(QWidget *parent)
    : QWidget(parent)
{
    QLCDNumber *lcd = new QLCDNumber(2);
    lcd->setSegmentStyle(QLCDNumber::Filled);

    QDial *dial = new QDial;
    dial->setNotchesVisible(true);
    dial->setMinimum(0);
    dial->setMaximum(99);
    dial->setValue(49);
    /// Connect the dial's signal change to the LCD to output
    /// the dials value
    connect(dial, SIGNAL(valueChanged(int)),
            lcd, SLOT(display(int)));

    QVBoxLayout *layout = new QVBoxLayout;
    layout->addWidget(lcd);
    layout->addWidget(dial);
    setLayout(layout);
}

/// Class that creates a series of widgets organized into a
/// radio
Radio::Radio(QWidget *parent)
: QWidget(parent)
{
    // Quit
    qDebug() << "building radio";

    QGridLayout *grid = new QGridLayout;
    


    QPushButton *quit = new QPushButton(tr("Exit"));
    quit->setFont(QFont("Helvetica", 18, QFont::Bold));
    // Connect the signal of the button click to the quit action
    connect(quit, SIGNAL(clicked()), qApp, SLOT(quit()));

    QPushButton *whlBtn = new QPushButton(QIcon("imgs/wheel.png"), tr("WHEEL"));
    whlBtn->setIconSize(QSize(65, 65));
    // connect(whlBtn, SIGNAL(clicked()), this, SIGNALfreqChanged(int freqVal));
    
    QPushButton *sqkBtn = new QPushButton(QIcon("imgs/listen.png"), tr("SQUEAK"));
    sqkBtn->setIconSize(QSize(65, 65));
    QPushButton *engnBtn = new QPushButton(QIcon("imgs/engine.png"), tr("ENGINE"));
    engnBtn->setIconSize(QSize(65, 65));
    QPushButton *acBtn = new QPushButton(QIcon("imgs/ac.png"), tr("AC"));
    acBtn->setIconSize(QSize(65, 65));
    QPushButton *batBtn = new QPushButton(QIcon("imgs/car-battery.png"), tr("BATTERY"));
    batBtn->setIconSize(QSize(65, 65));
    QPushButton *tireBtn = new QPushButton(QIcon("imgs/flat-tire.png"), tr("TIRE"));
    tireBtn->setIconSize(QSize(65, 65));
    QPushButton *smkBtn = new QPushButton(QIcon("imgs/smoke.png"), tr("SMOKE"));
    smkBtn->setIconSize(QSize(65, 65));
    QPushButton *accelBtn = new QPushButton(QIcon("imgs/slowDown.png"), tr("ACCELERATION"));
    accelBtn->setIconSize(QSize(65, 65));

    quit->setFont(QFont("Helvetica", 18, QFont::Bold));


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
        this, SIGNAL(sendMsg(QString)));

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


// void Radio::updateSymptom(QString msg)
// {
//     qDebug() << "the msg is" << msg;
// }