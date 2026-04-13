// 0x800EB688 cXObjectImpl::HasZeroExtent (60B)

typedef int (*DispatchFn)(void*);

struct cXObj_HZE {
    char pad_00[4];
    void* m_inner;

    int HasZeroExtent();
};

int cXObj_HZE::HasZeroExtent() {
    char* inner = (char*)m_inner;
    char* vt = *(char**)(inner + 4);
    short adj = *(short*)(vt + 0x398);
    DispatchFn fn = (DispatchFn)*(void**)(vt + 0x39C);
    int result = fn(inner + adj);
    return (result >> 2) & 1;
}
