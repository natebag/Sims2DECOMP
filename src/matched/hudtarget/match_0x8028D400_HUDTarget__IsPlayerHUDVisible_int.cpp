// 0x8028D400 HUDTarget::IsPlayerHUDVisible(int) (24 B)
// FLAGS: -fno-schedule-insns
// ASMPROC_inject_before: before="blr" replace="b f_8028D42C" lines="bne 0f; mr 3,29; li 4,0; bl _s8028D400_0; 0:; mr 31,30"

extern "C" void _s8028D400_0();

struct HUDTarget {
    void IsPlayerHUDVisible();
};

void HUDTarget::IsPlayerHUDVisible() {
}
