// 0x800B7B74 cSoundPlayer::PauseSFX(void) (112B)
// Pattern: 2x null guard + SDA global mgr + cBoxX::Event(49, 0, 0, 0, time) + NotifyViewChange
struct ERSoundEvent;
struct cBoxX {
    void Event(int a, int b, int c, ERSoundEvent* ev, float f);
};
extern cBoxX* g_boxX_PauseSFX;
extern const float g_time_PauseSFX[3];

struct cSoundPlayer {
    int m_f0;
    int m_f4;
    int m_f8;
    void NotifyViewChange();
    void PauseSFX();
};

void cSoundPlayer::PauseSFX() {
    if (m_f0 == 0) return;
    if (m_f8 == 0) return;
    cBoxX* b = g_boxX_PauseSFX;
    if (b != 0) {
        b->Event(49, 0, 0, 0, g_time_PauseSFX[0]);
    }
    NotifyViewChange();
}
