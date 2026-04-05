// 0x801490D0 (52 bytes)
// TreeStack::GetNthFrame(int)
// DOL: mr. r4; blt->null; bounds; blt+12->valid; null: li 0;blr; valid: rlwinm;lwzx r3,r11,r9;blr
// NOTE: [VERSION_DIFF] - control flow layout doesn't match exactly

class TreeStack {
public:
    char _pad[8];
    void** m_begin;  // offset 8
    void** m_end;    // offset 12
    void* GetNthFrame(int n);
};

void* TreeStack::GetNthFrame(int n) {
    if (n < 0) return 0;
    int size = (int)(m_end - m_begin);
    if ((unsigned)n >= (unsigned)size) return 0;
    return m_begin[n];
}
