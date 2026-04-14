// 0x801475A8 StackElem::ReconStream(ReconBuffer *, int, BehaviorFinder *) (264B)

struct ReconBuffer {
    void Recon8(signed char* p, int count);
    void Recon16(short* p, int count);
    void ReconBool(bool* p, int count);
};

struct BehaviorFinder;

struct StackElem {
    char pad0[2];
    short m_2;
    short m_4;
    char m_6;
    char m_7;
    char m_8[8];
    char m_16[1];
    void ReconStream(ReconBuffer* buf, int version, BehaviorFinder* finder);
    short GetTreeID() const;
    void SetTreeID(short);
    short* GetParams();
    short* GetLocals();
};

extern "C" void ReconBuffer_OtherRecon(ReconBuffer*, void*, int);

void StackElem::ReconStream(ReconBuffer* buf, int version, BehaviorFinder* finder) {
    if (version > 25) {
        buf->Recon16(&m_4, 1);
    }
    short local = GetTreeID();
    buf->Recon16(&local, 1);
    SetTreeID(local);

    buf->Recon16(&m_2, 1);
    buf->Recon8((signed char*)&m_6, 1);
    buf->Recon8((signed char*)&m_7, 1);

    short* params = GetParams();
    buf->Recon16(params, (unsigned char)m_7);

    short* locals = GetLocals();
    buf->Recon16(locals, (unsigned char)m_6);

    ReconBuffer_OtherRecon(buf, m_8, 1);

    int* vt = *(int**)finder;
    short adj = *(short*)((char*)vt + 8);
    void (*fn)(void*, void*, ReconBuffer*, int) = (void (*)(void*, void*, ReconBuffer*, int))*(void**)((char*)vt + 12);
    fn((char*)finder + adj, m_16, buf, version);
}
