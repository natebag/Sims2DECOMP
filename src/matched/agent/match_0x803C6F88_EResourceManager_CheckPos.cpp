// 0x803C6F88 (24B) EResourceManager::ResourceIndexRecord::CheckPos(... &, ... &)

namespace EResourceManager {

struct ResourceIndexRecord {
    char pad[4];
    int m_pos;
    static bool CheckPos(ResourceIndexRecord& a, ResourceIndexRecord& b);
};

bool ResourceIndexRecord::CheckPos(ResourceIndexRecord& a, ResourceIndexRecord& b) {
    return a.m_pos < b.m_pos;
}

}
