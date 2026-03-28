struct ResIdTable {
    int m_count;
    unsigned int m_ids[1];
};

class EResourceManager {
    char pad[76];
    ResIdTable* m_pIdTable;
public:
    void GetIds(unsigned int*& ids, int& count);
};

void EResourceManager::GetIds(unsigned int*& ids, int& count) {
    count = m_pIdTable->m_count;
    ids = &m_pIdTable->m_ids[0];
}
