/* QuickDataSlotDescList::AddRef(void) - 0x801448F0 - 20 bytes */

class QuickDataSlotDescList {
public:
    char _pad[0x5C];
    int m_refCount;

    int AddRef(void);
};

int QuickDataSlotDescList::AddRef(void) {
    return ++m_refCount;
}
