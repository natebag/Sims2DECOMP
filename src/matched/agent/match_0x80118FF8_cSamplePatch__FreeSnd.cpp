// 0x80118FF8 cSamplePatch::FreeSnd() (88B) — MI vcall

class ISound {
public:
    virtual ~ISound() = 0;
    virtual void filler1() = 0;
    virtual void Release() = 0;
};

class cSamplePatch {
public:
    char pad[0x18];
    ISound* m_18;
    int FreeSnd();
};

int cSamplePatch::FreeSnd() {
    ISound* s = m_18;
    if (s != 0) {
        s->Release();
        m_18 = 0;
    }
    return 1;
}
