/* TTabScratchEntry::AddRef(void) - 0x80149840 - 20 bytes */

class TTabScratchEntry {
public:
    char _pad[0x118];
    int m_refCount;

    int AddRef(void);
};

int TTabScratchEntry::AddRef(void) {
    return ++m_refCount;
}
