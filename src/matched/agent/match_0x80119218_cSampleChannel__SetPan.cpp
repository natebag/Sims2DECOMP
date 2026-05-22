// 0x80119218 cSampleChannel::SetPan(int) (96B)

class ISound {
public:
    virtual ~ISound() = 0;
    virtual void f1() = 0;
    virtual void f2() = 0;
    virtual void f3() = 0;
    virtual void f4() = 0;
    virtual void f5() = 0;
    virtual void Pause() = 0;
    virtual void Unpause() = 0;
    virtual void f9() = 0;
    virtual void f10() = 0;
    virtual void f11() = 0;
    virtual void f12() = 0;
    virtual void f13() = 0;
    virtual void f14() = 0;
    virtual void SetPan(int p) = 0;
};

class cSamplePatch;

class cSampleChannel {
public:
    cSamplePatch* m_0;
    ISound* m_4;
    void SetPatch(cSamplePatch* p);
    void SetPan(int pan);
};

void cSampleChannel::SetPan(int pan) {
    if (m_4 == 0) {
        SetPatch(m_0);
    }
    m_4->SetPan(pan);
}
