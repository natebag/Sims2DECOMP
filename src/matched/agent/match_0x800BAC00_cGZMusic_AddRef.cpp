/* cGZMusic::AddRef(void) - 0x800BAC00 - 20 bytes */

struct cGZMusic {
    char _pad[4];
    int m_refCount;

    int AddRef();
};

int cGZMusic::AddRef() {
    return ++m_refCount;
}
