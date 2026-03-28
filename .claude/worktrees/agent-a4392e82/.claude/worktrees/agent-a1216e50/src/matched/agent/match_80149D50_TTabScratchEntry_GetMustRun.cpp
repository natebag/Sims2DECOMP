// 0x80149D50 (12 bytes)
// TTabScratchEntry::GetMustRun(void) const
class TTabScratchEntry {
public:
    char m_pad[272];
    unsigned short m_flags;
    int GetMustRun() const;
};

int TTabScratchEntry::GetMustRun() const {
    return (m_flags >> 11) & 1;
}
