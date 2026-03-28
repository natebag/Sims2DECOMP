/* AmbientScorePlayer::RemoveFinishedSounds(void) at 0x800A9198 (216B) */

struct ERAmbientSound {
    char pad_00[0x19];
    char m_looping;
};

struct AmbientSoundPlayer {
    int IsValid();
    int IsFinished();
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

    int SoundRangeCoversCurTime(ERAmbientSound *snd);
    void RemoveFinishedSounds();
};

void AmbientScorePlayer::RemoveFinishedSounds()
{
    int i = 0;
    if (i < m_maxSounds) {
        int offset = 0;
        do {
            if (((AmbientSoundPlayer *)(m_soundPlayers + offset))->IsValid()) {
                if (!((AmbientSoundPlayer *)(m_soundPlayers + offset))->IsFinished()) {
                    if (((AmbientSoundPlayer *)(m_soundPlayers + offset))->GetAmbientSound()->m_looping != 0) {
                        if (!SoundRangeCoversCurTime(((AmbientSoundPlayer *)(m_soundPlayers + offset))->GetAmbientSound())) {
                            ((AmbientSoundPlayer *)(m_soundPlayers + offset))->Stop();
                            ((AmbientSoundPlayer *)(m_soundPlayers + offset))->SetAmbientSound(0);
                            m_numPlaying--;
                        }
                    }
                } else {
                    ((AmbientSoundPlayer *)(m_soundPlayers + offset))->Stop();
                    ((AmbientSoundPlayer *)(m_soundPlayers + offset))->SetAmbientSound(0);
                    m_numPlaying--;
                }
            }
            i++;
            offset += 0x30;
        } while (i < m_maxSounds);
    }
}
