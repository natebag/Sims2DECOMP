// 0x8032C5D4 ENgcAudio::AudioAllocVoice(void) (64B)

struct EVoice {
    char _pad00[8];
    int field_08;
    char _pad0C[20];
    void reset();
};

class ENgcAudio {
public:
    EVoice* AudioAllocVoice();
};

EVoice* ENgcAudio::AudioAllocVoice() {
    EVoice* voice = new EVoice;
    voice->field_08 = -1;
    voice->reset();
    return voice;
}
