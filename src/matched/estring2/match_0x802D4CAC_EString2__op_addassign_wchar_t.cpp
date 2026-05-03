// FLAGS: -fno-elide-constructors-only
/* EString2::operator+=(wchar_t) @ 0x802D4CAC (88 bytes) */

typedef unsigned short wchar_t_u;

struct EString2_APEWc {
    wchar_t_u *m_str;
    EString2_APEWc(const EString2_APEWc& o);
    EString2_APEWc(wchar_t_u *a, wchar_t_u *b);
    EString2_APEWc& operator+=(wchar_t c);
    EString2_APEWc operator+(wchar_t c) const;
    EString2_APEWc& operator=(wchar_t_u *s);
    void Deallocate(wchar_t_u *p);
};

EString2_APEWc& EString2_APEWc::operator+=(wchar_t c) {
    EString2_APEWc local = *this + c;
    EString2_APEWc *lp = &local;
    *this = local.m_str;
    lp->Deallocate(local.m_str);
    return *this;
}
