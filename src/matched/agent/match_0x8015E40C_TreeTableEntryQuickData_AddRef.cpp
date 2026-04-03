/* TreeTableEntryQuickData::AddRef(void) - 0x8015E40C - 20 bytes */

struct TreeTableEntryQuickData {
    char _pad[24];
    int m_refCount;

    int AddRef();
};

int TreeTableEntryQuickData::AddRef() {
    return ++m_refCount;
}
