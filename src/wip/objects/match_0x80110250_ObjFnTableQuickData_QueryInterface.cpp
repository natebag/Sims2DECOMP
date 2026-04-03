// VERIFIED MATCH - 0x80110250 (112 bytes)
// ObjFnTableQuickData::QueryInterface(unsigned int, void **)

class ObjFnTableQuickData {
public:
    void* vtable;
    
    int QueryInterface(unsigned int iid, void** ppv) {
        if (!ppv) return 0;
        if (iid == 1 || iid == 0x6BA37FA5) {
            void** vt = (void**)vtable;
            int offset = *(int*)((char*)vt + 16);
            void (*addref)(void*) = (void (*)(void*))*(void**)((char*)vt + 20);
            addref((char*)this + offset);
            *ppv = this;
            return 1;
        }
        return 0;
    }
};
