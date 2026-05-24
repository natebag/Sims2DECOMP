// FLAGS: -fno-schedule-insns
// 0x8037162C OSSetFontWidth (16B)
// lwz r0,-xxx(r13); stw r3,-xxx(r13); mr r3,r0; blr — SDA exchange-and-return-old
extern int gOSFontWidth;
int OSSetFontWidth(int newVal) {
    int old = gOSFontWidth;
    gOSFontWidth = newVal;
    return old;
}
