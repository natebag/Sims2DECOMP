// COMPILER: mwcc
// 0x80266E4C AIRegisterDMACallback (68B) — Dolphin SDK ai/ai.c
//
// Atomically swaps the AI DMA callback. Saves old callback from SDA before
// disabling interrupts, stores new callback after, returns old.

typedef void (*AICallback)(unsigned int nSamples);
extern AICallback __AIDMACallback;

extern "C" void OSDisableInterrupts(void);
extern "C" void OSRestoreInterrupts(void);

extern "C" AICallback AIRegisterDMACallback(AICallback callback) {
    AICallback old = __AIDMACallback;
    OSDisableInterrupts();
    __AIDMACallback = callback;
    OSRestoreInterrupts();
    return old;
}
