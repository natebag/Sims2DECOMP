/* EString2::operator=(char) @ 0x802D472C (84 bytes) */

typedef unsigned short wchar_t_u;

struct EString2_OAC {
    wchar_t_u *m_str;
    void MakeCopy(wchar_t_u *s);
    void Deallocate(wchar_t_u *p);
    EString2_OAC& operator=(char c);
};

EString2_OAC& EString2_OAC::operator=(char c) {
    wchar_t_u tmp[2];
    tmp[0] = (wchar_t_u)c;
    tmp[1] = 0;
    wchar_t_u *old = m_str;
    MakeCopy(tmp);
    Deallocate(old);
    return *this;
}
