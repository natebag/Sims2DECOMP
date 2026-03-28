// 0x80149BB0 (12 bytes)
// TTabScratchEntry::GetImmediate(void) const
class TTabScratchEntry {
public:
    char m_pad[272];
    unsigned short m_flags;
    int GetImmediate() const;
};

int TTabScratchEntry::GetImmediate() const {
    return (m_flags >> 2) & 1;
}
