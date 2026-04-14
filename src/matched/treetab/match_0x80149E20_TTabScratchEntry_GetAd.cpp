/* TTabScratchEntry::GetAd(int) - 0x80149E20 - 16 bytes */
/* rlwinm r4, r4, 4, 0, 27; addi r4, r4, 8; add r3, r3, r4; blr */

struct AdEntry2 {
    int data[4];
};

class TTabScratchEntry2 {
public:
    char _pad[0x8];
    AdEntry2 m_ads[8];

    AdEntry2* GetAd(int index);
};

AdEntry2* TTabScratchEntry2::GetAd(int index) {
    return &m_ads[index];
}
