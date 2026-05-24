// FLAGS: -fno-schedule-insns
// 0x8025F6B8 DVDSetAutoInvalidation (16B)
// lwz r0,-xxx(r13); stw r3,-xxx(r13); mr r3,r0; blr — SDA exchange-and-return-old
extern int gDVDAutoInvalidation;
int DVDSetAutoInvalidation(int newVal) {
    int old = gDVDAutoInvalidation;
    gDVDAutoInvalidation = newVal;
    return old;
}
