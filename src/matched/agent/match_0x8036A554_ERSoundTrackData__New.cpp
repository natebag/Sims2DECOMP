// 0x8036A554 ERSoundTrackData::New (48b)
typedef unsigned int uint;

struct EAHeap {
    void *Malloc(uint size, int flags);
};
EAHeap *MainHeap(void);

struct ERSoundTrackData {
    char _pad[36];
    ERSoundTrackData(void);
};

inline void *operator new(uint, void *p) { return p; }

ERSoundTrackData *ERSoundTrackData__New(void) {
    void *mem = MainHeap()->Malloc(36, 0);
    ERSoundTrackData *p = new(mem) ERSoundTrackData;
    return p;
}
