// 0x8036A860 (100B) REffectsEmitter::Deallocate(void)

extern "C" void* MainHeap();                          // 0x802CFF00
extern "C" void helper_EAHeap_Free(void* heap, void* ptr);  // 0x802D0D78 EAHeap::Free

class REffectsEmitter {
public:
    void Deallocate();
};

void REffectsEmitter::Deallocate() {
    char* vt = *(char**)this;
    short adj = *(short*)(vt + 104);
    void* fn = *(void**)(vt + 108);
    char* adj_this = (char*)this + adj;
    ((void (*)(void*))fn)(adj_this);

    void* m24 = *(void**)((char*)this + 24);
    if (m24 != 0) {
        void* heap = MainHeap();
        helper_EAHeap_Free(heap, *(void**)((char*)this + 24));
        *(int*)((char*)this + 20) = 0;
        *(int*)((char*)this + 24) = 0;
    }
}
