// 0x80149B84 (12 bytes)
// TTabScratchEntry::GetCanJoin(void) const
class TTabScratchEntry {
public:
    char m_pad[272];
    unsigned short m_flags;
    int GetCanJoin() const;
};

int TTabScratchEntry::GetCanJoin() const {
    return (m_flags >> 1) & 1;
}
