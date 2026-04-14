// 0x8020913C (12 bytes) - InteractorModule::FloorPainter::IsInAnchorState(void)
// lbz r3, 96(r3); rlwinm r3,r3,0,31,31; blr  =>  return m_state & 1;

struct FloorPainter {
    char pad[0x60];
    unsigned char m_state;

    int IsInAnchorState();
};

int FloorPainter::IsInAnchorState() {
    return m_state & 1;
}
