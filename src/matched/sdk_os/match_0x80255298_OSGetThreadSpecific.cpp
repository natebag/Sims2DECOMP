// COMPILER: mwcc
// 0x80255298 OSGetThreadSpecific (56B) — Dolphin SDK os/OSThread.c
//
// Reads a per-thread value from the current thread's specific[] slot, with
// bounds checks (returns 0 if no thread / out of range). OS_CURRENT_THREAD =
// *(OSThread**)0x800000E4 (absolute). specific[2] at offset 784. MWCC GC-1.2.5n.

struct OSThread { char _pad[784]; void* specific[2]; };

extern "C" void* OSGetThreadSpecific(long index) {
    OSThread* thread = *(OSThread**)0x800000E4;
    if (thread != 0 && index >= 0 && index < 2)
        return thread->specific[index];
    return 0;
}
