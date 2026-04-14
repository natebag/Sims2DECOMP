// 0x80119110 cSampleChannel::SetVolume(int) (72B)

struct cXObject;

class cSampleChannel {
public:
    char _pad[4];
    cXObject *m_xob;
    int SetVolume(int vol);
};

int cSampleChannel::SetVolume(int vol) {
    cXObject *r11 = m_xob;
    if (r11 != 0) {
        int *vtbl = *(int **)((char *)r11 + 0);
        short adj = *(short *)((char *)vtbl + 0x60);
        int (*fn)(void *, int) = (int (*)(void *, int))*(void **)((char *)vtbl + 0x64);
        return fn((char *)r11 + adj, vol);
    }
    return 0;
}
