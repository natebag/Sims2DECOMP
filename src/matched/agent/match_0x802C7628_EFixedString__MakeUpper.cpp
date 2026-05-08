// EFixedString::MakeUpper(void) - 0x802C7628 (52B)
// ASMPROC_force_reg_at_pos: match="lwz 3,0(3)" pos=0 from_reg=3 to_reg=11
// ASMPROC_region_gpr_relabel: start_anchor="lwz 11,0(3)" start_mode=after end_anchor="blr" end_mode=at rename="3:11"

struct EFixedString {
    char* m_pBuffer;
    int m_nMaxSize;

    void MakeUpper(void);
};

void EFixedString::MakeUpper(void) {
    char* p = m_pBuffer;
    unsigned char c = *p;
    if (!c) return;
    do {
        if ((unsigned int)(c - 'a') <= 25u)
            *p = c - 32;
        c = *++p;
    } while (c);
}
