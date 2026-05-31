// COMPILER: mwcc
// 0x80264240 VIGetCurrentFrameBuffer (8B) — Dolphin SDK vi/vi.c
//
// Returns the currently-scanned XFB pointer (SDA-resident). MWCC GC-1.2.5n.

extern void* __VICurrentFrameBuffer;

extern "C" void* VIGetCurrentFrameBuffer(void) {
    return __VICurrentFrameBuffer;
}
