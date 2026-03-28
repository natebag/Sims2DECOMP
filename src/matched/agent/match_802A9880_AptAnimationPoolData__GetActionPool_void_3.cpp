struct AptAnimationPoolData3 {
    char pad[0x98];
    void* m_actionPool;

    void* GetActionPool();
};

void* AptAnimationPoolData3::GetActionPool() {
    return m_actionPool;
}
