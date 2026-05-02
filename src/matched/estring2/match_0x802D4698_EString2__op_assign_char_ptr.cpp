/* EString2::operator=(char *) @ 0x802D4698 (64 bytes) */

typedef unsigned short wchar_t_u;

struct EString2_OAPC {
    wchar_t_u *m_str;
    void MakeCopyFromChars(char *s);
    void Deallocate(wchar_t_u *p);
    EString2_OAPC& operator=(char *s);
};

EString2_OAPC& EString2_OAPC::operator=(char *s) {
    wchar_t_u *old = m_str;
    MakeCopyFromChars(s);
    Deallocate(old);
    return *this;
}
