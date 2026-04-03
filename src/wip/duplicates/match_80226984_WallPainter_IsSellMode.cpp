// 0x80226984 (12 bytes) - InteractorModule::WallPainter::IsSellMode(void)
// lwz r3, 136(r3); rlwinm r3,r3,29,31,31; blr  =>  (m_flags >> 3) & 1

struct WallPainter_SM {
    char pad[0x88];
    int m_flags;
    int IsSellMode();
};
int WallPainter_SM::IsSellMode() {
    return (m_flags >> 3) & 1;
}
