struct AptAnimationPoolData {
    char pad[0x98];
    void* m_actionPool;

    void* GetActionPool();
};

void* AptAnimationPoolData::GetActionPool() {
    return m_actionPool;
}
