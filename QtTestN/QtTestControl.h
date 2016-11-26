#pragma once

class QtTestWidget;
class QWinWidget;
class QApplication;

namespace QtTestN
{
    public ref class QtTestControl : System::Windows::Forms::UserControl
    {
    public:
        QtTestControl();
        ~QtTestControl();
        !QtTestControl();

    protected:
        virtual void WndProc(System::Windows::Forms::Message%) override;

    private:
        void QtTestControl_HandleCreated(System::Object^, System::EventArgs^);
        void QtTestControl_Load(System::Object^, System::EventArgs^);
        void QtTestControl_SizeChanged(System::Object^, System::EventArgs^);

        void _timer_Tick(System::Object^, System::EventArgs^);
        
        void _widgetHandle_OnWndProc(System::Windows::Forms::Message%);

        delegate void WndProcHandler(System::Windows::Forms::Message%);
        
        ref class ExtNativeWindow : System::Windows::Forms::NativeWindow
        {
        public:
            event WndProcHandler^ OnWndProc;

        protected:
            virtual void WndProc(System::Windows::Forms::Message%) override;
        };
        
        ExtNativeWindow^ _widgetHandle;
        System::Windows::Forms::Timer^ _timer;

        QWinWidget* _host;
        QtTestWidget* _widget;
        QApplication* _qApp;
    };
}
