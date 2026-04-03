// VERIFIED MATCH - 0x801be18c (92 bytes)
// ObjFnTableQuickData::~ObjFnTableQuickData(void)
// Deallocates fnData and optionally deletes this object

extern void __builtin_delete(void* ptr, int flags);

class ObjFnTableQuickData {
public:
    void* vtable;
    void* id;
    void* fnData;
    int refcount;
    
    ~ObjFnTableQuickData() {
        if (fnData) {
            __builtin_delete(fnData, 0);
        }
        if (refcount & 1) {
            __builtin_delete(this, 0);
        }
    }
};
