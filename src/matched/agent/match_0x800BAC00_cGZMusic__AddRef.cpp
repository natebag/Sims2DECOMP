/* cGZMusic::AddRef(void) at 0x800BAC00 (20B) */

struct cGZMusic {
    char pad[0x04];
    int m_refCount;

    int AddRef(void);
};

int cGZMusic::AddRef(void) {
    m_refCount = m_refCount + 1;
    return m_refCount;
}
