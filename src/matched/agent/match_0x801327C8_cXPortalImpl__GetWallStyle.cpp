// 0x801327C8 cXPortalImpl::GetWallStyle() (68B) — twin of GetCustomWallStyleID with short offset 0x5C

class cXPortalImpl {
public:
    void* m_0;
    short GetWallStyle();
};

short cXPortalImpl::GetWallStyle() {
    char* a = (char*)m_0;
    char* b = *(char**)a;
    char* c = *(char**)(b + 4);
    char* vt = *(char**)(c + 4);
    short adj = *(short*)(vt + 0x310);
    void* fn = *(void**)(vt + 0x314);
    char* obj = ((char* (*)(void*))fn)(c + adj);
    return *(short*)(obj + 0x5C);
}
