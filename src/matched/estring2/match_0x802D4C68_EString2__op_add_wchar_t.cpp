// FLAGS: -fno-elide-constructors-only
/* EString2::operator+(wchar_t) @ 0x802D4C68 (68 bytes) */

typedef unsigned short wchar_t_u;

struct EString2_OPA {
    wchar_t_u *m_str;
    EString2_OPA(wchar_t_u *s1, wchar_t_u *s2);
    EString2_OPA operator+(wchar_t_u c) const;
};

EString2_OPA EString2_OPA::operator+(wchar_t_u c) const {
    wchar_t_u tmp[2];
    tmp[0] = c;
    tmp[1] = 0;
    return EString2_OPA(m_str, tmp);
}
