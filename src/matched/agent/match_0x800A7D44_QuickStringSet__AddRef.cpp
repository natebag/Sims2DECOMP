/* QuickStringSet::AddRef(void) at 0x800A7D44 (20B) */

struct QuickStringSet {
    char pad[0x10];
    int m_refCount;

    int AddRef(void);
};

int QuickStringSet::AddRef(void) {
    m_refCount = m_refCount + 1;
    return m_refCount;
}
