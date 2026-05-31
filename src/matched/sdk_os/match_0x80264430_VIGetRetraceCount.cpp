// COMPILER: mwcc
// 0x80264430 VIGetRetraceCount (8B) — Dolphin SDK vi/vi.c
//
// Returns the cumulative retrace counter (SDA-resident). MWCC GC-1.2.5n.

extern unsigned int __VIRetraceCount;

extern "C" unsigned int VIGetRetraceCount(void) {
    return __VIRetraceCount;
}
