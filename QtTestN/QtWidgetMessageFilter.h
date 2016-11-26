#pragma once

namespace QtTestN
{

    ref class QtWidgetMessageFilter : System::Windows::Forms::IMessageFilter
    {
    public:
        QtWidgetMessageFilter(System::IntPtr hWnd);

        virtual bool PreFilterMessage(System::Windows::Forms::Message%);
    };

}
