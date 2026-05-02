// FLAGS: -fno-elide-constructors-only
/* operator+(wchar_t, EString2 &) @ 0x802D5334 (68 bytes) */

typedef unsigned short wchar_t_u;

struct EString2_OPF {
    wchar_t_u *m_str;
    EString2_OPF(wchar_t_u *s1, wchar_t_u *s2);
};

EString2_OPF operator+(wchar_t_u c, EString2_OPF& s) {
    wchar_t_u tmp[2];
    tmp[0] = c;
    tmp[1] = 0;
    return EString2_OPF(tmp, s.m_str);
}
