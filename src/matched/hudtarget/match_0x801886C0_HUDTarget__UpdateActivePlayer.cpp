// 0x801886C0 (100B) HUDTarget::UpdateActivePlayer(int, bool)

struct GlobalRefStruct_0x80475DCC {
    char pad[188];
    void* m_arr[8];
};
extern GlobalRefStruct_0x80475DCC g_baseStruct_0x80475DCC;

class cXPersonImpl;
extern "C" void AttachToHUD__12cXPersonImplFb(cXPersonImpl*, bool);

class HUDTarget {
public:
    void UpdateActivePlayer(int idx, bool flag);
};

void HUDTarget::UpdateActivePlayer(int idx, bool flag) {
    void* p = g_baseStruct_0x80475DCC.m_arr[idx];
    if (p == 0) return;
    char* obj = (char*)p;
    char* vt = *(char**)(obj + 4);
    short adj = *(short*)(vt + 776);
    void* fn = *(void**)(vt + 780);
    cXPersonImpl* p2 = ((cXPersonImpl* (*)(void*))fn)(obj + adj);
    AttachToHUD__12cXPersonImplFb(p2, flag);
}
