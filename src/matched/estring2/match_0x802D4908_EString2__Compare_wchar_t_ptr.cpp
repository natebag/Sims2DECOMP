/* EString2::Compare(unsigned wchar_t *) const @ 0x802D4908 (76 bytes) */

typedef unsigned short wchar_t_u;

struct EString2_CmpW {
    wchar_t_u *m_str;
    int Compare(wchar_t_u *s) const;
};

int EString2_CmpW::Compare(wchar_t_u *s) const {
    wchar_t_u *p = m_str;
    while (true) {
        wchar_t_u mc = *p;
        wchar_t_u sc = *s;
        if (mc < sc) return -1;
        if (mc > sc) return 1;
        wchar_t_u next = *++p;
        ++s;
        if (!next) {
            if (!*s) return 0;
        }
    }
}
