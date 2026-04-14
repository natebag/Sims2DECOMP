// 0x80119340 cSampleChannel::IsPlaying() (72B)

struct cXObject;

class cSampleChannel {
public:
    char _pad[4];
    cXObject *m_xob;
    int IsPlaying();
};

int cSampleChannel::IsPlaying() {
    cXObject *r11 = m_xob;
    if (r11 != 0) {
        int *vtbl = *(int **)((char *)r11 + 0);
        short adj = *(short *)((char *)vtbl + 0x28);
        int (*fn)(void *) = (int (*)(void *))*(void **)((char *)vtbl + 0x2C);
        return fn((char *)r11 + adj);
    }
    return 0;
}
