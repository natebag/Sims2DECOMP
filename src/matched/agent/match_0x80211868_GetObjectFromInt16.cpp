// FLAGS: -fno-schedule-insns2 -msdata=eabi -G 8
// 0x80211868 InteractorModule::GetObjectFromInt16 (88b)
extern void* g_objManager;

struct SubMgr {
    char pad[0x90];
    short offset;
    char pad2[2];
    void* funcPtr;
};

class TreeSim {
public:
    void* _dyncastimpl(int scid);
};

class InteractorModule {
public:
    static void* GetObjectFromInt16(short id);
};

void* InteractorModule::GetObjectFromInt16(short id) {
    void* mgr = g_objManager;
    SubMgr* sub = *(SubMgr**)mgr;
    short off = sub->offset;
    void* func = sub->funcPtr;
    void* adjusted = (char*)mgr + off;
    void* result = ((void* (*)(void*, short))func)(adjusted, id);
    if (result == 0) return 0;
    TreeSim* obj = *(TreeSim**)result;
    return obj->_dyncastimpl(10);
}
