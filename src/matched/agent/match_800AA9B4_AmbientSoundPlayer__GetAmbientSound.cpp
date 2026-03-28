// 0x800AA9B4 (8 bytes)
class ERAmbientSound;

class AmbientSoundPlayer {
public:
    void *pad;
    ERAmbientSound *m_ambientSound;

    ERAmbientSound *GetAmbientSound(void);
};

ERAmbientSound *AmbientSoundPlayer::GetAmbientSound(void) {
    return m_ambientSound;
}
