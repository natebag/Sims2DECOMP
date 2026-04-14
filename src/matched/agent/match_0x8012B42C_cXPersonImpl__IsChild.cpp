// 0x8012B42C cXPersonImpl::IsChild(void) (128B)

struct cXPersonImpl {
    char pad[4];
    void* m_obj;  // offset 4
    int IsChild(void);
};

int cXPersonImpl::IsChild(void) {
    void* o = m_obj;
    int* v = *(int**)((char*)o + 4);
    short a1 = *(short*)((char*)v + 336);
    int (*fn1)(void*) = (int (*)(void*))*(void**)((char*)v + 340);
    if (fn1((char*)o + a1) != 0) return 0;

    void* o2 = m_obj;
    int* v2 = *(int**)((char*)o2 + 4);
    short a2 = *(short*)((char*)v2 + 352);
    void* (*fn2)(void*) = (void* (*)(void*))*(void**)((char*)v2 + 356);
    int t = *(int*)((char*)fn2((char*)o2 + a2) + 4);
    return t == 1;
}
