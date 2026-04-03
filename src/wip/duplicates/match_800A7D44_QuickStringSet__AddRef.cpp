class QuickStringSet {
public:
    char pad[0x10];
    int m_refCount;

    int AddRef(void);
};

int QuickStringSet::AddRef(void) {
    m_refCount = m_refCount + 1;
    return m_refCount;
}
