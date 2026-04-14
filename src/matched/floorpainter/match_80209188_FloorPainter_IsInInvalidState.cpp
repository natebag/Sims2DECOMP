// 0x80209188 (12 bytes) - InteractorModule::FloorPainter::IsInInvalidState(void)
// lbz r3, 96(r3); rlwinm r3,r3,27,31,31; blr  =>  return (m_state >> 5) & 1;

struct FloorPainter_I {
    char pad[0x60];
    unsigned char m_state;

    int IsInInvalidState();
};

int FloorPainter_I::IsInInvalidState() {
    return (m_state >> 5) & 1;
}
