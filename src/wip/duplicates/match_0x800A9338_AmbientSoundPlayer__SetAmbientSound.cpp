/* AmbientSoundPlayer::SetAmbientSound(ERAmbientSound *) at 0x800A9338 (8B) */

struct ERAmbientSound;

struct AmbientSoundPlayer {
    void* m_scorePlayer;
    ERAmbientSound* m_ambientSound;

    void SetAmbientSound(ERAmbientSound* s);
};

void AmbientSoundPlayer::SetAmbientSound(ERAmbientSound* s) {
    m_ambientSound = s;
}
