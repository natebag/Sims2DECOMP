// 0x8015E92C TreeTableQuickData::GetPrefixCheckTreeID() const (28B)

struct TreeTableRef {
    char pad[8];
    short m_prefixCheckTreeID;
};

struct TreeTableQuickData {
    char pad[4];
    TreeTableRef* m_ref;
    short GetPrefixCheckTreeID() const;
};

short TreeTableQuickData::GetPrefixCheckTreeID() const {
    return m_ref ? m_ref->m_prefixCheckTreeID : (short)0;
}
