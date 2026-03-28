// 0x800AA9B4 (8 bytes)
class AmbientSoundPlayer {
public:
    int GetAmbientSound();
};

int AmbientSoundPlayer::GetAmbientSound() {
    return *(int*)((char*)this + 0x4);
}
