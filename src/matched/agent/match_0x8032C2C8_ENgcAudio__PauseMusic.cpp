// 0x8032C2C8 ENgcAudio::PauseMusic(void) (112B)

extern int gv_audioEnabled;

class ENGCAudioStreamer {
public:
    void Pause(unsigned int id);
};

extern ENGCAudioStreamer* gv_audioStreamer;

struct VoiceSlot {
    int id1;
    char _pad[60];
    int id2;
};

extern VoiceSlot g_voiceArray[64];

class ENgcAudio {
public:
    char _pad0[12];
    int m_paused;

    void PauseMusic();
};

void ENgcAudio::PauseMusic() {
    if (gv_audioEnabled == 0) return;
    m_paused = 1;
    VoiceSlot* p = g_voiceArray;
    VoiceSlot* end = (VoiceSlot*)((char*)p + 4284);
    do {
        if (p->id1 != -1) {
            if (p->id2 != -1) {
                gv_audioStreamer->Pause(p->id2);
            }
        }
        p = (VoiceSlot*)((char*)p + 68);
    } while (p <= end);
}
