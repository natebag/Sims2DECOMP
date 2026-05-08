// 0x8015E900 (44B) TreeTableQuickData::CountEntries(void) const

struct Pool { void** m_arr; };

struct TreeTableQuickData {
    char pad[4];
    Pool* m_pool;
    int CountEntries() const;
};

int TreeTableQuickData::CountEntries() const {
    Pool* p = m_pool;
    if (p == 0) goto bail;
    {
        int* arr = (int*)p->m_arr;
        int n = arr ? arr[-1] : 0;
        return n;
    }
bail:
    return 0;
}
