/* EString2::ConvertToBackslashes(void) @ 0x802D57F0 (48 bytes) */

typedef unsigned short wchar_t_u;

struct EString2_CTB {
    wchar_t_u *m_str;
    void ConvertToBackslashes();
};

void EString2_CTB::ConvertToBackslashes() {
    wchar_t_u *p = m_str;
    while (*p) {
        if (*p == '/') *p = '\\';
        p++;
    }
}
