// FLAGS: -fno-elide-constructors-only
/* EString2::operator+=(EString &) @ 0x802D4E00 (88 bytes) */

typedef unsigned short wchar_t_u;

struct EStr2_ES { wchar_t_u *m_str; };

struct EString2_APEES {
    wchar_t_u *m_str;
    EString2_APEES(const EString2_APEES& o);
    EString2_APEES& operator+=(EStr2_ES& s);
    EString2_APEES operator+(EStr2_ES& s) const;
    EString2_APEES& operator=(wchar_t_u *s);
    void Deallocate(wchar_t_u *p);
    EString2_APEES(wchar_t_u *a, wchar_t_u *b);
};

EString2_APEES& EString2_APEES::operator+=(EStr2_ES& s) {
    EString2_APEES local = *this + s;
    EString2_APEES *lp = &local;
    *this = local.m_str;
    lp->Deallocate(local.m_str);
    return *this;
}
