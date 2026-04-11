/* TreeTableAdQuickData::AddRef(void) - 0x8015E32C - 20 bytes */

struct TreeTableAdQuickData {
    char _pad[8];
    int m_refCount;

    int AddRef();
};

int TreeTableAdQuickData::AddRef() {
    return ++m_refCount;
}
