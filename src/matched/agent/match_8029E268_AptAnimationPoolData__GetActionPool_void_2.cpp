struct AptAnimationPoolData2 {
    char pad[0x98];
    void* m_actionPool;

    void* GetActionPool();
};

void* AptAnimationPoolData2::GetActionPool() {
    return m_actionPool;
}
