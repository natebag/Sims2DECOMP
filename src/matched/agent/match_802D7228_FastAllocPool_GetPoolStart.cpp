struct FastAllocPool_GPS {
    void* m_poolStart;
    void* GetPoolStart() const;
};

void* FastAllocPool_GPS::GetPoolStart() const {
    return m_poolStart;
}
