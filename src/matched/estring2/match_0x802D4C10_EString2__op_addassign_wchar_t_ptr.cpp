// EString2::operator+=(unsigned wchar_t *) @ 0x802D4C10 (88 bytes)
// ASMPROC_force_reg: match="addi 29,1" from_reg=29 to_reg=3 occurrence=0
// ASMPROC_swap_operands: match="mr 3,29" pos=0,1 occurrence=0

typedef unsigned short wchar_t_u;

struct EString2_APEW {
    wchar_t_u *m_str;
    EString2_APEW& operator+=(wchar_t_u *s);
    EString2_APEW(wchar_t_u *a, wchar_t_u *b);
    EString2_APEW& operator=(wchar_t_u *s);
    void Deallocate(wchar_t_u *p);
};

EString2_APEW& EString2_APEW::operator+=(wchar_t_u *s) {
    EString2_APEW local(m_str, s);
    *this = local.m_str;
    local.Deallocate(local.m_str);
    return *this;
}
