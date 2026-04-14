// 0x800B7C54 cSoundPlayer::PauseMusic(void) (112B)
// Pattern: 2x null guard + SDA global mgr + cBoxX::Event(51, 0, 0, 0, time) + NotifyViewChange
struct ERSoundEvent;
struct cBoxX {
    void Event(int a, int b, int c, ERSoundEvent* ev, float f);
};
extern cBoxX* g_boxX_PauseMusic;
extern const float g_time_PauseMusic[3];

struct cSoundPlayer {
    int m_f0;
    int m_f4;
    int m_f8;
    void NotifyViewChange();
    void PauseMusic();
};

void cSoundPlayer::PauseMusic() {
    if (m_f0 == 0) return;
    if (m_f8 == 0) return;
    cBoxX* b = g_boxX_PauseMusic;
    if (b != 0) {
        b->Event(51, 0, 0, 0, g_time_PauseMusic[0]);
    }
    NotifyViewChange();
}
