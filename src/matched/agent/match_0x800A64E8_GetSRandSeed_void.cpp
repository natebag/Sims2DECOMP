// FLAGS: -fno-schedule-insns
// 0x800A64E8 GetSRandSeed (8B)
// lwz r3,gSRandSeed(r13)
extern int gSRandSeed;
int GetSRandSeed() { return gSRandSeed; }
