// 0x80388790 (12 bytes)
// stw r4, 12(r3); stw r5, 16(r3); blr
typedef unsigned int u32;
typedef struct GXFifoObj {
    int pad0; int pad1; int pad2;
    u32 hiWatermark; // 0x0C
    u32 loWatermark; // 0x10
} GXFifoObj;
void GXInitFifoLimits(GXFifoObj* fifo, u32 hi, u32 lo) {
    fifo->hiWatermark = hi;
    fifo->loWatermark = lo;
}
