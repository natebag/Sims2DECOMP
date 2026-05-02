/* EString2::operator=(unsigned wchar_t *) @ 0x802D4658 (64 bytes) */

typedef unsigned short wchar_t_u;

struct EString2_OAP {
    wchar_t_u *m_str;
    void MakeCopy(wchar_t_u *s);
    void Deallocate(wchar_t_u *p);
    EString2_OAP& operator=(wchar_t_u *s);
};

EString2_OAP& EString2_OAP::operator=(wchar_t_u *s) {
    wchar_t_u *old = m_str;
    MakeCopy(s);
    Deallocate(old);
    return *this;
}
