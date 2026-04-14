// 0x800B7EB0 cSoundPlayer::NotifyHourChange(void) (84B)
// Pattern: family match with NotifyViewChange — event 46, different float const
struct ERSoundEvent;
struct cBoxX {
    void Event(int a, int b, int c, ERSoundEvent* ev, float f);
};
extern cBoxX* g_boxX_NotifyHourChange;
extern const float g_time_NotifyHourChange[3];

struct cSoundPlayer {
    int m_f0;
    int m_f4;
    int m_f8;
    void NotifyHourChange();
};

void cSoundPlayer::NotifyHourChange() {
    if (m_f0 == 0) return;
    if (m_f8 == 0) return;
    g_boxX_NotifyHourChange->Event(46, 0, 0, 0, g_time_NotifyHourChange[0]);
}
