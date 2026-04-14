/* TreeTableQuickData::GetEntryByIndex(int) const - 0x8015E17C - 96 bytes */
/* Sign-extends index to short, calls TreeTable::GetIndexOfResource, virtual call */

struct TreeTable {
    int GetIndexOfResource(short idx) const;
};

class TreeTableQuickData {
public:
    char* m_vtable;
    TreeTable* m_impl;

    void* GetEntryByIndex(int index) const;
};

typedef void* (*WrapperFn)(void*, int);

void* TreeTableQuickData::GetEntryByIndex(int index) const {
    if (m_impl == 0) return 0;
    int idx = m_impl->GetIndexOfResource((short)index);
    char* vt = m_vtable;
    short adj = *(short*)(vt + 0x78);
    WrapperFn fn = *(WrapperFn*)(vt + 0x7C);
    return fn((char*)this + adj, idx);
}