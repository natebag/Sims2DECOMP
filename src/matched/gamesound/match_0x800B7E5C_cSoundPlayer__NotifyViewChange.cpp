// 0x800B7E5C cSoundPlayer::NotifyViewChange(void) (84B)
// Pattern: 2x null guard + cBoxX::Event(46, 0, 0, 0, time) — no args pass through
struct ERSoundEvent;
struct cBoxX {
    void Event(int a, int b, int c, ERSoundEvent* ev, float f);
};
extern cBoxX* g_boxX_NotifyViewChange;
extern const float g_time_NotifyViewChange[3];

struct cSoundPlayer {
    int m_f0;
    int m_f4;
    int m_f8;
    void NotifyViewChange();
};

void cSoundPlayer::NotifyViewChange() {
    if (m_f0 == 0) return;
    if (m_f8 == 0) return;
    g_boxX_NotifyViewChange->Event(46, 0, 0, 0, g_time_NotifyViewChange[0]);
}
