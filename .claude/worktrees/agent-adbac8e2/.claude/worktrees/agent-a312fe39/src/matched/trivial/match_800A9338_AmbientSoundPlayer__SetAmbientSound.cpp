// 0x800A9338 (8 bytes)
class AmbientSoundPlayer {
public:
    void SetAmbientSound(int p);
};

void AmbientSoundPlayer::SetAmbientSound(int p) {
    *(int*)((char*)this + 0x4) = p;
}
