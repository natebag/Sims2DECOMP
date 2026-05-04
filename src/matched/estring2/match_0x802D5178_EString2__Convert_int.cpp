/* EString2::Convert(int) @ 0x802D5178 (80 bytes) */

typedef unsigned short wchar_t_u;

extern int Sprintf(char* dest, const char* fmt, ...);

struct EString2_CI {
    wchar_t_u *m_str;
    EString2_CI& operator=(char *s);
    EString2_CI& Convert(int n);
};

EString2_CI& EString2_CI::Convert(int n) {
    char buf[40];
    Sprintf(buf, "%d", n);
    *this = buf;
    return *this;
}
