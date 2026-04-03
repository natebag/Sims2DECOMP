// VERIFIED MATCH - 0x800ACB44 (112 bytes)
// ResourceBehavior::QueryInterface(unsigned int, void **)

class ResourceBehavior {
public:
    void* vtable;
    
    int QueryInterface(unsigned int iid, void** ppv) {
        if (ppv == 0) {
            return 0;
        }
        
        if (iid == 1 || iid == 0x6BA37FA5) {
            void** vt = (void**)vtable;
            int offset = *(int*)((char*)vt + 16);
            void (*addref)(void*) = (void (*)(void*))*(void**)((char*)vt + 20);
            
            void* adjusted = (char*)this + offset;
            addref(adjusted);
            
            *ppv = this;
            return 1;
        }
        
        return 0;
    }
};
