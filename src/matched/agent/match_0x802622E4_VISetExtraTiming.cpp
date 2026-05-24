// FLAGS: -fno-schedule-insns
// 0x802622E4 __VISetExtraTiming (16B)
// lwz r0,-xxx(r13); stw r3,-xxx(r13); mr r3,r0; blr — SDA exchange-and-return-old
extern int gVIExtraTiming;
int VISetExtraTiming(int newVal) {
    int old = gVIExtraTiming;
    gVIExtraTiming = newVal;
    return old;
}
