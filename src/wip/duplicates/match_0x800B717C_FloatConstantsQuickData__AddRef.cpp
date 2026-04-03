/* FloatConstantsQuickData::AddRef(void) at 0x800B717C (20B) */

struct FloatConstantsQuickData {
    char pad[0x10];
    int m_refCount;

    int AddRef(void);
};

int FloatConstantsQuickData::AddRef(void) {
    m_refCount = m_refCount + 1;
    return m_refCount;
}
