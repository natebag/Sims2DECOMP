// FLAGS: -fno-schedule-insns
// 0x800B4CB4 CTilePt::GetY(void) (12B)
// lbz r3,1(r3); extsb r3,r3; blr  -- return signed char m_y
struct CTilePt {
    signed char m_x;        // 0x0
    signed char m_y;        // 0x1
    signed char m_level;    // 0x2
    int GetY();
};

int CTilePt::GetY() { return m_y; }
