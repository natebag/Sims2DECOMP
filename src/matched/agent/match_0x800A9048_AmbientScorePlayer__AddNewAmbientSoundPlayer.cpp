/* AmbientScorePlayer::AddNewAmbientSoundPlayer(ERAmbientSound *) at 0x800A9048 (148B) */

struct ERAmbientSound;

struct AmbientSoundPlayer {
    int IsValid();
    void SetAmbientSound(ERAmbientSound *snd);
};

struct AmbientScorePlayer {
    char pad_00[0x0C];
    int m_soundPlayers;
    int m_numPlaying;
    char pad_14[0x08];
    int m_maxSounds;

    int AddNewAmbientSoundPlayer(ERAmbientSound *snd);
};

int AmbientScorePlayer::AddNewAmbientSoundPlayer(ERAmbientSound *snd)
{
    int i = 0;
    if (i < m_maxSounds) {
        int offset = 0;
        do {
            if (!((AmbientSoundPlayer *)(m_soundPlayers + offset))->IsValid()) {
                ((AmbientSoundPlayer *)(m_soundPlayers + offset))->SetAmbientSound(snd);
                m_numPlaying++;
                return (int)((AmbientSoundPlayer *)(m_soundPlayers + offset));
            }
            i++;
            offset += 0x30;
        } while (i < m_maxSounds);
    }
    return 0;
}
