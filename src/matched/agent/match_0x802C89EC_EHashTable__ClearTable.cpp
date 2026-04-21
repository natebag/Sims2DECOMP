// 0x802C89EC (48B) EHashTable::ClearTable(void)
// memset(this->m_buf, 0, this->m_count * 4).

typedef unsigned int size_t;
extern "C" void* memset(void* dest, int val, size_t n);

class EHashTable {
public:
    char pad[8];
    void* m_buf;
    int m_count;
    void ClearTable();
};

void EHashTable::ClearTable() {
    memset(m_buf, 0, m_count * 4);
}
