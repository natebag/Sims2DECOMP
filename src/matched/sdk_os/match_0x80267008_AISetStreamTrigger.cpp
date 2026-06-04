// COMPILER: mwcc
// 0x80267008 AISetStreamTrigger (12B) — Dolphin SDK ai/ai.c
//
// Writes trigger value to AI stream trigger register at 0xCC006C0C.
// Constant address folds to lis r4 + stw r3, 0x6C0C(r4).

extern "C" void AISetStreamTrigger(unsigned int trigger) {
    *(volatile unsigned int*)0xCC006C0C = trigger;
}
