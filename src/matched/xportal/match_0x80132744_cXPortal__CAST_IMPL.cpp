// 0x80132744 cXPortal::CAST_IMPL() (68B) — Tech #47 MI-vcall, null-guard, vtable+4

class cXPortal {
public:
    cXPortal* CAST_IMPL();
};

cXPortal* cXPortal::CAST_IMPL() {
    if (this != 0) {
        char* p = (char*)this;
        char* vt = *(char**)(p + 4);
        short adj = *(short*)(vt + 32);
        void* fn = *(void**)(vt + 36);
        return ((cXPortal*(*)(void*))fn)(p + adj);
    }
    return 0;
}
