// 0x800BAC14 (128B) cGZMusic::Release(void)
// Refcounted release with two vtable-offset virtual calls.
// Vtable entries at offsets 48/52 (slot 6) and 152/156 (slot 19).

struct cGZMusic {
    void* vtable;
    int refcount;
    char pad[0x18];
    
    int Release();
};

int cGZMusic::Release() {
    switch (refcount) {
        case 1: {
            // Virtual call at vtable slot 6 (offset 48/52), no args
            char* vt = *(char**)this;
            short adj = *(short*)(vt + 48);
            void (*func)(char*) = *(void (**)(char*))(vt + 52);
            func((char*)this + adj);
            
            // First call may delete this, so re-check
            if (this != 0) {
                char* vt2 = *(char**)this;
                short adj2 = *(short*)(vt2 + 152);
                void (*func2)(char*, int) = *(void (**)(char*, int))(vt2 + 156);
                func2((char*)this + adj2, 3);
            }
            return 0;
        }
        default:
            return --refcount;
    }
}
