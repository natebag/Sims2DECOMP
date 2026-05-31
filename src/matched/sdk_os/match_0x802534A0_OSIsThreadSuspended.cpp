// COMPILER: mwcc
// 0x802534A0 OSIsThreadSuspended (28B) — Dolphin SDK os/OSThread.c
//
// Returns TRUE when the thread's suspend count is positive. suspend is a
// signed int at offset 0x2CC (716); the field is compared directly against
// zero (cmpwi/ble) with twin blr tails. MWCC GC-1.2.5n.

struct OSThread { char _pad[716]; int suspend; };

extern "C" int OSIsThreadSuspended(OSThread* thread) {
    return thread->suspend > 0 ? 1 : 0;
}
