// COMPILER: mwcc
// LANG: c
// 0x802534BC OSIsThreadTerminated (52B) — Dolphin SDK os/OSThread.c
//
// Returns TRUE when the thread is in the MORIBUND (8) or zero state.
// thread->state is a u16 at offset 0x2C8 (712). Must compile as C: the C `||`
// yields an int (full-word cmpwi boolify + r0/r3 split that the DOL uses),
// whereas C++ `||` yields bool — MWCC then byte-tests (rlwinm.,24,31) and
// allocates the temp to r3. Routed through mwcceppc -lang c. MWCC GC-1.2.5n.

struct OSThread { char _pad[712]; unsigned short state; };

int OSIsThreadTerminated(struct OSThread* thread) {
    int result = (thread->state == 8 || thread->state == 0);
    return result ? 1 : 0;
}
