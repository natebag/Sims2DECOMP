// 0x800C7D88 (72B) cXMTObjectImpl::CAST_IMPL(void)

struct cXMTObjectImpl {
    void* CAST_IMPL();
};

void* cXMTObjectImpl::CAST_IMPL() {
    if (this != 0) {
        void* p = *(void**)((char*)this + 4);
        char* vt = *(char**)((char*)p + 4);
        short adj = *(short*)(vt + 0x58);
        void* (*fn)(void*) = *(void*(**)(void*))(vt + 0x5C);
        return fn((char*)p + adj);
    }
    return 0;
}
