// 0x80209164 (12 bytes) - InteractorModule::FloorPainter::IsInRemoveState(void)
// lbz r3, 96(r3); rlwinm r3,r3,29,31,31; blr  =>  return (m_state >> 3) & 1;

struct FloorPainter_R {
    char pad[0x60];
    unsigned char m_state;

    int IsInRemoveState();
};

int FloorPainter_R::IsInRemoveState() {
    return (m_state >> 3) & 1;
}
