// FLAGS: -fno-elide-constructors-only
/* EString2::operator+=(char) @ 0x802D4EB0 (88 bytes) */

typedef unsigned short wchar_t_u;

struct EString2_APECc {
    wchar_t_u *m_str;
    EString2_APECc(const EString2_APECc& o);
    EString2_APECc& operator+=(char c);
    EString2_APECc operator+(wchar_t_u c) const;
    EString2_APECc& operator=(wchar_t_u *s);
    void Deallocate(wchar_t_u *p);
    EString2_APECc(wchar_t_u *a, wchar_t_u *b);
};

EString2_APECc& EString2_APECc::operator+=(char c) {
    EString2_APECc local = *this + (wchar_t_u)c;
    EString2_APECc *lp = &local;
    *this = local.m_str;
    lp->Deallocate(local.m_str);
    return *this;
}
