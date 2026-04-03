/* TTabScratchEntry::AddRef(void) - 0x80149840 - 20 bytes */

struct TTabScratchEntry {
    char _pad[280];
    int m_refCount;

    int AddRef();
};

int TTabScratchEntry::AddRef() {
    return ++m_refCount;
}
