// COMPILER: mwcc
// 0x80255268 OSSetThreadSpecific (48B) — Dolphin SDK os/OSThread.c
//
// Stores a per-thread value into the current thread's specific[] slot, with
// bounds checks. OS_CURRENT_THREAD = *(OSThread**)0x800000E4 (absolute, no
// relocation). specific[2] lives at offset 784. MWCC GC-1.2.5n.

struct OSThread { char _pad[784]; void* specific[2]; };

extern "C" void OSSetThreadSpecific(long index, void* value) {
    OSThread* thread = *(OSThread**)0x800000E4;
    if (thread == 0) return;
    if (index < 0) return;
    if (index >= 2) return;
    thread->specific[index] = value;
}
