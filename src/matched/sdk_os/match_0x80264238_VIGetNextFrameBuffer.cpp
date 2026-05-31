// COMPILER: mwcc
// 0x80264238 VIGetNextFrameBuffer (8B) — Dolphin SDK vi/vi.c
//
// Returns the queued next-frame XFB pointer (SDA-resident). MWCC GC-1.2.5n.

extern void* __VINextFrameBuffer;

extern "C" void* VIGetNextFrameBuffer(void) {
    return __VINextFrameBuffer;
}
