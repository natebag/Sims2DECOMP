// 0x80149CA0 (12 bytes)
// TTabScratchEntry::GetDebugOnly(void) const
class TTabScratchEntry {
public:
    char m_pad[272];
    unsigned short m_flags;
    int GetDebugOnly() const;
};

int TTabScratchEntry::GetDebugOnly() const {
    return (m_flags >> 7) & 1;
}
