/* EString2::Convert(float) @ 0x802D512C (76 bytes) */

typedef unsigned short wchar_t_u;

extern int Sprintf(char* dest, const char* fmt, ...);

struct EString2_CF {
    wchar_t_u *m_str;
    EString2_CF& operator=(char *s);
    EString2_CF& Convert(float f);
};

EString2_CF& EString2_CF::Convert(float f) {
    char buf[40];
    Sprintf(buf, "%g", f);
    *this = buf;
    return *this;
}
