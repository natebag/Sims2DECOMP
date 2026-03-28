/* AmbientScorePlayer::GetVolume(void) at 0x800A8B1C (8B) */

struct AmbientScorePlayer {
    char pad[0x14];
    int m_volume;

    int GetVolume(void);
};

int AmbientScorePlayer::GetVolume(void) {
    return m_volume;
}
