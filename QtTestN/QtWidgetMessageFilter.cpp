#include "QtWidgetMessageFilter.h"

using namespace System;
using namespace System::Windows::Forms;
using namespace QtTestN;


QtWidgetMessageFilter::QtWidgetMessageFilter(IntPtr hWnd)
{
}

bool QtWidgetMessageFilter::PreFilterMessage(Message% msg)
{
    return false;
}
