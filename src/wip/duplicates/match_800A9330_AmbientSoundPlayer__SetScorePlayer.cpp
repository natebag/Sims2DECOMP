// 0x800A9330 (8 bytes)
class AmbientSoundPlayer {
public:
    void SetScorePlayer(int p);
};

void AmbientSoundPlayer::SetScorePlayer(int p) {
    *(int*)((char*)this + 0x0) = p;
}
