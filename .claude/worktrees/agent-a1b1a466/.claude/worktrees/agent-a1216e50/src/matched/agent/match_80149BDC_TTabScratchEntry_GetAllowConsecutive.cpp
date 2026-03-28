// 0x80149BDC (12 bytes)
// TTabScratchEntry::GetAllowConsecutive(void) const
class TTabScratchEntry {
public:
    char m_pad[272];
    unsigned short m_flags;
    int GetAllowConsecutive() const;
};

int TTabScratchEntry::GetAllowConsecutive() const {
    return (m_flags >> 3) & 1;
}
