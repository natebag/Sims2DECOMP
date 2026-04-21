// 0x800C7CD0 (68B) cXMTObject::CAST_IMPL(void)

struct cXMTObject {
    void* CAST_IMPL();
};

void* cXMTObject::CAST_IMPL() {
    if (this != 0) {
        char* vt = *(char**)((char*)this + 4);
        short adj = *(short*)(vt + 0x58);
        void* (*fn)(void*) = *(void*(**)(void*))(vt + 0x5C);
        return fn((char*)this + adj);
    }
    return 0;
}
