// FLAGS: -fno-schedule-insns
struct EGlobal {
    char p0[0x3BC]; int m_c3BC; int m_c3C0; char p1[4]; int m_c3C8;
    char p2[16]; int m_c3DC; char p3[4]; int m_c3E4; int m_c3E8;
    char p4[4]; int m_c3F0; char p5[16]; int m_c404;
    void SetAuthorModeCheats();
};
void EGlobal::SetAuthorModeCheats() {
    m_c3E4 = 1; m_c3BC = 1; m_c3C0 = 1; m_c3C8 = 1;
    m_c3DC = 1; m_c3E8 = 1; m_c3F0 = 1; m_c404 = 1;
}
