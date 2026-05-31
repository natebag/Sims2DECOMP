// COMPILER: mwcc
// 0x80254988 OSGetIdleFunction (28B) — Dolphin SDK os/OSThread.c
//
// Returns the idle context if it has been started (state != 0), else null. The
// base address is reused as both the lhz base (state at +0x2C8) and the return
// value, so MWCC materialises it once via lis/addi. bnelr is the positive guard.
// MWCC GC-1.2.5n.

struct OSThread { char _pad[712]; unsigned short state; };
extern OSThread __OSIdleContext;

extern "C" OSThread* OSGetIdleFunction(void) {
    if (__OSIdleContext.state != 0)
        return &__OSIdleContext;
    return 0;
}
