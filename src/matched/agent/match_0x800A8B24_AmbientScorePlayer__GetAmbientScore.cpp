/* AmbientScorePlayer::GetAmbientScore(void) at 0x800A8B24 (8B) */

struct AmbientScorePlayer {
    char pad[0x08];
    void* m_ambientScore;

    void* GetAmbientScore(void);
};

void* AmbientScorePlayer::GetAmbientScore(void) {
    return m_ambientScore;
}
