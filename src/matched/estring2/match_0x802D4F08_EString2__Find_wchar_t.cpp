/* EString2::Find(wchar_t) const @ 0x802D4F08 (60 bytes) */

typedef unsigned short wchar_t_u;

struct EString2_Fi {
    wchar_t_u *m_str;
    int Find(wchar_t_u c) const;
};

int EString2_Fi::Find(wchar_t_u c) const {
    wchar_t_u *p = m_str;
    int i = 0;
    wchar_t_u cur = *p;
    if (cur) {
        do {
            if (cur == c) return i;
            cur = *++p;
            i++;
        } while (cur);
    }
    return -1;
}
