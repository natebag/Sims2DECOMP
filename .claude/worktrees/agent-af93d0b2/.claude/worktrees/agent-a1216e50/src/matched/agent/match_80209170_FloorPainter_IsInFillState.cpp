// 0x80209170 (12 bytes) - InteractorModule::FloorPainter::IsInFillState(void)
// lbz r3, 96(r3); rlwinm r3,r3,31,31,31; blr  =>  return (m_state >> 1) & 1;

struct FloorPainter_F {
    char pad[0x60];
    unsigned char m_state;

    int IsInFillState();
};

int FloorPainter_F::IsInFillState() {
    return (m_state >> 1) & 1;
}
