// COMPILER: mwcc
// 0x80253B74 OSReschedule (48B) — Dolphin SDK os/OSThread.c
//
// When the reschedule-disable count is clear, hands the CPU to the scheduler.
// __OSReschedule is the SDA-resident disable counter; SelectThread(0) performs
// the context switch. Metrowerks prologue (mflr; stw r0,4(r1); stwu). MWCC
// GC-1.2.5n.

extern int __OSReschedule;
extern "C" int SelectThread(int yield);

extern "C" void OSReschedule(void) {
    if (__OSReschedule != 0)
        SelectThread(0);
}
