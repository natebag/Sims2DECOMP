// 0x80226948 (24B) InteractorModule::WallPainter::IsAnchored(void)

struct WallPainter {
    char pad[136];
    unsigned int m_flags;
    bool IsAnchored();
};

bool WallPainter::IsAnchored() {
    if ((m_flags & 1) == 0) return 0;
    return 1;
}
