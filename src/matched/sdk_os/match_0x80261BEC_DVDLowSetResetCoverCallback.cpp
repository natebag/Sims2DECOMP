// COMPILER: mwcc
// 0x80261BEC DVDLowSetResetCoverCallback (68B) — Dolphin SDK dvd/dvdlow.c
//
// Atomically swaps the DVD reset/cover callback. Disables interrupts first
// (saves level in r3), loads old after, stores new, restores. Returns old.

typedef void (*DVDLowCallback)(unsigned int status);
extern DVDLowCallback __DVDLowResetCoverCallback;

extern "C" int OSDisableInterrupts(void);
extern "C" void OSRestoreInterrupts(int level);

extern "C" DVDLowCallback DVDLowSetResetCoverCallback(DVDLowCallback callback) {
    int level = OSDisableInterrupts();
    DVDLowCallback old = __DVDLowResetCoverCallback;
    __DVDLowResetCoverCallback = callback;
    OSRestoreInterrupts(level);
    return old;
}
