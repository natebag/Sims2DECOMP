// 0x80149C64 (12 bytes)
// TTabScratchEntry::GetAvailableToChildrenDemo(void) const
class TTabScratchEntry {
public:
    char m_pad[272];
    unsigned short m_flags;
    int GetAvailableToChildrenDemo() const;
};

int TTabScratchEntry::GetAvailableToChildrenDemo() const {
    return (m_flags >> 5) & 1;
}
