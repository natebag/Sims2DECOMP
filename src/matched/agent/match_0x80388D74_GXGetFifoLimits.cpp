// FLAGS: -fno-schedule-insns
// 0x80388D74 GXGetFifoLimits (20B)
// lwz r0,0xc(r3); stw r0,0(r4); lwz r0,0x10(r3); stw r0,0(r5); blr
struct GXFifoObj {
    char pad[12];
    int m_lo;   // offset 0xc
    int m_hi;   // offset 0x10
};
void GXGetFifoLimits(const GXFifoObj* fifo, int* lo, int* hi) {
    int v = fifo->m_lo;
    *lo = v;
    v = fifo->m_hi;
    *hi = v;
}
