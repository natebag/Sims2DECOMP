// 0x80149CCC (12 bytes)
// TTabScratchEntry::GetAutoFirstSelect(void) const
class TTabScratchEntry {
public:
    char m_pad[272];
    unsigned short m_flags;
    int GetAutoFirstSelect() const;
};

int TTabScratchEntry::GetAutoFirstSelect() const {
    return (m_flags >> 8) & 1;
}
