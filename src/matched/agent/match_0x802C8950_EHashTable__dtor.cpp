// 0x802C8950 EHashTable::~EHashTable (76B)
// dtor: bl RemoveAll(); bl MainHeap()->Free(m_field8); delete-flag check.

struct EAHeap {
    void Free(void* p);
};

extern EAHeap* MainHeap();

struct EHashTable {
    void* m_unused0;
    void* m_unused4;
    void* m_field8;
    void RemoveAll();
    ~EHashTable();
};

EHashTable::~EHashTable() {
    RemoveAll();
    MainHeap()->Free(m_field8);
}
