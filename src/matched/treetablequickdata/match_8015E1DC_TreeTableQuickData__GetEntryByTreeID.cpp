/* TreeTableQuickData::GetEntryByTreeID(short,short) const - 0x8015E1DC - 92 bytes */
/* Calls TreeTable::GetIndexByTreeID, then virtual call through vtable */

struct TreeTable {
    int GetIndexByTreeID(short a, short b) const;
};

class TreeTableQuickData {
public:
    char* m_vtable;
    TreeTable* m_impl;

    void* GetEntryByTreeID(short a, short b) const;
};

typedef void* (*WrapperFn)(void*, int);

void* TreeTableQuickData::GetEntryByTreeID(short a, short b) const {
    if (m_impl == 0) return 0;
    int idx = m_impl->GetIndexByTreeID(a, b);
    char* vt = m_vtable;
    short adj = *(short*)(vt + 0x78);
    WrapperFn fn = *(WrapperFn*)(vt + 0x7C);
    return fn((char*)this + adj, idx);
}