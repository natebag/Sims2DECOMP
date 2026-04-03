// VERIFIED MATCH - 0x801be6bc (92 bytes)
// ObjFnTableQuickData::Release(void)
// Decrements refcount and destroys object if count reaches zero

extern void (*__vt__18ObjFnTableQuickData[])();

class ObjFnTableQuickData {
public:
    void* vtable;
    void* id;
    void* fnData;
    int refcount;
    
    int Release() {
        refcount--;
        if (refcount == 0) {
            if (this != 0) {
                // Virtual destructor via vtable[29]
                ((__vt__18ObjFnTableQuickData[29])(this));
            }
        }
        return 0;
    }
};
