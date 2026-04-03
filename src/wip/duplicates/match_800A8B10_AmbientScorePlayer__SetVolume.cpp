// 0x800A8B10 (8 bytes)
class AmbientScorePlayer {
public:
    int SetVolume(int p);
};

int AmbientScorePlayer::SetVolume(int p) {
    *(int*)((char*)this + 0x14) = p; return 1;
}
