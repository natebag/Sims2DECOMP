// 0x80149980 (60B) TreeTable::GetIndexOfNthOrderedEntry(int) const
// Returns m_orderIndex (signed half at +26) of the n-th 36-byte entry, or -1.

struct TreeTableEntry { char _pad[26]; short m_orderIndex; char _pad2[8]; };

class TreeTable {
public:
    TreeTableEntry* m_data;
    int GetIndexOfNthOrderedEntry(int n) const;
};

int TreeTable::GetIndexOfNthOrderedEntry(int n) const
{
    TreeTableEntry* data = m_data;
    int size = 0;
    if (data) size = ((int*)data)[-1];
    if (n >= 0 && n < size) {
        int off = n * 36;
        return *(short*)((char*)data + off + 26);
    }
    return -1;
}
