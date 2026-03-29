// 0x8015E8CC (28 bytes)
// TreeTableQuickData::GetID(void) const

struct TreeTableImpl_GID {
    char _[6];
    short m_id;
};

class TreeTableQuickData_GID {
    void* _vtable;
    TreeTableImpl_GID* m_impl;
public:
    int GetID() const;
};

int TreeTableQuickData_GID::GetID() const {
    if (!m_impl) return 0;
    return m_impl->m_id;
}
