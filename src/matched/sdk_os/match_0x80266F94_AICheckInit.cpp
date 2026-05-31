// COMPILER: mwcc
// 0x80266F94 AICheckInit (8B) — Dolphin SDK ai/ai.c
//
// Returns the AI subsystem initialised flag (SDA-resident). MWCC GC-1.2.5n.

extern int __AI_init_flag;

extern "C" int AICheckInit(void) {
    return __AI_init_flag;
}
