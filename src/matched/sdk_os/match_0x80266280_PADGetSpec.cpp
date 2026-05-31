// COMPILER: mwcc
// 0x80266280 PADGetSpec (8B) — Dolphin SDK pad/Pad.c
//
// Returns the active controller-spec selector (SDA-resident). MWCC GC-1.2.5n.

extern unsigned int __PADSpec;

extern "C" unsigned int PADGetSpec(void) {
    return __PADSpec;
}
