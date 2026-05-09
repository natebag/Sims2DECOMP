// IFFSlotDescList::GetNumSlots(void) - 0x8014527C (32B)
// Pointer subtraction with magic /72 (8 * 9) — element size 72.

struct IFFSlotDesc {
    char data[72];
};

class IFFSlotDescList {
public:
    char _pad[84];
    IFFSlotDesc *m_begin;  // +84
    IFFSlotDesc *m_end;    // +88
    int GetNumSlots();
};

int IFFSlotDescList::GetNumSlots()
{
    return m_end - m_begin;
}
