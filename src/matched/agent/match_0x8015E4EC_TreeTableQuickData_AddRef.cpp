/* TreeTableQuickData::AddRef(void) - 0x8015E4EC - 20 bytes */

struct TreeTableQuickData {
    char _pad[32];
    int m_refCount;

    int AddRef();
};

int TreeTableQuickData::AddRef() {
    return ++m_refCount;
}
