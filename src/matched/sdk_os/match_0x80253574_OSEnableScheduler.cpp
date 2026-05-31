// COMPILER: mwcc
// 0x80253574 OSEnableScheduler (64B) — Dolphin SDK os/OSThread.c
//
// Decrements the reschedule-disable count under an interrupt-disabled window
// and returns the previous count. Twin of OSDisableScheduler (count - 1).
// Metrowerks prologue — MWCC GC-1.2.5n, not SN ProDG.

extern "C" int OSDisableInterrupts(void);
extern "C" int OSRestoreInterrupts(int level);
extern int __OSReschedule;

extern "C" int OSEnableScheduler(void) {
    int enabled = OSDisableInterrupts();
    int count = __OSReschedule;
    __OSReschedule = count - 1;
    OSRestoreInterrupts(enabled);
    return count;
}
