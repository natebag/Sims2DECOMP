// 0x80149C34 (16 bytes)
// TTabScratchEntry::GetAvailableToAdults(void) const
class TTabScratchEntry {
    char pad[272];
    unsigned short m_field272;
public:
    bool GetAvailableToAdults() const;
};

bool TTabScratchEntry::GetAvailableToAdults() const {
    return ((m_field272 ^ 0x40) >> 6) & 1;
}
