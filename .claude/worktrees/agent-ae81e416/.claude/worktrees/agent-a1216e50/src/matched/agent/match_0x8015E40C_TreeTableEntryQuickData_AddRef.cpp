/* TreeTableEntryQuickData::AddRef(void) - 0x8015E40C - 20 bytes */

class TreeTableEntryQuickData {
public:
    char _pad[0x18];
    int m_refCount;

    int AddRef(void);
};

int TreeTableEntryQuickData::AddRef(void) {
    return ++m_refCount;
}
