// FLAGS: -fno-elide-constructors-only
/* EString2::operator+(char) const @ 0x802D4DBC (68 bytes) */

typedef unsigned short wchar_t_u;

struct EString2_OPAC {
    wchar_t_u *m_str;
    EString2_OPAC(wchar_t_u *s1, wchar_t_u *s2);
    EString2_OPAC operator+(char c) const;
};

EString2_OPAC EString2_OPAC::operator+(char c) const {
    wchar_t_u tmp[2];
    tmp[0] = (wchar_t_u)c;
    tmp[1] = 0;
    return EString2_OPAC(m_str, tmp);
}
