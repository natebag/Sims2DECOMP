// COMPILER: mwcc
// 0x8025A86C DBIsDebuggerPresent (28B) — Dolphin SDK db/db.c
//
// Returns the debugger-present flag via the SDA interface pointer, or 0 when no
// interface is registered. The negative (early-return-on-null) guard produces
// the DOL's bne-to-deref with the return-0 inline. MWCC GC-1.2.5n.

extern int* __DBInterface;

extern "C" int DBIsDebuggerPresent(void) {
    if (__DBInterface == 0)
        return 0;
    return *__DBInterface;
}
