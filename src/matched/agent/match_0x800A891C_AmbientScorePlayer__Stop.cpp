// 0x800A891C AmbientScorePlayer::Stop (56b)

struct AmbientScorePlayer {
    int m_state;
    char pad[0x34];
    int KillAllAmbientSounds();
    bool Stop();
};

bool AmbientScorePlayer::Stop() {
    this->m_state = 0;
    if (this->KillAllAmbientSounds() == 0) {
        return 0;
    }
    return 1;
}
