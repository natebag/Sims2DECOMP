// 0x802B46D0 (160B) AptValue::AptValue(AptVirtualFunctionTable_Indices [, CIH_ONLY tag])
//
// Base value ctor: installs the AptValue vtable @0x08, runs the field setters
// (vtbl index, refcount 0, defined, gc mark/root cleared, max-refcount-hit,
// release-at-end), clears flag bit 0x04000000, and assigns a unique id from a
// global counter (m_field04 = g_counter++). Clean structural C++, no surgery.

extern unsigned int g_aptValueIdCounter;   // r13-27020 (SDA)

struct AptValue {
    unsigned int m_flags;     // 0x00
    unsigned int m_field04;   // 0x04
    virtual void dummy();     // vptr @ 0x08

    void setVtblIndex(int idx);
    void setRefCount(unsigned int n);
    void setIsDefined(bool b);
    void setGCMark(bool b);
    void setGCRoot(unsigned int n);
    void SetMaxRefCountHit(bool b);
    void ClearReleaseAtEnd();

    AptValue(int vftIdx);
};

AptValue::AptValue(int vftIdx) {
    setVtblIndex(vftIdx);
    setRefCount(0);
    setIsDefined(true);
    setGCMark(false);
    setGCRoot(0);
    m_flags &= ~0x04000000;
    m_field04 = g_aptValueIdCounter++;
    SetMaxRefCountHit(false);
    ClearReleaseAtEnd();
}
