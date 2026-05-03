// FLAGS: -fno-elide-constructors-only
/* EString2::operator+(EString &) const @ 0x802D4D60 (92 bytes) */

typedef unsigned short wchar_t_u;

struct EStr2_ES3 { wchar_t_u *m_str; };

struct EString2_APLEs_L {
    wchar_t_u *m_str;
    void MakeCopy(wchar_t_u *s);
    void Deallocate(wchar_t_u *p);
};

struct EString2_APLEs {
    wchar_t_u *m_str;
    EString2_APLEs(const EString2_APLEs& o);
    EString2_APLEs(wchar_t_u *a, wchar_t_u *b);
    EString2_APLEs operator+(EStr2_ES3& s) const;
};

EString2_APLEs EString2_APLEs::operator+(EStr2_ES3& s) const {
    wchar_t_u *p = m_str;
    EString2_APLEs_L local;
    EString2_APLEs_L *lp = &local;
    lp->MakeCopy(s.m_str);
    EString2_APLEs result(p, local.m_str);
    lp->Deallocate(local.m_str);
    return result;
}
