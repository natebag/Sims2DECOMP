/* IFFSlotDescList::AddRef(void) - 0x80145014 - 20 bytes */

class IFFSlotDescList {
public:
    char _pad[0x64];
    int m_refCount;

    int AddRef(void);
};

int IFFSlotDescList::AddRef(void) {
    return ++m_refCount;
}
