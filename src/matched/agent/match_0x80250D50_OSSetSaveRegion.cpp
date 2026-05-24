// FLAGS: -fno-schedule-insns
// 0x80250D50 OSSetSaveRegion (12B)
// stw r3,-xxx(r13); stw r4,-xxx(r13); blr — dual SDA store
extern int gSaveRegionA;
extern int gSaveRegionB;
void OSSetSaveRegion(int a, int b) {
    gSaveRegionA = a;
    gSaveRegionB = b;
}
