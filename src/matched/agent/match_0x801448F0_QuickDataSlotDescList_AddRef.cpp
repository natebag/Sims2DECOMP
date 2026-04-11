/* QuickDataSlotDescList::AddRef(void) - 0x801448F0 - 20 bytes */

struct QuickDataSlotDescList {
    char _pad[92];
    int m_refCount;

    int AddRef();
};

int QuickDataSlotDescList::AddRef() {
    return ++m_refCount;
}
