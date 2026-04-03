// NEEDS VERIFICATION - 0x800BA098 (188 bytes)
// cGZSnd::Release(void)

class cGZSnd {
public:
    void* vtable;
    int refcount;
    void* data0;
    void* data1;
    void* data2;
    void* data3;
    void* data4;
    void* data5;
    void* data6;
    void* callbackData;
    
    void Release() {
        if (refcount != 1) {
            return;
        }
        
        if (callbackData != 0) {
            int scratch = 0;
            void** vt = (void**)vtable;
            int offset = *(int*)((char*)vt + 172);
            void (*fn)(void*, void*) = (void (*)(void*, void*))*(void**)((char*)vt + 176);
            fn((char*)this + offset, &scratch);
        }
        
        // Cleanup continues
    }
};
