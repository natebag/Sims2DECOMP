// 0x80149B58 (12 bytes)
// TTabScratchEntry::GetAvailableToVisitors(void) const
class TTabScratchEntry {
public:
    char m_pad[272];
    unsigned short m_flags;
    int GetAvailableToVisitors() const;
};

int TTabScratchEntry::GetAvailableToVisitors() const {
    return m_flags & 1;
}
