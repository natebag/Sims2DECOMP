/* cGZMusic::IsPlaying(void) at 0x800BADA4 (8B) */

struct cGZMusic {
    char pad[0x08];
    int m_isPlaying;

    int IsPlaying(void);
};

int cGZMusic::IsPlaying(void) {
    return m_isPlaying;
}
