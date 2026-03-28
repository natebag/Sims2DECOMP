// 0x8022696C (12 bytes) - InteractorModule::WallPainter::IsRoomPreview(void)
// lwz r3, 136(r3); rlwinm r3,r3,28,31,31; blr  =>  (m_flags >> 4) & 1

struct WallPainter_RP {
    char pad[0x88];
    int m_flags;
    int IsRoomPreview();
};
int WallPainter_RP::IsRoomPreview() {
    return (m_flags >> 4) & 1;
}
