/* IFFSlotDescList::AddRef(void) - 0x80145014 - 20 bytes */

struct IFFSlotDescList {
    char _pad[100];
    int m_refCount;

    int AddRef();
};

int IFFSlotDescList::AddRef() {
    return ++m_refCount;
}
