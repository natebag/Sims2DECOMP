// 0x80352318 Effects::EffectsManager::~EffectsManager (76B)
// dtor: m_list2.RemoveAll(); m_list1.RemoveAll(); delete-flag check.

struct ENodeList {
    void* head;  // 4B so struct has size > 1
    void RemoveAll();
};

namespace Effects {

struct EffectsManager {
    void* m_unused;
    ENodeList m_list1;       // at +4 (4 bytes)
    char pad[8];             // 8 bytes pad
    ENodeList m_list2;       // at +16
    ~EffectsManager();
};

EffectsManager::~EffectsManager() {
    m_list2.RemoveAll();
    m_list1.RemoveAll();
}

}
