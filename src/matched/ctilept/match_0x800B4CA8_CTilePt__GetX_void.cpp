// FLAGS: -fno-schedule-insns
// 0x800B4CA8 CTilePt::GetX(void) (12B)
// lbz r3,0(r3); extsb r3,r3; blr  -- return signed char m_x
struct CTilePt {
    signed char m_x;        // 0x0
    signed char m_y;        // 0x1
    signed char m_level;    // 0x2
    int GetX();
};

int CTilePt::GetX() { return m_x; }
