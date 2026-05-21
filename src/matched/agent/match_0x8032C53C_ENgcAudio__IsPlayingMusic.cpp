// 0x8032C53C ENgcAudio::IsPlayingMusic(void) (92B)

extern int gv_audioEnabled;

class ENGCAudioStreamer {
public:
    int AnyIsActive();
};

extern ENGCAudioStreamer* gv_audioStreamer;

class ENgcAudio {
public:
    char _pad0[12];
    int m_paused;

    int IsPlayingMusic();
};

int ENgcAudio::IsPlayingMusic() {
    if (gv_audioEnabled == 0) return 0;
    int result = 0;
    if (gv_audioStreamer->AnyIsActive() != 0) {
        result = (m_paused != 0) ? 0 : 1;
    }
    return result;
}
