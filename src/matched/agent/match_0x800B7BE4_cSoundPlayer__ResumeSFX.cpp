// 0x800B7BE4 cSoundPlayer::ResumeSFX(void) (112B)
// Pattern: 2x null guard + SDA global mgr + cBoxX::Event(50, 0, 0, 0, time) + NotifyViewChange
struct ERSoundEvent;
struct cBoxX {
    void Event(int a, int b, int c, ERSoundEvent* ev, float f);
};
extern cBoxX* g_boxX_ResumeSFX;
extern const float g_time_ResumeSFX[3];

struct cSoundPlayer {
    int m_f0;
    int m_f4;
    int m_f8;
    void NotifyViewChange();
    void ResumeSFX();
};

void cSoundPlayer::ResumeSFX() {
    if (m_f0 == 0) return;
    if (m_f8 == 0) return;
    cBoxX* b = g_boxX_ResumeSFX;
    if (b != 0) {
        b->Event(50, 0, 0, 0, g_time_ResumeSFX[0]);
    }
    NotifyViewChange();
}
