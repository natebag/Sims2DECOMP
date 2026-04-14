// 0x800B7B20 cSoundPlayer::QuietBySourceID(int) (84B)
// Pattern: 2x null guard + cBoxX::Event(23, 0, id, 0, time)
struct ERSoundEvent;
struct cBoxX {
    void Event(int a, int b, int c, ERSoundEvent* ev, float f);
};
extern cBoxX* g_boxX_QuietBySourceID;
extern const float g_time_QuietBySourceID[3];

struct cSoundPlayer {
    int m_f0;
    int m_f4;
    int m_f8;
    void QuietBySourceID(int id);
};

void cSoundPlayer::QuietBySourceID(int id) {
    if (m_f0 == 0) return;
    if (m_f8 == 0) return;
    g_boxX_QuietBySourceID->Event(23, 0, id, 0, g_time_QuietBySourceID[0]);
}
