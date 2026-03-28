// 0x80149CF8 (12 bytes)
// TTabScratchEntry::GetAvailableToVisitingPlayers(void) const
class TTabScratchEntry {
public:
    char m_pad[272];
    unsigned short m_flags;
    int GetAvailableToVisitingPlayers() const;
};

int TTabScratchEntry::GetAvailableToVisitingPlayers() const {
    return (m_flags >> 9) & 1;
}
