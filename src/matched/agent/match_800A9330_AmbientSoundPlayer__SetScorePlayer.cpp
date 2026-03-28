// 0x800A9330 (8 bytes)
class AmbientScorePlayer;

class AmbientSoundPlayer {
public:
    AmbientScorePlayer *m_scorePlayer;

    void SetScorePlayer(AmbientScorePlayer *p);
};

void AmbientSoundPlayer::SetScorePlayer(AmbientScorePlayer *p) {
    m_scorePlayer = p;
}
