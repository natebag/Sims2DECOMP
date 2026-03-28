// 0x800A8B34 (8 bytes)
class AmbientScorePlayer {
public:
    int GetListenerInfos();
};

int AmbientScorePlayer::GetListenerInfos() {
    return (int)((char*)this + 0x20);
}
