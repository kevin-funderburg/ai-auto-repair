#include <QApplication>
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>

#include "dialog.h"

int main(int argc, char *argv[])
{
    qDebug() << "*** main.cpp | main() ***\n";
    QApplication app(argc, argv);

    QString translatorFileName = QLatin1String("qt_");
    translatorFileName += QLocale::system().name();
    QTranslator *translator = new QTranslator(&app);
    if (translator->load(translatorFileName, QLibraryInfo::location(QLibraryInfo::TranslationsPath)))
        app.installTranslator(translator);

    Diagnosis diagnosis;
    // Dialog dialog;
#ifdef Q_OS_SYMBIAN
    diagnosis.showMaximized();
#else
    diagnosis.show();
#endif

    return app.exec();
}
