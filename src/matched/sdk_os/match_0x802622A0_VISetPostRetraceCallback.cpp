// COMPILER: mwcc
// 0x802622A0 VISetPostRetraceCallback (68B) — Dolphin SDK vi/vi.c
//
// Atomically swaps the VI post-retrace callback. Same interrupt-protected pattern
// as VISetPreRetraceCallback; SDA global at -23264(r13).

typedef void (*VIRetraceCallback)(unsigned int count);
extern VIRetraceCallback __VIPostRetraceCallback;

extern "C" void OSDisableInterrupts(void);
extern "C" void OSRestoreInterrupts(void);

extern "C" VIRetraceCallback VISetPostRetraceCallback(VIRetraceCallback callback) {
    VIRetraceCallback old = __VIPostRetraceCallback;
    OSDisableInterrupts();
    __VIPostRetraceCallback = callback;
    OSRestoreInterrupts();
    return old;
}
