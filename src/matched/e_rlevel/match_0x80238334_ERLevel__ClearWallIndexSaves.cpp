/* 0x80238334 (20 bytes) - ERLevel::ClearWallIndexSaves(void) */
struct ERLevel {
    char pad[0x2C2BC];
    int m_wallIndexSave0;
    int m_wallIndexSave1;
    void ClearWallIndexSaves();
};

void ERLevel::ClearWallIndexSaves() {
    m_wallIndexSave0 = -1;
    m_wallIndexSave1 = -1;
}
