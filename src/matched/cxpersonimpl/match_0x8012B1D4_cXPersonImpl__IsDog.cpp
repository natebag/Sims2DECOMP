// 0x8012B1D4 cXPersonImpl::IsDog (128B)

typedef int (*Fn1)(void*);
typedef void* (*Fn2)(void*);

struct cXPerson_IDog {
    char pad_00[4];
    void* m_inner;
    int IsDog();
};

int cXPerson_IDog::IsDog() {
    char* inner = (char*)m_inner;
    char* vt = *(char**)(inner + 4);
    short adj = *(short*)(vt + 0x150);
    Fn1 fn = (Fn1)*(void**)(vt + 0x154);
    int r1 = fn(inner + adj);
    if (r1 != 0) return 0;
    char* inner2 = (char*)m_inner;
    char* vt2 = *(char**)(inner2 + 4);
    short adj2 = *(short*)(vt2 + 0x160);
    Fn2 fn2 = (Fn2)*(void**)(vt2 + 0x164);
    void* p = fn2(inner2 + adj2);
    int v = *(int*)((char*)p + 4);
    return (v == 2) ? 1 : 0;
}
