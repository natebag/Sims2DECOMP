// EString::MakeUpper(void) - 0x802D2C48 (52B)
// FLAGS: -fno-schedule-insns
// ASMPROC_force_reg_at_pos: match="lwz 3,0(3)" pos=0 from_reg=3 to_reg=11
// ASMPROC_region_gpr_relabel: start_anchor="lwz 11,0(3)" start_mode=after end_anchor="blr" end_mode=at rename="3:11"

struct EString {
    char* m_pBuffer;
    int m_nLen;

    void MakeUpper(void);
};

void EString::MakeUpper(void) {
    char* p = m_pBuffer;
    unsigned char c = (unsigned char)*p;
    if (!c) return;
    do {
        if ((unsigned int)(c - 'a') <= 25u)
            *p = (char)(c - 32);
        c = (unsigned char)*++p;
    } while (c);
}
