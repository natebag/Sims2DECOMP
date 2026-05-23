// 0x801493B0 (60B) TreeTable::GetNthEntry(int) const
// Sign + bounds checked indexed access into 36-byte entry array.

struct TreeTableEntry { char _pad[36]; };

class TreeTable {
public:
    TreeTableEntry* m_data;
    TreeTableEntry* GetNthEntry(int n) const;
};

TreeTableEntry* TreeTable::GetNthEntry(int n) const
{
    if (n >= 0) {
        register TreeTableEntry* raw asm("r0") = m_data;
        register int size asm("r11") = 0;
        register TreeTableEntry* data asm("r9") = raw;
        if (raw) size = ((int*)data)[-1];
        if (n < size) return &raw[n];
    }
    return 0;
}
