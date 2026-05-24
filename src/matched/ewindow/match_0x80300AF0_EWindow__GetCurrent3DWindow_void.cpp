// 0x80300AF0 EWindow::GetCurrent3DWindow(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,-26704(13)"

struct EWindow {
    void GetCurrent3DWindow();
};

void EWindow::GetCurrent3DWindow() {
}
