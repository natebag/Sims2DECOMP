// COMPILER: mwcc
// 0x8024C760 OSGetArenaHi (8B) — Dolphin SDK os/OSArena.c
//
// Returns the high end of the OS arena (SDA-resident global). MWCC GC-1.2.5n.

extern void* __OSArenaHi;

extern "C" void* OSGetArenaHi(void) {
    return __OSArenaHi;
}
