// 0x8020917C (12 bytes) - InteractorModule::FloorPainter::IsInConfirmedState(void)
// lbz r3, 96(r3); rlwinm r3,r3,28,31,31; blr  =>  return (m_state >> 4) & 1;

struct FloorPainter_C {
    char pad[0x60];
    unsigned char m_state;

    int IsInConfirmedState();
};

int FloorPainter_C::IsInConfirmedState() {
    return (m_state >> 4) & 1;
}
