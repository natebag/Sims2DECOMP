// 0x800C71F0 (80B) cXMTObjectImpl::IsDynamic(void)

struct cXMTObjectImpl {
    int IsDynamic();
};

int cXMTObjectImpl::IsDynamic() {
    void* p = *(void**)this;
    void* p2 = *(void**)((char*)p + 4);
    char* vt = *(char**)((char*)p2 + 4);
    short adj = *(short*)(vt + 0x1D0);
    int (*fn)(void*, int) = *(int(**)(void*, int))(vt + 0x1D4);
    int result = fn((char*)p2 + adj, 8);
    return result != 0;
}
