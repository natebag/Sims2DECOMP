// 0x800EA9BC (68B) cXObject::CAST_IMPL(void)

struct cXObject {
    void* CAST_IMPL();
};

void* cXObject::CAST_IMPL() {
    if (this != 0) {
        char* vt = *(char**)((char*)this + 4);
        short adj = *(short*)(vt + 0x520);
        void* (*fn)(void*) = *(void*(**)(void*))(vt + 0x524);
        return fn((char*)this + adj);
    }
    return 0;
}
