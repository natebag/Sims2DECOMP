/* EString2::EString2(wchar_t) @ 0x802D4030 (64 bytes) */

typedef unsigned short wchar_t_u;

struct EString2_CW {
    wchar_t_u *m_str;
    EString2_CW(wchar_t_u c);
    void MakeCopy(wchar_t_u *s);
};

EString2_CW::EString2_CW(wchar_t_u c) {
    wchar_t_u tmp[2];
    tmp[0] = c;
    tmp[1] = 0;
    MakeCopy(tmp);
}
