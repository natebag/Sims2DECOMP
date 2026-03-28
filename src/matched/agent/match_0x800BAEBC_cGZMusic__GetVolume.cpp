/* cGZMusic::GetVolume(void) at 0x800BAEBC (8B) */

struct cGZMusic {
    char pad[0x14];
    int m_volume;

    int GetVolume(void);
};

int cGZMusic::GetVolume(void) {
    return m_volume;
}
