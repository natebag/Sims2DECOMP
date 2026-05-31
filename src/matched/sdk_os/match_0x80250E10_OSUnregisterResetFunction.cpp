// COMPILER: mwcc
// 0x80250E10 OSUnregisterResetFunction (56B) — Dolphin SDK os/OSReset.c
//
// Unlinks a reset-function node from the doubly-linked reset queue.
// node: next@0x08, prev@0x0C. Queue (SDA -23632): head@0x00, tail@0x04.
// MWCC GC-1.2.5n.

struct OSResetFunctionInfo {
    void* func;                  // 0x00
    unsigned int priority;       // 0x04
    OSResetFunctionInfo* next;   // 0x08
    OSResetFunctionInfo* prev;   // 0x0C
};
struct OSResetQueue { OSResetFunctionInfo* head; OSResetFunctionInfo* tail; };
extern OSResetQueue __OSResetFunctionQueue;

extern "C" void OSUnregisterResetFunction(OSResetFunctionInfo* info) {
    OSResetFunctionInfo* next = info->next;
    OSResetFunctionInfo* prev = info->prev;
    if (next == 0)
        __OSResetFunctionQueue.tail = prev;
    else
        next->prev = prev;
    if (prev == 0)
        __OSResetFunctionQueue.head = next;
    else
        prev->next = next;
}
