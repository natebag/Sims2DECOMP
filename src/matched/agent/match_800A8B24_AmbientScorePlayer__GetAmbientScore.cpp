// 0x800A8B24 (8 bytes)
class AmbientScorePlayer {
public:
    char pad[8];
    void *m_ambientScore;

    void *GetAmbientScore(void);
};

void *AmbientScorePlayer::GetAmbientScore(void) {
    return m_ambientScore;
}
