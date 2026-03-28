class AmbientScorePlayer {
public:
    int m_state;
    int pad_004;
    void *m_ambientScore;
    int pad_00C;
    int m_numPlaying;
    int m_volume;

    int SetVolume(int volume);
};

int AmbientScorePlayer::SetVolume(int volume) {
    m_volume = volume;
    return 1;
}
