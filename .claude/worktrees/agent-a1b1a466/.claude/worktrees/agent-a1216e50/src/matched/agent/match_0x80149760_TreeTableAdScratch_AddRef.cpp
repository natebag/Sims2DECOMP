/* TreeTableAdScratch::AddRef(void) - 0x80149760 - 20 bytes */

class TreeTableAdScratch {
public:
    char _pad[0x0C];
    int m_refCount;

    int AddRef(void);
};

int TreeTableAdScratch::AddRef(void) {
    return ++m_refCount;
}
