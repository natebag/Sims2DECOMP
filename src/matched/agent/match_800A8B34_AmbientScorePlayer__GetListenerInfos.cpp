// 0x800A8B34 (8 bytes)
class AmbientScorePlayer {
public:
    char pad[32];

    void *GetListenerInfos(void);
};

void *AmbientScorePlayer::GetListenerInfos(void) {
    return (void *)((char *)this + 32);
}
