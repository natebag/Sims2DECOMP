struct FastAllocPool_GA {
    char pad[0x10];
    int m_alignment;
    int GetAlignment() const;
};

int FastAllocPool_GA::GetAlignment() const {
    return m_alignment;
}
