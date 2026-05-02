/* EString2::operator=(wchar_t) @ 0x802D46D8 (84 bytes) */

typedef unsigned short wchar_t_u;

struct EString2_OAW {
    wchar_t_u *m_str;
    void MakeCopy(wchar_t_u *s);
    void Deallocate(wchar_t_u *p);
    EString2_OAW& operator=(wchar_t_u c);
};

EString2_OAW& EString2_OAW::operator=(wchar_t_u c) {
    wchar_t_u tmp[2];
    tmp[0] = c;
    tmp[1] = 0;
    wchar_t_u *old = m_str;
    MakeCopy(tmp);
    Deallocate(old);
    return *this;
}
