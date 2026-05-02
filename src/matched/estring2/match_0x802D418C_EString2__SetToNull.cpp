/* EString2::SetToNull(void) @ 0x802D418C (12 bytes) */

typedef unsigned short wchar_t_u;

extern char _estring2Null[2];

struct EString2_STN {
    wchar_t_u *m_str;
    void SetToNull();
};

void EString2_STN::SetToNull() {
    m_str = (wchar_t_u*)_estring2Null;
}
