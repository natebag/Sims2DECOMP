// COMPILER: mwcc
// 0x8024D7F4 OSGetCurrentContext (12B) — Dolphin SDK os/OSContext.c
//
// Returns the current-context pointer held in low memory at 0x800000D4.
// Absolute lis/lwz, no relocation. MWCC GC-1.2.5n.

struct OSContext;

extern "C" OSContext* OSGetCurrentContext(void) {
    return *(OSContext**)0x800000D4;
}
