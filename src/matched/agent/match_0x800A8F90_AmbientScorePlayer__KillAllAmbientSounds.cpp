/* AmbientScorePlayer::KillAllAmbientSounds(void) at 0x800A8F90 (184B) */

struct ERAmbientSound;

struct AmbientSoundPlayer {
    int IsValid();
    int Stop();
    void SetAmbientSound(ERAmbientSound *snd);
};

struct AmbientScorePlayer {
    char pad_00[0x0C];
    int m_soundPlayers;
    int m_numPlaying;
    char pad_14[0x08];
    int m_maxSounds;

    int KillAllAmbientSounds();
};

int AmbientScorePlayer::KillAllAmbientSounds()
{
    if (m_soundPlayers == 0) {
        return 1;
    }
    int i = 0;
    int result = 1;
    if (i < m_maxSounds) {
        int offset = 0;
        do {
            if (((AmbientSoundPlayer *)(m_soundPlayers + offset))->IsValid()) {
                if (((AmbientSoundPlayer *)(m_soundPlayers + offset))->Stop() == 0) {
                    result = 0;
                } else {
                    ((AmbientSoundPlayer *)(m_soundPlayers + offset))->SetAmbientSound(0);
                    m_numPlaying--;
                }
            }
            i++;
            offset += 0x30;
        } while (i < m_maxSounds);
    }
    return result;
}
