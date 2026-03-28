// 0x800A8B1C (8 bytes)
class AmbientScorePlayer {
public:
    int GetVolume();
};

int AmbientScorePlayer::GetVolume() {
    return *(int*)((char*)this + 0x14);
}
