// 0x802D53F4 EString2::FixTrailingSlash() (88B)
// ASMPROC_region_gpr_relabel: start_anchor="addi 0,3,-1" start_mode=at end_anchor="lhzx 9,11,0" end_mode=at rename="0:9,9:0" unsafe_clobber=true
// ASMPROC_force_reg_at_pos: match="cmpwi 0,9,92" pos=1 from_reg=9 to_reg=0
typedef unsigned short wchar_t_u;

struct EString2_FTS {
    wchar_t_u *m_str;
    int GetLength(void) const;
    EString2_FTS& operator+=(char c);
    void FixTrailingSlash(void);
};

void EString2_FTS::FixTrailingSlash(void) {
    int len = GetLength();
    if (len) {
        int i = len - 1;
        wchar_t_u *base = m_str;
        if (base[i] != '\\') {
            *this += (char)'\\';
        }
    }
}
