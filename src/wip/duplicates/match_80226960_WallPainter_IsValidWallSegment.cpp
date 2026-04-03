// 0x80226960 (12 bytes) - InteractorModule::WallPainter::IsValidWallSegment(void)
// lwz r3, 136(r3); rlwinm r3,r3,25,31,31; blr  =>  (m_flags >> 7) & 1

struct WallPainter_V {
    char pad[0x88];
    int m_flags;
    int IsValidWallSegment();
};
int WallPainter_V::IsValidWallSegment() {
    return (m_flags >> 7) & 1;
}
