/* TreeTableAdScratch::AddRef(void) - 0x80149760 - 20 bytes */

struct TreeTableAdScratch {
    char _pad[12];
    int m_refCount;

    int AddRef();
};

int TreeTableAdScratch::AddRef() {
    return ++m_refCount;
}
