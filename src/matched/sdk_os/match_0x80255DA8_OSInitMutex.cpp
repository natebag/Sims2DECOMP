// COMPILER: mwcc
// 0x80255DA8 OSInitMutex (56B) — Dolphin SDK os/OSMutex.c
//
// Initializes a mutex: empties its wait queue, clears owner + lock count.
// queue@0x00, thread@0x08, count@0x0C. MWCC GC-1.2.5n.

struct OSThreadQueue { void* head; void* tail; };
struct OSMutex { OSThreadQueue queue; void* thread; int count; };
extern "C" void OSInitThreadQueue(OSThreadQueue* queue);

extern "C" void OSInitMutex(OSMutex* mutex) {
    OSInitThreadQueue(&mutex->queue);
    mutex->thread = 0;
    mutex->count = 0;
}
