// [VERSION_DIFF] 0x8015E92C (28 bytes)
// DOL: lwz r3, 4(r3) + beq-forward; Our GCC 2.95 SN: lwz r9 + beqlr (different reg alloc)
// TreeTableQuickData::GetPrefixCheckTreeID(void) const

struct TreeTableImpl_GPCTI {
    char _[8];
    short m_prefixId;
};

class TreeTableQuickData_GPCTI {
    void* _vtable;
    TreeTableImpl_GPCTI* m_impl;
public:
    int GetPrefixCheckTreeID() const;
};

int TreeTableQuickData_GPCTI::GetPrefixCheckTreeID() const {
    if (!m_impl) return 0;
    return m_impl->m_prefixId;
}
