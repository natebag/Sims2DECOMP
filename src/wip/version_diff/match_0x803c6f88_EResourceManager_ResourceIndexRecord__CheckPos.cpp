// 0x803c6f88 EResourceManager::ResourceIndexRecord::CheckPos(EResourceManager::ResourceIndexRecord &, EResourceManager::ResourceIndexRecord &) (24B)

struct ResourceIndexRecord {
    char pad[0x04];
    int m_pos;
    int CheckPos(ResourceIndexRecord& a, ResourceIndexRecord& b);
};

int ResourceIndexRecord::CheckPos(ResourceIndexRecord& a, ResourceIndexRecord& b) {
    return a.m_pos == b.m_pos;
}
