#include <QApplication>
#include <QTranslator>
#include <QLocale>
#include <QLibraryInfo>

#include "dialog.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);

    QString translatorFileName = QLatin1String("qt_");
    translatorFileName += QLocale::system().name();
    QTranslator *translator = new QTranslator(&app);
    if (translator->load(translatorFileName, QLibraryInfo::location(QLibraryInfo::TranslationsPath)))
        app.installTranslator(translator);

    Dialog dialog;
#ifdef Q_OS_SYMBIAN
    dialog.showMaximized();
#else
    dialog.show();
#endif

    return app.exec();
}
