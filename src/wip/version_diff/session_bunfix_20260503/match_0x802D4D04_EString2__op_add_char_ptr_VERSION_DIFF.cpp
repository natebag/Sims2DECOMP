// FLAGS: -fno-elide-constructors-only
/* EString2::operator+(char *) const @ 0x802D4D04 (92 bytes) */

typedef unsigned short wchar_t_u;

struct EString2_APLCp_L {
    wchar_t_u *m_str;
    void MakeCopyFromChars(char *s);
    void Deallocate(wchar_t_u *p);
};

struct EString2_APLCp {
    wchar_t_u *m_str;
    EString2_APLCp(const EString2_APLCp& o);
    EString2_APLCp(wchar_t_u *a, wchar_t_u *b);
    EString2_APLCp operator+(char *s) const;
};

EString2_APLCp EString2_APLCp::operator+(char *s) const {
    EString2_APLCp_L local;
    EString2_APLCp_L *lp = &local;
    lp->MakeCopyFromChars(s);
    EString2_APLCp result(m_str, local.m_str);
    lp->Deallocate(local.m_str);
    return result;
}
