/* EString2::ConvertToForwardslashes(void) @ 0x802D5820 (48 bytes) */

typedef unsigned short wchar_t_u;

struct EString2_CTF {
    wchar_t_u *m_str;
    void ConvertToForwardslashes();
};

void EString2_CTF::ConvertToForwardslashes() {
    wchar_t_u *p = m_str;
    while (*p) {
        if (*p == '\\') *p = '/';
        p++;
    }
}
