/* AmbientSoundPlayer::GetAmbientSound(void) at 0x800AA9B4 (8B) */

struct ERAmbientSound;

struct AmbientSoundPlayer {
    void* m_scorePlayer;
    ERAmbientSound* m_ambientSound;

    ERAmbientSound* GetAmbientSound(void);
};

ERAmbientSound* AmbientSoundPlayer::GetAmbientSound(void) {
    return m_ambientSound;
}
