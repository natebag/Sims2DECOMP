// 0x800A8B2C (8 bytes)
class AmbientScorePlayer {
public:
    char pad[16];
    int m_numPlaying;

    int GetNumPlaying(void);
};

int AmbientScorePlayer::GetNumPlaying(void) {
    return m_numPlaying;
}
