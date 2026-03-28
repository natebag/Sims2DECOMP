/* AmbientScorePlayer::RemoveAmbientSoundPlayer(ERAmbientSound *) at 0x800A90DC (188B) */

struct ERAmbientSound;

struct AmbientSoundPlayer {
    int IsValid();
    ERAmbientSound *GetAmbientSound();
    int Stop();
    void SetAmbientSound(ERAmbientSound *snd);
};

struct AmbientScorePlayer {
    char pad_00[0x0C];
    int m_soundPlayers;
    int m_numPlaying;
    char pad_14[0x08];
    int m_maxSounds;

    int RemoveAmbientSoundPlayer(ERAmbientSound *snd);
};

int AmbientScorePlayer::RemoveAmbientSoundPlayer(ERAmbientSound *snd)
{
    int i = 0;
    if (i < m_maxSounds) {
        int offset = 0;
        do {
            if (((AmbientSoundPlayer *)(m_soundPlayers + offset))->IsValid()) {
                if (((AmbientSoundPlayer *)(m_soundPlayers + offset))->GetAmbientSound() == snd) {
                    if (((AmbientSoundPlayer *)(m_soundPlayers + offset))->Stop() == 0) {
                        return 0;
                    }
                    ((AmbientSoundPlayer *)(m_soundPlayers + offset))->SetAmbientSound(0);
                    m_numPlaying--;
                    return 1;
                }
            }
            i++;
            offset += 0x30;
        } while (i < m_maxSounds);
    }
    return 0;
}
