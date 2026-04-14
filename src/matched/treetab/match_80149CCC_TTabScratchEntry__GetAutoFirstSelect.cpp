/* TTabScratchEntry::GetAutoFirstSelect - 0x80149CCC (12 bytes) */
/* lhz r3, 272(r3); rlwinm r3, r3, 24, 31, 31; blr */

class TTabScratchEntry {
public:
    char pad[0x110];
    unsigned short m_flags;
    int GetAutoFirstSelect() const;
};

int TTabScratchEntry::GetAutoFirstSelect() const {
    return (m_flags >> 8) & 1;
}
