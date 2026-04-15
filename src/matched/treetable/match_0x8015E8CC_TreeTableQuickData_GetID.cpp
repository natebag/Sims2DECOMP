// 0x8015E8CC TreeTableQuickData::GetID() const (28B)

struct TreeTableRef {
    char pad[6];
    short m_id;
};

struct TreeTableQuickData {
    char pad[4];
    TreeTableRef* m_ref;
    short GetID() const;
};

short TreeTableQuickData::GetID() const {
    return m_ref ? m_ref->m_id : (short)0;
}
