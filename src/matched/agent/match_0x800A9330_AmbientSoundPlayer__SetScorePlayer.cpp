/* AmbientSoundPlayer::SetScorePlayer(AmbientScorePlayer *) at 0x800A9330 (8B) */

struct AmbientScorePlayer;

struct AmbientSoundPlayer {
    AmbientScorePlayer* m_scorePlayer;

    void SetScorePlayer(AmbientScorePlayer* p);
};

void AmbientSoundPlayer::SetScorePlayer(AmbientScorePlayer* p) {
    m_scorePlayer = p;
}
