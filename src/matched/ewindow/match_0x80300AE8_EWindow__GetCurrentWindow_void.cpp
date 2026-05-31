// FLAGS: -fno-schedule-insns
// 0x80300AE8 EWindow::GetCurrentWindow(void) (8B)
// lwz r3,gCurrentWindow(r13); blr  -- returns SDA global
extern int gCurrentWindow;

struct EWindow {
    int GetCurrentWindow();
};

int EWindow::GetCurrentWindow() { return gCurrentWindow; }
