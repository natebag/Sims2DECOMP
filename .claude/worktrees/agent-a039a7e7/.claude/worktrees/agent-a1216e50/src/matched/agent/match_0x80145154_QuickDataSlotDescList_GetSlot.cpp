/* QuickDataSlotDescList::GetSlot(int) - 0x80145154 - 16 bytes */
/* mulli r4, r4, 0x48; lwz r3, 0x54(r3); add r3, r3, r4; blr */

class QuickDataSlotDescList {
public:
    char _pad[0x54];
    char* m_slots;

    void* GetSlot(int index);
};

void* QuickDataSlotDescList::GetSlot(int index) {
    return m_slots + index * 0x48;
}
