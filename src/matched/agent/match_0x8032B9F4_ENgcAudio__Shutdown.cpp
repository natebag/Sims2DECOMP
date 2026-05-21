// 0x8032B9F4 ENgcAudio::Shutdown(void) (104B)

extern int gv_audioEnabled;
extern int gv_audioInited;

class ENGCAudioStreamer {
public:
    ~ENGCAudioStreamer();
};

extern ENGCAudioStreamer* gv_audioStreamer;

extern "C" {
    void AXRegisterCallback(void*);
    void MIXQuit();
    void AXQuit();
}

class ENgcAudio {
public:
    void Shutdown();
};

void ENgcAudio::Shutdown() {
    if (gv_audioEnabled == 0) return;
    if (gv_audioInited == 0) return;
    if (gv_audioStreamer != 0) {
        delete gv_audioStreamer;
        gv_audioStreamer = 0;
    }
    AXRegisterCallback(0);
    MIXQuit();
    AXQuit();
    gv_audioInited = 0;
}
