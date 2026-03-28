// 0x80149C08 (12 bytes)
// TTabScratchEntry::GetAvailableToGhosts(void) const
class TTabScratchEntry {
public:
    char m_pad[272];
    unsigned short m_flags;
    int GetAvailableToGhosts() const;
};

int TTabScratchEntry::GetAvailableToGhosts() const {
    return (m_flags >> 4) & 1;
}
