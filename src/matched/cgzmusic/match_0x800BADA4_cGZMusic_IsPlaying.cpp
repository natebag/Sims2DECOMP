// 0x800BADA4 cGZMusic::IsPlaying (8B) — lwz r3, 8(r3)
struct cGZMusic {
    char pad[8];
    int m_isPlaying;
    int IsPlaying();
};
int cGZMusic::IsPlaying() { return m_isPlaying; }
