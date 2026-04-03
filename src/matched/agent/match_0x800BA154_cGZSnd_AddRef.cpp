/* cGZSnd::AddRef(void) - 0x800BA154 - 20 bytes */

struct cGZSnd {
    char _pad[4];
    int m_refCount;

    int AddRef();
};

int cGZSnd::AddRef() {
    return ++m_refCount;
}
