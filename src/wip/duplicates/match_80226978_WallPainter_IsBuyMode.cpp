// 0x80226978 (12 bytes) - InteractorModule::WallPainter::IsBuyMode(void)
// lwz r3, 136(r3); rlwinm r3,r3,30,31,31; blr  =>  (m_flags >> 2) & 1

struct WallPainter_BM {
    char pad[0x88];
    int m_flags;
    int IsBuyMode();
};
int WallPainter_BM::IsBuyMode() {
    return (m_flags >> 2) & 1;
}
