class E3DWindow;
class EWindow {
public:
    static E3DWindow *s_pCurrent3DWindow;
    static E3DWindow *GetCurrent3DWindow();
};
E3DWindow *EWindow::s_pCurrent3DWindow;
E3DWindow *EWindow::GetCurrent3DWindow() { return s_pCurrent3DWindow; }
