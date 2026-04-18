// 0x80238334 (20B) ERLevel::ClearWallIndexSaves(void)

struct ERLevel_CWS {
    char pad[0x2C2BC];
    int m_2C2BC;
    int m_2C2C0;
    void ClearWallIndexSaves();
};

void ERLevel_CWS::ClearWallIndexSaves() {
    m_2C2BC = -1;
    m_2C2C0 = -1;
}
