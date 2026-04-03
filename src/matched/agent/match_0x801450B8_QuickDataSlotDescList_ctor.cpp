/* QuickDataSlotDescList::QuickDataSlotDescList(void) - 0x801450B8 - 68 bytes */

struct ObjectDataSlotDescList {
    char _data[92];
    ObjectDataSlotDescList();
};

struct QuickDataSlotDescList : public ObjectDataSlotDescList {
    int m_refCount;
    QuickDataSlotDescList();
};

extern void *__vt__QuickDataSlotDescList[];

QuickDataSlotDescList::QuickDataSlotDescList() : ObjectDataSlotDescList() {
    m_refCount = 0;
    *(void ***)this = __vt__QuickDataSlotDescList;
}
