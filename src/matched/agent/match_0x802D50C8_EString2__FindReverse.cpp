// 0x802D50C8 EString2::FindReverse(unsigned short) const (100B)
// ASMPROC_swap_adj: a=lwz b=add which=first
// ASMPROC_force_reg_at_pos: match="add 0,3,3" pos=0 from_reg=0 to_reg=9
// ASMPROC_force_reg_at_pos: match="lwz 9,0(30)" pos=0 from_reg=9 to_reg=0
// ASMPROC_force_reg_at_pos: match="add 9,9,0" pos=1 from_reg=9 to_reg=0
// ASMPROC_force_reg_at_pos: match="add 9,0,0" pos=2 from_reg=0 to_reg=9
// ASMPROC_swap_adj: a=bc b=addi which=first
// ASMPROC_swap_adj: a=add b=addi which=first
// ASMPROC_swap_adj: a=addic. b=addi which=first
typedef unsigned short wchar_t_u;

struct EString2_FR {
    wchar_t_u *m_str;
    int GetLength(void) const;
    int FindReverse(wchar_t_u c) const;
};

int EString2_FR::FindReverse(wchar_t_u c) const {
    int len = GetLength();
    wchar_t_u *p = m_str + len;
    if (--len < 0) return -1;
    --p;
    do {
        if (*p == c) return len;
        p--;
    } while (--len >= 0);
    return -1;
}
