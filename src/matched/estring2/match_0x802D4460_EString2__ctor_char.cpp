/* EString2::EString2(char) @ 0x802D4460 (64 bytes) */

typedef unsigned short wchar_t_u;

struct EString2_CC {
    wchar_t_u *m_str;
    EString2_CC(char c);
    void MakeCopy(wchar_t_u *s);
};

EString2_CC::EString2_CC(char c) {
    wchar_t_u tmp[2];
    tmp[0] = (wchar_t_u)c;
    tmp[1] = 0;
    MakeCopy(tmp);
}
