/* IFFSlotDescList::GetSlot(int) - 0x8014529C - 16 bytes */
/* mulli r4, r4, 0x48; lwz r3, 0x54(r3); add r3, r3, r4; blr */

class IFFSlotDescList {
public:
    char _pad[0x54];
    char* m_slots;

    void* GetSlot(int index);
};

void* IFFSlotDescList::GetSlot(int index) {
    return m_slots + index * 0x48;
}
