// 0x801192E8 cSampleChannel::NoteOff() (88B) — MI vcall, same pattern as FreeSnd

class ISound {
public:
    virtual ~ISound() = 0;
    virtual void filler1() = 0;
    virtual void Release() = 0;
};

class cSampleChannel {
public:
    char pad[4];
    ISound* m_4;
    int NoteOff();
};

int cSampleChannel::NoteOff() {
    ISound* s = m_4;
    if (s != 0) {
        s->Release();
        m_4 = 0;
    }
    return 1;
}
