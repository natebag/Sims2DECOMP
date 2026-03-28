// 0x80149D24 (12 bytes)
// TTabScratchEntry::GetIgnorePrefixTree(void) const
class TTabScratchEntry {
public:
    char m_pad[272];
    unsigned short m_flags;
    int GetIgnorePrefixTree() const;
};

int TTabScratchEntry::GetIgnorePrefixTree() const {
    return (m_flags >> 10) & 1;
}
