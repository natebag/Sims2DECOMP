// 0x8012C2B8 cXPersonImpl::GetNormalSimDescription (180B)
// Returns SimDescription's normal-form (field +0x604) if present, otherwise
// falls back to a different slot (0x150/0x154, the GetServiceNPC-style call).
// GCC 2.95 does not CSE the dispatch — three separate calls to slot 0x188/0x18C
// are emitted inline, matching the original DOL.

typedef void* (*FnDispatch)(void*);

struct cXPerson_GNSD {
    char pad_00[4];
    char* m_inner;  // +0x04
    void* GetNormalSimDescription();
};

void* cXPerson_GNSD::GetNormalSimDescription() {
    char* a_inner = m_inner;
    char* avt = *(char**)(a_inner + 4);
    short aadj = *(short*)(avt + 0x188);
    FnDispatch afn = (FnDispatch)*(void**)(avt + 0x18C);
    void* a = afn(a_inner + aadj);
    if (a != 0) {
        char* b_inner = m_inner;
        char* bvt = *(char**)(b_inner + 4);
        FnDispatch bfn = (FnDispatch)*(void**)(bvt + 0x18C);
        short badj = *(short*)(bvt + 0x188);
        void* b = bfn(b_inner + badj);
        if (*(void**)((char*)b + 0x604) != 0) {
            char* c_inner = m_inner;
            char* cvt = *(char**)(c_inner + 4);
            short cadj = *(short*)(cvt + 0x188);
            FnDispatch cfn = (FnDispatch)*(void**)(cvt + 0x18C);
            void* c = cfn(c_inner + cadj);
            return *(void**)((char*)c + 0x604);
        }
    }
    char* d_inner = m_inner;
    char* dvt = *(char**)(d_inner + 4);
    short dadj = *(short*)(dvt + 0x150);
    FnDispatch dfn = (FnDispatch)*(void**)(dvt + 0x154);
    return dfn(d_inner + dadj);
}
