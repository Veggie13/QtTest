#include <windows.h>
#include <QtWidgets/QApplication>
#include <QtTestWidget.h>

int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
    QApplication app(__argc, __argv);
    QtTestWidget* w = new QtTestWidget();
    w->show();
    return app.exec();
}
