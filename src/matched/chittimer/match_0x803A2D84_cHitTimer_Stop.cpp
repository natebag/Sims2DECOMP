// 0x803A2D84 cHitTimer::Stop (16B) — zero first field, return 1
struct cHitTimer {
    int m_active;
    int Stop();
};
int cHitTimer::Stop() { m_active = 0; return 1; }
