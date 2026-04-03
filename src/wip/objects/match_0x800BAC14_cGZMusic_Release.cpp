// NEEDS VERIFICATION - 0x800BAC14 (128 bytes)
// cGZMusic::Release(void)

class cGZMusic {
public:
    void* vtable;
    int refcount;
    void* data1;
    void* data2;
    void* data3;
    void* data4;
    
    void Release() {
        if (refcount == 1) {
            void** vt = (void**)vtable;
            int offset = *(int*)((char*)vt + 48);
            void (*fn1)(void*) = (void (*)(void*))*(void**)((char*)vt + 52);
            fn1((char*)this + offset);
        }
        
        if (this != 0) {
            void** vt = (void**)vtable;
            int offset2 = *(int*)((char*)vt + 152);
            void (*fn2)(void*) = (void (*)(void*))*(void**)((char*)vt + 156);
            fn2((char*)this + offset2);
        }
    }
};
