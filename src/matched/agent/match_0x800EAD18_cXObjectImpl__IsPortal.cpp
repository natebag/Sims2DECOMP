// 0x800EAD18 cXObjectImpl::IsPortal(void) (128B)

struct cXObjectImpl {
    char pad[4];
    void* m_f4;
    int IsPortal(void);
};

extern "C" int CX_SomeCall(void* p, int x);  // 0x800f2ba4

int cXObjectImpl::IsPortal(void) {
    int result = 0;
    void* o = m_f4;
    int* vt = *(int**)((char*)o + 4);
    short a1 = *(short*)((char*)vt + 792);
    int (*fn1)(void*) = (int (*)(void*))*(void**)((char*)vt + 796);
    if (fn1((char*)o + a1) == 8) {
        int r;
        if (this != 0) {
            r = CX_SomeCall(*(void**)m_f4, 6);
        } else {
            r = 0;
        }
        if (r != 0) result = 1;
    }
    return result;
}
