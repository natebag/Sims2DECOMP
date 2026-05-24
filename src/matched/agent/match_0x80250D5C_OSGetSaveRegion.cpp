// FLAGS: -fno-schedule-insns
// 0x80250D5C OSGetSaveRegion (20B)
// lwz r0,-23640(r13); stw r0,0(r3); lwz r0,-23636(r13); stw r0,0(r4); blr
extern int gSaveRegionA;
extern int gSaveRegionB;
void OSGetSaveRegion(int* outA, int* outB) {
    int v = gSaveRegionA;
    *outA = v;
    v = gSaveRegionB;
    *outB = v;
}
