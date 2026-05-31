// COMPILER: mwcc
// 0x80253BA4 OSYieldThread (60B) — Dolphin SDK os/OSThread.c
//
// Forces a reschedule under an interrupt-disabled window.
// Metrowerks prologue — MWCC GC-1.2.5n.

extern "C" int OSDisableInterrupts(void);
extern "C" int OSRestoreInterrupts(int level);
extern "C" int SelectThread(int yield);

extern "C" void OSYieldThread(void) {
    int enabled = OSDisableInterrupts();
    SelectThread(1);
    OSRestoreInterrupts(enabled);
}
