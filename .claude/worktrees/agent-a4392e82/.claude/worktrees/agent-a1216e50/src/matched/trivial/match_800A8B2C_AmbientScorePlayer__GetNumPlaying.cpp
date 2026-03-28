// 0x800A8B2C (8 bytes)
class AmbientScorePlayer {
public:
    int GetNumPlaying();
};

int AmbientScorePlayer::GetNumPlaying() {
    return *(int*)((char*)this + 0x10);
}
