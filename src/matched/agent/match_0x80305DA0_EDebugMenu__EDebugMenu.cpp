// 0x80305DA0 EDebugMenu::EDebugMenu(void) (40B)
// Non-sequential store order: 20,8,16,12,0,24. Two fields = 1, four = 0.
// swap_adj moves li r11,1 before first stw to match DOL preload order.
// ASMPROC_swap_adj: a=stw b=li which=first

struct EDebugMenu {
    EDebugMenu();
};

EDebugMenu::EDebugMenu() {
    int z = 0;
    int one = z + 1;
    volatile int* p = (volatile int*)this;
    p[5] = z;
    p[2] = one;
    p[4] = z;
    p[3] = z;
    p[0] = one;
    p[6] = z;
}
