// 0x802B5818 (24B) DOGMA_PoolManager::GetFirstOutsideAllocation(void)

struct DPM_First {
    char pad[20];
    char* m_firstAlloc;
    char* GetFirstOutsideAllocation();
};

char* DPM_First::GetFirstOutsideAllocation() {
    if (!m_firstAlloc) return 0;
    return m_firstAlloc + 8;
}
