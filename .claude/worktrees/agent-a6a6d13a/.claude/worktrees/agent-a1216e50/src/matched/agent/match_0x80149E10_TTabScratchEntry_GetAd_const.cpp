/* TTabScratchEntry::GetAd(int) const - 0x80149E10 - 16 bytes */
/* rlwinm r4, r4, 4, 0, 27; addi r4, r4, 8; add r3, r3, r4; blr */
/* Returns this + 8 + index*16 */

struct AdEntry {
    int data[4];
};

class TTabScratchEntry {
public:
    char _pad[0x8];
    AdEntry m_ads[8];

    const AdEntry* GetAd(int index) const;
};

const AdEntry* TTabScratchEntry::GetAd(int index) const {
    return &m_ads[index];
}
