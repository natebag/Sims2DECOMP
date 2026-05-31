// COMPILER: mwcc
// 0x80261D24 DVDLowBreak (20B) — Dolphin SDK dvd/dvdlow.c
//
// Requests a low-level DVD break: raises both SDA-resident break flags and
// returns success. The return value is materialised between the two stores.
// MWCC GC-1.2.5n.

extern int __DVDResetRequired;
extern int __DVDBreakRequested;

extern "C" int DVDLowBreak(void) {
    __DVDResetRequired = 1;
    __DVDBreakRequested = 1;
    return 1;
}
