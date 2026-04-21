// 0x800120EC AwarenessManager::~AwarenessManager (84B)
// dtor: vtable@+68 + bl MemoryAwarenessClearAction + bl StopPassiveInfluenceAnimation + delete check.

extern int VT_AwarenessManager[];

struct AwarenessManager {
    char pad[68];
    int* m_vtable;
    void MemoryAwarenessClearAction();
    void StopPassiveInfluenceAnimation();
    ~AwarenessManager();
};

AwarenessManager::~AwarenessManager() {
    m_vtable = VT_AwarenessManager;
    MemoryAwarenessClearAction();
    StopPassiveInfluenceAnimation();
}
