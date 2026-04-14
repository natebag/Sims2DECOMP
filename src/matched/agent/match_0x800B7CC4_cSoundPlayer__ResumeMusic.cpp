// 0x800B7CC4 cSoundPlayer::ResumeMusic(void) (112B)
// Pattern: 2x null guard + SDA global mgr + cBoxX::Event(52, 0, 0, 0, time) + NotifyViewChange
struct ERSoundEvent;
struct cBoxX {
    void Event(int a, int b, int c, ERSoundEvent* ev, float f);
};
extern cBoxX* g_boxX_ResumeMusic;
extern const float g_time_ResumeMusic[3];

struct cSoundPlayer {
    int m_f0;
    int m_f4;
    int m_f8;
    void NotifyViewChange();
    void ResumeMusic();
};

void cSoundPlayer::ResumeMusic() {
    if (m_f0 == 0) return;
    if (m_f8 == 0) return;
    cBoxX* b = g_boxX_ResumeMusic;
    if (b != 0) {
        b->Event(52, 0, 0, 0, g_time_ResumeMusic[0]);
    }
    NotifyViewChange();
}
