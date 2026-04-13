// FLAGS: -fno-schedule-insns2 -msdata=eabi -G 8
// 0x80211868 InteractorModule::GetObjectFromInt16 (88b)

extern char g_objManager[4];

class TreeSim {
public:
    void* _dyncastimpl(int scid);
};

class InteractorModule {
public:
    static void* GetObjectFromInt16(short id);
};

void* InteractorModule::GetObjectFromInt16(short id) {
    void* mgr = *(void**)g_objManager;
    void* vtable = *(void**)mgr;
    short off = *(short*)((char*)vtable + 0x90);
    void* func = *(void**)((char*)vtable + 0x94);
    void* adjusted = (char*)mgr + off;
    void* result = ((void* (*)(void*, short))func)(adjusted, id);
    if (result == 0) return 0;
    TreeSim* obj = *(TreeSim**)result;
    return obj->_dyncastimpl(10);
}
