// 0x8012B4AC cXPersonImpl::IsMale (124B)

typedef void* (*Fn1)(void*);
typedef int* (*Fn2)(void*);

struct cXPerson_IMale {
    char pad_00[4];
    void* m_inner;
    int IsMale();
};

int cXPerson_IMale::IsMale() {
    char* inner = (char*)m_inner;
    char* vt = *(char**)(inner + 4);
    short adj = *(short*)(vt + 0x150);
    Fn1 fn = (Fn1)*(void**)(vt + 0x154);
    void* r1 = fn(inner + adj);
    if (r1 != 0) return *(int*)((char*)r1 + 0x84);
    char* inner2 = (char*)m_inner;
    char* vt2 = *(char**)(inner2 + 4);
    short adj2 = *(short*)(vt2 + 0x160);
    Fn2 fn2 = (Fn2)*(void**)(vt2 + 0x164);
    int* p = fn2(inner2 + adj2);
    return (*p == 0) ? 1 : 0;
}
