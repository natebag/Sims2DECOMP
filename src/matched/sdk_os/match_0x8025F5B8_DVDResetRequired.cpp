// COMPILER: mwcc
// 0x8025F5B8 DVDResetRequired (8B) — Dolphin SDK dvd/dvd.c
//
// Returns the cached "reset required" flag (SDA-resident). MWCC GC-1.2.5n.

extern int __DVDResetRequired;

extern "C" int DVDResetRequired(void) {
    return __DVDResetRequired;
}
