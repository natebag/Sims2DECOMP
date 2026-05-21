// 0x801321E0 cXPortalImpl::GetCustomWallStyleID() (68B) — multi-deref MI-vcall + tail short load

class cXPortalImpl {
public:
    void* m_0;
    short GetCustomWallStyleID();
};

short cXPortalImpl::GetCustomWallStyleID() {
    char* a = (char*)m_0;
    char* b = *(char**)a;
    char* c = *(char**)(b + 4);
    char* vt = *(char**)(c + 4);
    short adj = *(short*)(vt + 0x310);
    void* fn = *(void**)(vt + 0x314);
    char* obj = ((char* (*)(void*))fn)(c + adj);
    return *(short*)(obj + 0xA2);
}
