/* TreeTableQuickData::GetNthOrderedEntry(int) const - 0x8015E238 - 92 bytes */
/* Calls TreeTable::GetIndexOfNthOrderedEntry, then virtual call through vtable */

struct TreeTable {
    int GetIndexOfNthOrderedEntry(int n) const;
};

class TreeTableQuickData {
public:
    char* m_vtable;
    TreeTable* m_impl;

    void* GetNthOrderedEntry(int n) const;
};

typedef void* (*WrapperFn)(void*, int);

void* TreeTableQuickData::GetNthOrderedEntry(int n) const {
    if (m_impl == 0) return 0;
    int idx = m_impl->GetIndexOfNthOrderedEntry(n);
    char* vt = m_vtable;
    short adj = *(short*)(vt + 0x78);
    WrapperFn fn = *(WrapperFn*)(vt + 0x7C);
    return fn((char*)this + adj, idx);
}