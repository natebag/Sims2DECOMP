class ResourceBehavior {
public:
    char pad[0x1C];
    int m_refCount;

    int AddRef(void);
};

int ResourceBehavior::AddRef(void) {
    m_refCount = m_refCount + 1;
    return m_refCount;
}
