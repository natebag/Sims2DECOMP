// COMPILER: mwcc
// 0x8026225C VISetPreRetraceCallback (68B) — Dolphin SDK vi/vi.c
//
// Atomically swaps the VI pre-retrace callback. Same interrupt-protected pattern
// as AIRegisterDMACallback; SDA global at -23268(r13).

typedef void (*VIRetraceCallback)(unsigned int count);
extern VIRetraceCallback __VIPreRetraceCallback;

extern "C" void OSDisableInterrupts(void);
extern "C" void OSRestoreInterrupts(void);

extern "C" VIRetraceCallback VISetPreRetraceCallback(VIRetraceCallback callback) {
    VIRetraceCallback old = __VIPreRetraceCallback;
    OSDisableInterrupts();
    __VIPreRetraceCallback = callback;
    OSRestoreInterrupts();
    return old;
}
