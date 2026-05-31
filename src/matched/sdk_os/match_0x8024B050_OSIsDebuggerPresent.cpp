// COMPILER: mwcc
// 0x8024B050 OSIsDebuggerPresent (12B) — Dolphin SDK db/db.c
//
// Returns the debugger-present flag cached in low memory at 0x80000040.
// Absolute lis/lwz, no relocation. MWCC GC-1.2.5n.

extern "C" int OSIsDebuggerPresent(void) {
    return *(int*)0x80000040;
}
