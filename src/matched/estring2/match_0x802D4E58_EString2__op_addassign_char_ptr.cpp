// FLAGS: -fno-elide-constructors-only
/* EString2::operator+=(char *) @ 0x802D4E58 (88 bytes) */

typedef unsigned short wchar_t_u;

struct EString2_APECp {
    wchar_t_u *m_str;
    EString2_APECp(const EString2_APECp& o);
    EString2_APECp& operator+=(char *s);
    EString2_APECp operator+(char *s) const;
    EString2_APECp& operator=(wchar_t_u *s);
    void Deallocate(wchar_t_u *p);
    EString2_APECp(wchar_t_u *a, wchar_t_u *b);
};

EString2_APECp& EString2_APECp::operator+=(char *s) {
    EString2_APECp local = *this + s;
    EString2_APECp *lp = &local;
    *this = local.m_str;
    lp->Deallocate(local.m_str);
    return *this;
}
