// COMPILER: mwcc
// 0x80261DE8 DVDLowSetWAType (68B) — Dolphin SDK dvd/dvdlow.c
//
// Atomically stores two DVD work-around parameters to SDA globals while
// interrupts are disabled. DOL uses addi-form register saves (r30/r31).

extern void *__DVDLowWAParam0;
extern void *__DVDLowWAParam1;

extern "C" int OSDisableInterrupts(void);
extern "C" void OSRestoreInterrupts(int level);

extern "C" void DVDLowSetWAType(void *type, void *param) {
    int level = OSDisableInterrupts();
    __DVDLowWAParam0 = type;
    __DVDLowWAParam1 = param;
    OSRestoreInterrupts(level);
}
