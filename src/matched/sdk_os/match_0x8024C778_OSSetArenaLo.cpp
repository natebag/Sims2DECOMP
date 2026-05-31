// COMPILER: mwcc
// 0x8024C778 OSSetArenaLo (8B) — Dolphin SDK os/OSArena.c
//
// Sets the low end of the OS arena (SDA-resident global). MWCC GC-1.2.5n.

extern void* __OSArenaLo;

extern "C" void OSSetArenaLo(void* newLo) {
    __OSArenaLo = newLo;
}
