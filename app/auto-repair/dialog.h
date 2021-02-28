#ifndef DIALOG_H
#define DIALOG_H

#include <string>
#include <QWidget>
#include<QDebug>

class QCheckBox;
class QLabel;
class QErrorMessage;

class Dialog : public QWidget
{
    Q_OBJECT

public:
    Dialog(QWidget *parent = 0);

private slots:
    void setItem();
    void setText();
    void informationMessage();
    void questionMessage();
    void warningMessage();
    void errorMessage();
    void init();
    void instantiate(QString symptom);
    void push_on_stack();
    void inference(QString varble);
    void determine_member_concl_list(QString varble);
    QString yesOrNo(QString msg);

private:
    QCheckBox *native;
    QLabel *integerLabel;
    QLabel *doubleLabel;
    QLabel *itemLabel;
    QLabel *symptomLabel;
    QLabel *repairLabel;
    QLabel *colorLabel;
    QLabel *fontLabel;
    QLabel *directoryLabel;
    QLabel *openFileNameLabel;
    QLabel *openFileNamesLabel;
    QLabel *saveFileNameLabel;
    QLabel *criticalLabel;
    QLabel *informationLabel;
    QLabel *questionLabel;
    QLabel *warningLabel;
    QLabel *errorLabel;
    QErrorMessage *errorMessageDialog;

    QString openFilesPath;
};

#endif