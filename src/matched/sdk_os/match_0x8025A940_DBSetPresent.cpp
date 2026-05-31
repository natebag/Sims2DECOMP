// COMPILER: mwcc
// 0x8025A940 DBSetPresent (12B) — Dolphin SDK db/db.c
//
// Stores the debugger-present flag through the SDA-resident interface pointer.
// MWCC GC-1.2.5n.

extern int* __DBInterface;

extern "C" void DBSetPresent(int present) {
    *__DBInterface = present;
}
