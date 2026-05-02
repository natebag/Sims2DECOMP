/* EString2::SetToError(void) @ 0x802D4198 (16 bytes) */

typedef unsigned short wchar_t_u;

extern char _estring2Error[];

struct EString2_STE {
    wchar_t_u *m_str;
    void SetToError();
};

void EString2_STE::SetToError() {
    m_str = (wchar_t_u*)_estring2Error;
}
