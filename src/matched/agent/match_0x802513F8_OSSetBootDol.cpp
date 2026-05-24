// FLAGS: -fno-schedule-insns
// 0x802513F8 OSSetBootDol (16B)
// lwz r0,-xxx(r13); stw r3,-xxx(r13); mr r3,r0; blr — SDA exchange-and-return-old
extern int gOSBootDol;
int OSSetBootDol(int newVal) {
    int old = gOSBootDol;
    gOSBootDol = newVal;
    return old;
}
