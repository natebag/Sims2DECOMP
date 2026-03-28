/* AmbientScorePlayer::SoundAlreadyPlaying(ERAmbientSound *) at 0x800A8C28 (136B) */

struct ERAmbientSound;

struct AmbientSoundPlayer {
    int IsValid();
    ERAmbientSound *GetAmbientSound();
};

struct AmbientScorePlayer {
    char pad_00[0x0C];
    int m_soundPlayers;
    char pad_10[0x0C];
    int m_maxSounds;

    int SoundAlreadyPlaying(ERAmbientSound *snd);
};

int AmbientScorePlayer::SoundAlreadyPlaying(ERAmbientSound *snd)
{
    int i = 0;
    if (i < m_maxSounds) {
        int offset = 0;
        do {
            if (((AmbientSoundPlayer *)(m_soundPlayers + offset))->IsValid()) {
                if (((AmbientSoundPlayer *)(m_soundPlayers + offset))->GetAmbientSound() == snd) {
                    return 1;
                }
            }
            i++;
            offset += 0x30;
        } while (i < m_maxSounds);
    }
    return 0;
}
