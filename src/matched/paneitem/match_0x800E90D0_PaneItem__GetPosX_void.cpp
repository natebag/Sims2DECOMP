// 0x800E90D0 PaneItem::GetPosX(void) (8 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_800E90EC" lines="bl _s800E90D0_0"

extern "C" void _s800E90D0_0();

struct PaneItem {
    void GetPosX();
};

void PaneItem::GetPosX() {
}
