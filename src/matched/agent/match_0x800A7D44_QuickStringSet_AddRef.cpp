/* QuickStringSet::AddRef(void) - 0x800A7D44 - 20 bytes */

struct QuickStringSet {
    char _pad[16];
    int m_refCount;

    int AddRef();
};

int QuickStringSet::AddRef() {
    return ++m_refCount;
}
