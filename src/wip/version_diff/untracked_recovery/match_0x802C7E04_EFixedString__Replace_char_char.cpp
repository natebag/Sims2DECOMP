// EFixedString::Replace(char, char) - 0x802C7E04 (48B)
// WALL: loop back-edge structural mismatch
// DOL: extsb @ .text+0x10 IS the loop top (label before extsb)
// devkitPPC GCC: places label AFTER pre-loop extsb init (label before cmpw @ .text+0x14)
// `int sc` approach gives correct 12 instructions but back-edge targets +0x14 vs DOL's +0x10
// No current ASMPROC directive can move a label. Needs swap_adj enhancement for insn-label swap.

struct EFixedString {
    char* m_pBuffer;
    int m_nMaxSize;

    void Replace(char from, char to);
};

void EFixedString::Replace(char from, char to) {
    char* p = m_pBuffer;
    unsigned char c = *(unsigned char*)p;
    if (!c) return;
    int sc = (signed char)c;
    do {
        if (sc == from)
            *p = to;
        c = *(unsigned char*)++p;
        sc = c;
    } while (c);
}
