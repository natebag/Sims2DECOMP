/* EString2::Replace(wchar_t, wchar_t) @ 0x802D51C8 (44 bytes) */

typedef unsigned short wchar_t_u;

struct EString2_Rep {
    wchar_t_u *m_str;
    void Replace(wchar_t_u from, wchar_t_u to);
};

void EString2_Rep::Replace(wchar_t_u from, wchar_t_u to) {
    wchar_t_u *p = m_str;
    while (*p) {
        if (*p == from) *p = to;
        p++;
    }
}
