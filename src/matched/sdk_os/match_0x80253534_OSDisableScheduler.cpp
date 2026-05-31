// COMPILER: mwcc
// 0x80253534 OSDisableScheduler (64B) — Dolphin SDK os/OSThread.c
//
// Bumps the reschedule-disable count under an interrupt-disabled window and
// returns the previous count. Metrowerks prologue (mflr; stw r0,4(r1); stwu;
// stw r31) — matches MWCC GC-1.2.5n, NOT SN ProDG (which emits stwu-first +
// stmw). Confirms the DolphinSDK proper is Metrowerks-compiled.

extern "C" int OSDisableInterrupts(void);
extern "C" int OSRestoreInterrupts(int level);
extern int __OSReschedule;

extern "C" int OSDisableScheduler(void) {
    int enabled = OSDisableInterrupts();
    int count = __OSReschedule;
    __OSReschedule = count + 1;
    OSRestoreInterrupts(enabled);
    return count;
}
