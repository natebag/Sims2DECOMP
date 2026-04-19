// 0x8015E900 (44B) TreeTableQuickData::CountEntries(void) const

struct Pool { void** m_arr; };

struct TreeTableQuickData {
    char pad[4];
    Pool* m_pool;
    int CountEntries() const;
};

int TreeTableQuickData::CountEntries() const {
    if (m_pool != 0) {
        void** arr = m_pool->m_arr;
        if (arr != 0) return ((int*)arr)[-1];
    }
    return 0;
}
