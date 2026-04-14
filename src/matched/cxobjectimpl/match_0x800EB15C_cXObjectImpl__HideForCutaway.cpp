// 0x800EB15C cXObjectImpl::HideForCutaway (116B)

struct EdithVariableSet {
    unsigned short* operator[](int index);
};

typedef void* (*Fn)(void*);

struct cXObj_HFC {
    char pad_00[4];
    void* m_inner;
    char pad_08[0x20];
    EdithVariableSet m_vars;
    int HideForCutaway();
};

int cXObj_HFC::HideForCutaway() {
    int result = 0;
    char* inner = (char*)m_inner;
    char* vt = *(char**)(inner + 4);
    short adj = *(short*)(vt + 0x310);
    Fn fn = (Fn)*(void**)(vt + 0x314);
    void* p = fn(inner + adj);
    short f5C = *(short*)((char*)p + 0x5C);
    if (f5C != 0) {
        result = 1;
    } else {
        unsigned short v = *m_vars[8];
        if (v & 0x400) {
            result = 1;
        }
    }
    return result;
}
