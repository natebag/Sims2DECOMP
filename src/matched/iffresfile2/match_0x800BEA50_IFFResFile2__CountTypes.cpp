// 0x800BEA50 IFFResFile2::CountTypes(void) (136B)

struct IFFResFile2 {
    char pad[12];
    int* m_vt;
    char pad2[312 - 16];
    void* m_f312;  // offset 312
    short CountTypes(void);
};

extern "C" void IFFRes_DoWithCode(IFFResFile2* self, int code);
extern "C" int IFFRes_CheckDone(IFFResFile2* self);
extern "C" int IFF_CountTypesImpl(void* p);

short IFFResFile2::CountTypes(void) {
    int* vt = m_vt;
    short adj = *(short*)((char*)vt + 96);
    int (*fn)(void*) = (int (*)(void*))*(void**)((char*)vt + 100);
    int rc = fn((char*)this + adj);

    if (rc == 0) {
        IFFRes_DoWithCode(this, -49);
    } else {
        IFFRes_DoWithCode(this, 0);
    }

    if (IFFRes_CheckDone(this) != 0) return 0;
    return IFF_CountTypesImpl(m_f312);
}
