/* FloatConstantsQuickData::AddRef(void) - 0x800B717C - 20 bytes */

struct FloatConstantsQuickData {
    char _pad[16];
    int m_refCount;

    int AddRef();
};

int FloatConstantsQuickData::AddRef() {
    return ++m_refCount;
}
