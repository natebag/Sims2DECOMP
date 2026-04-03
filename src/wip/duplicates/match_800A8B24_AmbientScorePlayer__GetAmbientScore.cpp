// 0x800A8B24 (8 bytes)
class AmbientScorePlayer {
public:
    int GetAmbientScore();
};

int AmbientScorePlayer::GetAmbientScore() {
    return *(int*)((char*)this + 0x8);
}
