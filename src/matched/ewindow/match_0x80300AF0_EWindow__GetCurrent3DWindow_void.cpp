// FLAGS: -fno-schedule-insns
// 0x80300AF0 EWindow::GetCurrent3DWindow(void) (8B)
// lwz r3,gCurrent3DWindow(r13); blr  -- returns SDA global
extern int gCurrent3DWindow;

struct EWindow {
    int GetCurrent3DWindow();
};

int EWindow::GetCurrent3DWindow() { return gCurrent3DWindow; }
