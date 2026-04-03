// NEEDS VERIFICATION - 0x80135634 (128 bytes)
// iResFile::Release(Memory::HandleNode *)

struct HandleNode {
    int value;
    int refcount;
};

class iResFile {
public:
    void* vtable;
    void* pad1;
    void* pad2;
    void* resourceData;
    
    int GetError();
    
    void Release(HandleNode* node) {
        void** vt = (void**)vtable;
        int offset = *(int*)((char*)vt + 216);
        void (*fn)(void*) = (void (*)(void*))*(void**)((char*)vt + 220);
        fn((char*)this + offset);
        
        int err = GetError();
        if (err == 0) {
            if (node != 0) {
                if (node->value == 0) {
                    // Additional cleanup path
                }
            }
        }
    }
};
