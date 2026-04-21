// 0x803615C8 EStringTableNoCase::~EStringTableNoCase (76B)
// dtor: bl RemoveAll(); MainHeap()->Free(m_field8); delete-flag check.

struct EAHeap {
    void Free(void* p);
};

extern EAHeap* MainHeap();

struct EStringTableNoCase {
    void* m_unused0;
    void* m_unused4;
    void* m_field8;
    void RemoveAll();
    ~EStringTableNoCase();
};

EStringTableNoCase::~EStringTableNoCase() {
    RemoveAll();
    MainHeap()->Free(m_field8);
}
