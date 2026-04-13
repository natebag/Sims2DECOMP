// 0x80211868 InteractorModule::GetObjectFromInt16 (88b)
// FLAGS: -fno-schedule-insns2

// SDA global - accessed via r13 at -21484
extern char g_objManager[4];

struct ObjManager {
    void* vtable;
    char pad[0x8C];    // to offset 0x90
    short offset;      // at offset 0x90
    char pad2[2];      // padding
    void* funcPtr;     // at offset 0x94
};

class TreeSim {
public:
    void* _dyncastimpl(int scid);
};

void* InteractorModule_GetObjectFromInt16(short id) {
    ObjManager* mgr = *(ObjManager**)g_objManager;
    short offset = *(short*)((char*)mgr + 0x90);
    void* func = *(void**)((char*)mgr + 0x94);
    
    void* result = ((void* (*)(short))func)(id);
    
    if (result == 0) {
        return 0;
    }
    
    TreeSim* obj = *(TreeSim**)result;
    return obj->_dyncastimpl(10);
}

extern "C" void _ZN15InteractorModule17GetObjectFromInt16Es(void* out, short id) {
    *(void**)out = InteractorModule_GetObjectFromInt16(id);
}
