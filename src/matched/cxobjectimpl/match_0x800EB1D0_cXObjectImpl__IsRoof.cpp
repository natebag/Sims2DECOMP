// 0x800EB1D0 cXObjectImpl::IsRoof (72B)

typedef void* (*Fn)(void*);

struct cXObj_IRoof {
    char pad_00[4];
    void* m_inner;
    int IsRoof();
};

int cXObj_IRoof::IsRoof() {
    char* inner = (char*)m_inner;
    char* vt = *(char**)(inner + 4);
    short adj = *(short*)(vt + 0x310);
    Fn fn = (Fn)*(void**)(vt + 0x314);
    void* p = fn(inner + adj);
    short val = *(short*)((char*)p + 0x12);
    return (val == 0xE) ? 1 : 0;
}
