// 0x800A9338 (8 bytes)
class ERAmbientSound;

class AmbientSoundPlayer {
public:
    void *pad;
    ERAmbientSound *m_ambientSound;

    void SetAmbientSound(ERAmbientSound *s);
};

void AmbientSoundPlayer::SetAmbientSound(ERAmbientSound *s) {
    m_ambientSound = s;
}
