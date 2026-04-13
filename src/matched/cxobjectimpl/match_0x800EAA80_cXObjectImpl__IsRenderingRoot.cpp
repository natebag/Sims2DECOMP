// 0x800EAA80 cXObjectImpl::IsRenderingRoot (60B)

typedef int (*DispatchFn)(void*);

struct cXObj_IRR {
    char pad_00[4];
    void* m_inner;

    int IsRenderingRoot();
};

int cXObj_IRR::IsRenderingRoot() {
    char* inner = (char*)m_inner;
    char* vt = *(char**)(inner + 4);
    short adj = *(short*)(vt + 0x2D8);
    DispatchFn fn = (DispatchFn)*(void**)(vt + 0x2DC);
    int result = fn(inner + adj);
    return result ^ 1;
}
