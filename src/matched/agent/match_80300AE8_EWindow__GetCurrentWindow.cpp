class EWindow {
public:
    static EWindow *s_pCurrentWindow;
    static EWindow *GetCurrentWindow();
};
EWindow *EWindow::s_pCurrentWindow;
EWindow *EWindow::GetCurrentWindow() { return s_pCurrentWindow; }
