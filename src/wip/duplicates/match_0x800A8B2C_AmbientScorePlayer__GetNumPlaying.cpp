/* AmbientScorePlayer::GetNumPlaying(void) at 0x800A8B2C (8B) */

struct AmbientScorePlayer {
    char pad[0x10];
    int m_numPlaying;

    int GetNumPlaying(void);
};

int AmbientScorePlayer::GetNumPlaying(void) {
    return m_numPlaying;
}
