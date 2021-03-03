#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QElapsedTimer>
#include "symptom.h"
#include "repair.h"
#include "diagnosis.h"

class QAction;
class QMenu;
class QTextEdit;
class QElapsedTimer;

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow();

private slots:
    void save();
    void open();
    void newTxt();
    void undo();
    void about();
    void recvSymp(QString);     // signal from symptom class
    void getRepair(QString);    // handle signal from diagnosis

private:
    void createActions();
    void createMenus();
    void createStatusBar();
    void createDockWindows();

    QTextEdit *textEdit;
    Diagnosis *diag;
    Repair *repair;

    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *viewMenu;
    QMenu *helpMenu;
    QToolBar *fileToolBar;
    QToolBar *editToolBar;
    QAction *newAct;
    QAction *openAct;
    QAction *saveAct;
    QAction *undoAct;
    QAction *aboutAct;
    QAction *aboutQtAct;
    QAction *quitAct;

    QElapsedTimer timer;
};

#endif
