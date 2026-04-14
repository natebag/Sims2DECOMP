// 0x800B7ACC cSoundPlayer::PlayBySource(ERSoundEvent*, short) (84B)
// Pattern: 4x guard + cBoxX::MappedEvent(ev, prio, time)
struct ERSoundEvent {};
struct cBoxX {
    void PlayEvent(ERSoundEvent* ev, short prio, float time);
};
extern cBoxX* g_boxX_PlayBy_ev;
extern const float g_time_PlayBy_ev[3];

struct cSoundPlayer {
    int m_f0;
    int m_f4;
    int m_f8;
    void PlayBySource(ERSoundEvent* ev, short prio);
};

void cSoundPlayer::PlayBySource(ERSoundEvent* ev, short prio) {
    if (m_f0 == 0) return;
    if (m_f8 == 0) return;
    if (ev == 0) return;
    if (prio == -2) return;
    g_boxX_PlayBy_ev->PlayEvent(ev, prio, g_time_PlayBy_ev[0]);
}
