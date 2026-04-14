// 0x80209158 (12 bytes) - InteractorModule::FloorPainter::IsInBuildState(void)
// lbz r3, 96(r3); rlwinm r3,r3,30,31,31; blr  =>  return (m_state >> 2) & 1;

struct FloorPainter_B {
    char pad[0x60];
    unsigned char m_state;

    int IsInBuildState();
};

int FloorPainter_B::IsInBuildState() {
    return (m_state >> 2) & 1;
}
