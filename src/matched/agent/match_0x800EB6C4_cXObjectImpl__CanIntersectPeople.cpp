// 0x800EB6C4 cXObjectImpl::CanIntersectPeople(void) (148B)

struct cXObjectImpl {
    char pad[4];
    void* m_f4;
    int CanIntersectPeople(void);
};

int cXObjectImpl::CanIntersectPeople(void) {
    void* o = m_f4;
    int* vt = *(int**)((char*)o + 4);
    short a1 = *(short*)((char*)vt + 1136);
    int (*fn1)(void*) = (int (*)(void*))*(void**)((char*)vt + 1140);
    int r1 = fn1((char*)o + a1);

    if (r1 != 0) {
        void* o2 = m_f4;
        int* vt2 = *(int**)((char*)o2 + 4);
        short a2 = *(short*)((char*)vt2 + 920);
        int (*fn2)(void*) = (int (*)(void*))*(void**)((char*)vt2 + 924);
        int r2 = fn2((char*)o2 + a2);
        return ((r2 ^ 2) >> 1) & 1;
    }
    void* o2 = m_f4;
    int* vt2 = *(int**)((char*)o2 + 4);
    short a2 = *(short*)((char*)vt2 + 920);
    int (*fn2)(void*) = (int (*)(void*))*(void**)((char*)vt2 + 924);
    int r2 = fn2((char*)o2 + a2);
    return (r2 >> 4) & 1;
}
