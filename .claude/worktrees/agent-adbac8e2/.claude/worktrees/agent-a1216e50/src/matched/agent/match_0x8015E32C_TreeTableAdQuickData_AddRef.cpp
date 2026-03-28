/* TreeTableAdQuickData::AddRef(void) - 0x8015E32C - 20 bytes */

class TreeTableAdQuickData {
public:
    char _pad[0x08];
    int m_refCount;

    int AddRef(void);
};

int TreeTableAdQuickData::AddRef(void) {
    return ++m_refCount;
}
