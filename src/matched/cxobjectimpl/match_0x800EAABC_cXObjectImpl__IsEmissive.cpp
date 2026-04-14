// 0x800EAABC cXObjectImpl::IsEmissive (124B)

typedef int (*Fn)(void*);

struct cXObj_IE {
    char pad_00[4];
    void* m_inner;
    int IsEmissive();
};

int cXObj_IE::IsEmissive() {
    int result = 0;
    char* inner = (char*)m_inner;
    char* vt = *(char**)(inner + 4);
    short adj = *(short*)(vt + 0x418);
    Fn fn = (Fn)*(void**)(vt + 0x41C);
    if (fn(inner + adj) != 0) {
        char* inner2 = (char*)m_inner;
        char* vt2 = *(char**)(inner2 + 4);
        short adj2 = *(short*)(vt2 + 0x318);
        Fn fn2 = (Fn)*(void**)(vt2 + 0x31C);
        if (fn2(inner2 + adj2) != 8) {
            result = 1;
        }
    }
    return result;
}
