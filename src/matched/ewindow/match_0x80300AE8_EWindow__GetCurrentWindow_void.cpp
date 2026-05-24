// 0x80300AE8 EWindow::GetCurrentWindow(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" lines="lwz 3,-26708(13)"

struct EWindow {
    void GetCurrentWindow();
};

void EWindow::GetCurrentWindow() {
}
