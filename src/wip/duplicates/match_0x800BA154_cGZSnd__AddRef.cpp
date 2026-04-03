/* cGZSnd::AddRef(void) at 0x800BA154 (20B) */

struct cGZSnd {
    char pad[0x04];
    int m_refCount;

    int AddRef(void);
};

int cGZSnd::AddRef(void) {
    m_refCount = m_refCount + 1;
    return m_refCount;
}
