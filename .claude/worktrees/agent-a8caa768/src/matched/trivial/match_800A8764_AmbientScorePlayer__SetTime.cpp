// 0x800A8764 (8 bytes)
class AmbientScorePlayer {
public:
    void SetTime(float p);
};

void AmbientScorePlayer::SetTime(float p) {
    *(float*)((char*)this + 0x34) = p;
}
