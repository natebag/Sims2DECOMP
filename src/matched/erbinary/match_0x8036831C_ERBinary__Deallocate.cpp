// 0x8036831C (68B) ERBinary::Deallocate(void)
// Technique: volatile-store on trailing m_20 to force descending-offset store order

extern "C" void helper_0x803276AC(void* mgr, void* ptr);
extern char EResourceManager_singleton[];

class ERBinary {
public:
    void Deallocate();
};

void ERBinary::Deallocate() {
    helper_0x803276AC(EResourceManager_singleton, *(void**)((char*)this + 20));
    *(volatile int*)((char*)this + 24) = 0;
    *(volatile int*)((char*)this + 20) = 0;
}
