// COMPILER: mwcc
// 0x8024C768 OSGetArenaLo (8B) — Dolphin SDK os/OSArena.c
//
// Returns the low end of the OS arena (SDA-resident global). MWCC GC-1.2.5n.

extern void* __OSArenaLo;

extern "C" void* OSGetArenaLo(void) {
    return __OSArenaLo;
}
