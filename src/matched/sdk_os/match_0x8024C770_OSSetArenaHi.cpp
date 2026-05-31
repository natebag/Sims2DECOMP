// COMPILER: mwcc
// 0x8024C770 OSSetArenaHi (8B) — Dolphin SDK os/OSArena.c
//
// Sets the high end of the OS arena (SDA-resident global). MWCC GC-1.2.5n.

extern void* __OSArenaHi;

extern "C" void OSSetArenaHi(void* newHi) {
    __OSArenaHi = newHi;
}
