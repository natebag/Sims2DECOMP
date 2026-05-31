// COMPILER: mwcc
// 0x80253438 OSGetCurrentThread (12B) — Dolphin SDK os/OSThread.c
//
// Returns the current thread pointer held at the fixed low-memory slot
// OS_CURRENT_THREAD = *(OSThread**)0x800000E4 (absolute lis/lwz, no reloc).
// MWCC GC-1.2.5n.

struct OSThread;

extern "C" OSThread* OSGetCurrentThread(void) {
    return *(OSThread**)0x800000E4;
}
