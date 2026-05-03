/* EString2::Compare(char *) const @ 0x802D4954 (80 bytes) */

typedef unsigned short wchar_t_u;

struct EString2_CmpC {
    wchar_t_u *m_str;
    int Compare(char *s) const;
};

int EString2_CmpC::Compare(char *s) const {
    wchar_t_u *p = m_str;
    while (true) {
        wchar_t_u mc = *p;
        signed char sc = *s;
        if ((int)mc < (int)sc) return -1;
        if ((int)mc > (int)sc) return 1;
        wchar_t_u next = *++p;
        ++s;
        if (!next) {
            if (!*s) return 0;
        }
    }
}
