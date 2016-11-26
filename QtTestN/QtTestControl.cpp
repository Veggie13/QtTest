#pragma warning(disable:4561)
#include <Windows.h>
#include <QtWidgets/QApplication>
#include <QtCore/QAbstractEventDispatcher>
#include <QtTestWidget.h>
#include "QWinWidget"
#pragma warning(default:4561)
#include "QtTestControl.h"


using namespace System;
using namespace System::Windows::Forms;
using namespace QtTestN;


QtTestControl::QtTestControl()
    :   UserControl()
    ,   _qApp(NULL)
    ,   _widget(NULL)
    ,   _host(NULL)
{
    int argc = 0;
    _qApp = new QApplication(argc, NULL);

    _widgetHandle = gcnew ExtNativeWindow();

    this->HandleCreated += gcnew EventHandler(this, &QtTestControl::QtTestControl_HandleCreated);
    this->Load += gcnew EventHandler(this, &QtTestControl::QtTestControl_Load);
    this->SizeChanged += gcnew EventHandler(this, &QtTestControl::QtTestControl_SizeChanged);

    _timer = gcnew Timer();
    _timer->Tick += gcnew EventHandler(this, &QtTestControl::_timer_Tick);
    _timer->Interval = 200;
}

QtTestControl::~QtTestControl()
{
    if (_widget != NULL)
    {
        delete _widget;
        _widget = NULL;
    }

    if (_host != NULL)
    {
        delete _host;
        _host = NULL;
    }

    if (_qApp != NULL)
    {
        delete _qApp;
        _qApp = NULL;
    }
}

QtTestControl::!QtTestControl()
{
    this->~QtTestControl();
}

void QtTestControl::QtTestControl_HandleCreated(Object^ sender, EventArgs^ e)
{
    _host = new QWinWidget((HWND)(this->Handle.ToPointer()));
    _widget = new QtTestWidget(_host);

    _widgetHandle->AssignHandle(IntPtr((HWND)_widget->winId()));
    _widgetHandle->OnWndProc += gcnew WndProcHandler(this, &QtTestControl::_widgetHandle_OnWndProc);
}

void QtTestControl::QtTestControl_Load(Object^ sender, EventArgs^ e)
{
    if (!_widget)
        return;

    _host->show();
    _widget->show();

    //_timer->Start();
}

void QtTestControl::QtTestControl_SizeChanged(Object^ sender, EventArgs^ e)
{
    if (!IsHandleCreated)
        return;

    _host->resize(Width, Height);
    _widget->resize(Width, Height);
}

void QtTestControl::_timer_Tick(Object^ sender, EventArgs^ e)
{
    _qApp->processEvents();
}

void QtTestControl::_widgetHandle_OnWndProc(Message% msg)
{
    _qApp->processEvents();
}

void QtTestControl::ExtNativeWindow::WndProc(Message% msg)
{
    OnWndProc(msg);
    this->NativeWindow::WndProc(msg);
}

void QtTestControl::WndProc(Message% msg)
{
    this->UserControl::WndProc(msg);
    if (this->IsHandleCreated && msg.HWnd != this->Handle)
    {
        int i = 1;
    }
}
