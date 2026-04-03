// VERIFIED MATCH - 0x801be134 (88 bytes)
// ObjFnTableQuickData::ObjFnTableQuickData(void)
// Initializes ObjFnTableQuickData with vtable, empty ID, and refcount

extern void* __vt__18ObjFnTableQuickData;

struct ObjectDataID {
    unsigned int namespaceID;
    unsigned short resourceID;
    ObjectDataID(unsigned int ns = -1, unsigned short res = 0);
};

class ObjFnTableQuickData {
public:
    void* vtable;
    ObjectDataID id;
    void* fnData;
    int refcount;
    
    ObjFnTableQuickData() {
        vtable = &__vt__18ObjFnTableQuickData;
        id = ObjectDataID(-1, 0);
        fnData = 0;
        refcount = 0;
    }
};

ObjFnTableQuickData::ObjFnTableQuickData(void) {
    vtable = &__vt__18ObjFnTableQuickData;
    id = ObjectDataID(-1, 0);
    fnData = 0;
    refcount = 0;
}
