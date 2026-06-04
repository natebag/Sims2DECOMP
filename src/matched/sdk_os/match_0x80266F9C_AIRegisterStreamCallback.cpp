// COMPILER: mwcc
// 0x80266F9C AIRegisterStreamCallback (68B) — Dolphin SDK ai/ai.c
//
// Atomically swaps the AI stream callback. Same interrupt-protected pattern as
// AIRegisterDMACallback but uses __AIStreamCallback SDA global at -23136(r13).

typedef void (*AICallback)(unsigned int nSamples);
extern AICallback __AIStreamCallback;

extern "C" void OSDisableInterrupts(void);
extern "C" void OSRestoreInterrupts(void);

extern "C" AICallback AIRegisterStreamCallback(AICallback callback) {
    AICallback old = __AIStreamCallback;
    OSDisableInterrupts();
    __AIStreamCallback = callback;
    OSRestoreInterrupts();
    return old;
}
