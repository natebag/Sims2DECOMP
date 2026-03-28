// 0x800A876C (8 bytes)
class AmbientScorePlayer {
public:
    float GetTime();
};

float AmbientScorePlayer::GetTime() {
    return *(float*)((char*)this + 0x34);
}
