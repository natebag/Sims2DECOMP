// COMPILER: mwcc
// 0x8024C7AC OSAllocFromArenaHi (32B) — Dolphin SDK os/OSArena.c
//
// Allocates from the top of the arena: aligns arenaHi down, subtracts size,
// aligns result, stores back to SDA. Returns aligned pointer.

extern void *__OSArenaHi;

extern "C" void *OSAllocFromArenaHi(int size, int alignment) {
    unsigned int mask = ~((unsigned int)alignment - 1);
    unsigned int hi = (unsigned int)__OSArenaHi;
    hi &= mask;
    hi -= (unsigned int)size;
    unsigned int ptr = hi & mask;
    __OSArenaHi = (void*)ptr;
    return (void*)ptr;
}
