// VERSION_DIFF: DOL uses mr r11,r3 + preload r3=1 + bgtlr cr0 for the float comparison return.
// SN ProDG v3.93 generates mfcr+rlwinm pattern for all float-comparison-based int returns.
// Also: register allocation differs — DOL has f12=_dt, f13=0.5f; ours gives f13=_dt, f12=0.5f.
// All field accesses use r11 (this copy) in DOL vs r3 (this) in our output — 0/15 bytes match.
//
// Logic is correct: decrement cancel timer by _dt each call, return 1 when timer exceeds 0.5s.
// 0x80204FD8 (60B) InteractorModule::DirectInteractor::CheckCancelTimer(void)

extern float _dt;

struct DirectInteractor {
    char pad[0x84];
    int m_cancelTimerFlag;
    float m_cancelTimer;
    int CheckCancelTimer();
};

int DirectInteractor::CheckCancelTimer() {
    if (m_cancelTimerFlag != 1) return 0;
    m_cancelTimer += _dt;
    if (m_cancelTimer > 0.5f) return 1;
    return 0;
}
