// 0x80336368 ENgcMovie::PlayerGetTotalFrame(void) (32B)

struct ENgcMoviePlayer {
    char _pad0[0x50];
    int m_totalFrame;
    char _pad1[0x4c];
    void* m_handle;
    char _pad2[0x12c];
};

extern ENgcMoviePlayer ActivePlayer;

namespace ENgcMovie {
int PlayerGetTotalFrame() {
    if (!ActivePlayer.m_handle) return 0;
    return ActivePlayer.m_totalFrame;
}
}
