// 0x800B78B0 cSoundPlayer::EnableSound(bool) (84B)
// Pattern: 2x null guard + direct cBoxX::Event(34, e, 0, 0, time) — no g_boxX null check
struct ERSoundEvent;
struct cBoxX {
    void Event(int a, int b, int c, ERSoundEvent* ev, float f);
};
extern cBoxX* g_boxX_En;
extern const float g_time_En[3];

struct cSoundPlayer {
    int m_f0;
    int m_f4;
    int m_f8;
    void EnableSound(bool e);
};

void cSoundPlayer::EnableSound(bool e) {
    if (m_f0 == 0) return;
    if (m_f8 == 0) return;
    g_boxX_En->Event(34, e, 0, 0, g_time_En[0]);
}
