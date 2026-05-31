// FLAGS: -fno-schedule-insns
// 0x800B4DDC CTilePt::GetLevel(void) (12B)
// lbz r3,2(r3); extsb r3,r3; blr  -- return signed char m_level
struct CTilePt {
    signed char m_x;        // 0x0
    signed char m_y;        // 0x1
    signed char m_level;    // 0x2
    int GetLevel();
};

int CTilePt::GetLevel() { return m_level; }
