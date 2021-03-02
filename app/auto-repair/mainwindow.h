#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "symptom.h"
#include "repair.h"
#include "diagnosis.h"

class QAction;
class QListWidget;
class QMenu;
class QTextEdit;
class Radio;


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
    void recvMsg(QString);

private:
    void createActions();
    void createMenus();
    void createStatusBar();
    void createDockWindows();

    QTextEdit *textEdit;
    Diagnosis *diag;
    Repair *repair;
    QListWidget *customerList;
    QListWidget *paragraphsList;

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
};

#endif
