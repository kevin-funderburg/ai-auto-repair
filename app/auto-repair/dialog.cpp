#include <QtGui>

#include "dialog.h"

#define MESSAGE \
    Dialog::tr("<p>Message boxes have a caption, a text, " \
               "and any number of buttons, each with standard or custom texts." \
               "<p>Click a button to close the message box. Pressing the Esc button " \
               "will activate the detected escape button (if any).")

Dialog::Dialog(QWidget *parent)
    : QWidget(parent)
{
    errorMessageDialog = new QErrorMessage(this);

    int frameStyle = QFrame::Sunken | QFrame::Panel;

    symptomLabel = new QLabel;
    symptomLabel->setFrameStyle(frameStyle);
    QPushButton *symptomButton = new QPushButton(tr("Click to Enter Symptom"));

    repairLabel = new QLabel;
    repairLabel->setFrameStyle(frameStyle);
    QPushButton *repairButton = new QPushButton(tr("What to Repair"));

    informationLabel = new QLabel;
    informationLabel->setFrameStyle(frameStyle);
    QPushButton *informationButton =
            new QPushButton(tr("QMessageBox::i&nformation()"));

    questionLabel = new QLabel;
    questionLabel->setFrameStyle(frameStyle);
    QPushButton *questionButton =
            new QPushButton(tr("QMessageBox::&question()"));

    warningLabel = new QLabel;
    warningLabel->setFrameStyle(frameStyle);
    QPushButton *warningButton = new QPushButton(tr("QMessageBox::&warning()"));

    errorLabel = new QLabel;
    errorLabel->setFrameStyle(frameStyle);
    QPushButton *errorButton =
            new QPushButton(tr("QErrorMessage::showM&essage()"));

    connect(symptomButton, SIGNAL(clicked()), this, SLOT(setText()));
    connect(repairButton, SIGNAL(clicked()), this, SLOT(setText()));
    connect(informationButton, SIGNAL(clicked()),
            this, SLOT(informationMessage()));
    connect(questionButton, SIGNAL(clicked()), this, SLOT(questionMessage()));
    connect(warningButton, SIGNAL(clicked()), this, SLOT(warningMessage()));
    connect(errorButton, SIGNAL(clicked()), this, SLOT(errorMessage()));

    native = new QCheckBox(this);
    native->setText("Use native file dialog.");
    native->setChecked(true);

    QGridLayout *layout = new QGridLayout;
    layout->setColumnStretch(1, 1);
    layout->setColumnMinimumWidth(1, 250);
    layout->addWidget(symptomButton, 3, 0);
    layout->addWidget(symptomLabel, 3, 1);
    layout->addWidget(repairButton, 4, 0);
    layout->addWidget(repairLabel, 4, 1);

    layout->addWidget(informationButton, 11, 0);
    layout->addWidget(informationLabel, 11, 1);
    layout->addWidget(questionButton, 12, 0);
    layout->addWidget(questionLabel, 12, 1);
    layout->addWidget(warningButton, 13, 0);
    layout->addWidget(warningLabel, 13, 1);
    layout->addWidget(errorButton, 14, 0);
    layout->addWidget(errorLabel, 14, 1);
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

    setWindowTitle(tr("Fix Your Car!"));
}

void Dialog::setInteger()
{
    bool ok;
    int i = QInputDialog::getInt(this, tr("QInputDialog::getInteger()"),
                                 tr("Percentage:"), 25, 0, 100, 1, &ok);
    if (ok)
        integerLabel->setText(tr("%1%").arg(i));
}

void Dialog::setDouble()
{
    bool ok;
    double d = QInputDialog::getDouble(this, tr("QInputDialog::getDouble()"),
                                       tr("Amount:"), 37.56, -10000, 10000, 2, &ok);
    if (ok)
        doubleLabel->setText(QString("$%1").arg(d));
}

void Dialog::setItem()
{
    QStringList items;
    items << tr("Spring") << tr("Summer") << tr("Fall") << tr("Winter");

    bool ok;
    QString item = QInputDialog::getItem(this, tr("QInputDialog::getItem()"),
                                         tr("Season:"), items, 0, false, &ok);
    if (ok && !item.isEmpty())
        itemLabel->setText(item);
}

void Dialog::setText()
{
    bool ok;
    QString text = QInputDialog::getText(this, tr("Enter Text Here"),
                                         tr("Symptom:"), QLineEdit::Normal,
                                         QDir::home().dirName(), &ok);
    if (ok && !text.isEmpty())
        symptomLabel->setText(text);
}

void Dialog::setColor()
{
    QColor color;
    if (native->isChecked())
        color = QColorDialog::getColor(Qt::green, this);
    else
        color = QColorDialog::getColor(Qt::green, this, "Select Color", QColorDialog::DontUseNativeDialog);

    if (color.isValid()) {
        colorLabel->setText(color.name());
        colorLabel->setPalette(QPalette(color));
        colorLabel->setAutoFillBackground(true);
    }
}

void Dialog::setFont()
{
    bool ok;
    QFont font = QFontDialog::getFont(&ok, QFont(fontLabel->text()), this);
    if (ok) {
        fontLabel->setText(font.key());
        fontLabel->setFont(font);
    }
}

void Dialog::setExistingDirectory()
{
    QFileDialog::Options options = QFileDialog::DontResolveSymlinks | QFileDialog::ShowDirsOnly;
    if (!native->isChecked())
        options |= QFileDialog::DontUseNativeDialog;
    QString directory = QFileDialog::getExistingDirectory(this,
                                tr("QFileDialog::getExistingDirectory()"),
                                directoryLabel->text(),
                                options);
    if (!directory.isEmpty())
        directoryLabel->setText(directory);
}

void Dialog::setOpenFileName()
{
    QFileDialog::Options options;
    if (!native->isChecked())
        options |= QFileDialog::DontUseNativeDialog;
    QString selectedFilter;
    QString fileName = QFileDialog::getOpenFileName(this,
                                tr("QFileDialog::getOpenFileName()"),
                                openFileNameLabel->text(),
                                tr("All Files (*);;Text Files (*.txt)"),
                                &selectedFilter,
                                options);
    if (!fileName.isEmpty())
        openFileNameLabel->setText(fileName);
}

void Dialog::setOpenFileNames()
{
    QFileDialog::Options options;
    if (!native->isChecked())
        options |= QFileDialog::DontUseNativeDialog;
    QString selectedFilter;
    QStringList files = QFileDialog::getOpenFileNames(
                                this, tr("QFileDialog::getOpenFileNames()"),
                                openFilesPath,
                                tr("All Files (*);;Text Files (*.txt)"),
                                &selectedFilter,
                                options);
    if (files.count()) {
        openFilesPath = files[0];
        openFileNamesLabel->setText(QString("[%1]").arg(files.join(", ")));
    }
}

void Dialog::setSaveFileName()
{
    QFileDialog::Options options;
    if (!native->isChecked())
        options |= QFileDialog::DontUseNativeDialog;
    QString selectedFilter;
    QString fileName = QFileDialog::getSaveFileName(this,
                                tr("QFileDialog::getSaveFileName()"),
                                saveFileNameLabel->text(),
                                tr("All Files (*);;Text Files (*.txt)"),
                                &selectedFilter,
                                options);
    if (!fileName.isEmpty())
        saveFileNameLabel->setText(fileName);
}

void Dialog::criticalMessage()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::critical(this, tr("QMessageBox::critical()"),
                                    MESSAGE,
                                    QMessageBox::Abort | QMessageBox::Retry | QMessageBox::Ignore);
    if (reply == QMessageBox::Abort)
        criticalLabel->setText(tr("Abort"));
    else if (reply == QMessageBox::Retry)
        criticalLabel->setText(tr("Retry"));
    else
        criticalLabel->setText(tr("Ignore"));
}

void Dialog::informationMessage()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::information(this, tr("QMessageBox::information()"), MESSAGE);
    if (reply == QMessageBox::Ok)
        informationLabel->setText(tr("OK"));
    else
        informationLabel->setText(tr("Escape"));
}

void Dialog::questionMessage()
{
    QMessageBox::StandardButton reply;
    reply = QMessageBox::question(this, tr("QMessageBox::question()"),
                                    MESSAGE,
                                    QMessageBox::Yes | QMessageBox::No | QMessageBox::Cancel);
    if (reply == QMessageBox::Yes)
        questionLabel->setText(tr("Yes"));
    else if (reply == QMessageBox::No)
        questionLabel->setText(tr("No"));
    else
        questionLabel->setText(tr("Cancel"));
}

void Dialog::warningMessage()
{
    QMessageBox msgBox(QMessageBox::Warning, tr("QMessageBox::warning()"),
                       MESSAGE, 0, this);
    msgBox.addButton(tr("Save &Again"), QMessageBox::AcceptRole);
    msgBox.addButton(tr("&Continue"), QMessageBox::RejectRole);
    if (msgBox.exec() == QMessageBox::AcceptRole)
        warningLabel->setText(tr("Save Again"));
    else
        warningLabel->setText(tr("Continue"));

}

void Dialog::errorMessage()
{
    errorMessageDialog->showMessage(
            tr("This dialog shows and remembers error messages. "
               "If the checkbox is checked (as it is by default), "
               "the shown message will be shown again, "
               "but if the user unchecks the box the message "
               "will not appear again if QErrorMessage::showMessage() "
               "is called with the same message."));
    errorLabel->setText(tr("If the box is unchecked, the message "
                           "won't appear again."));
}