// 0x801D92D0 PRGTarget::FormatFraction(unsigned wchar_t*, int, int) (96B)

extern int Sprintf(char* buf, char* fmt, ...);
extern int strlen(char* s);
extern int UTF8ToUCS2(char* src, int n, unsigned short* dst);

extern char s_fractionFmt[];  // 0x803F4BC8 — "%d/%d" or similar

class PRGTarget {
public:
    void FormatFraction(unsigned short* dst, int num, int den);
};

void PRGTarget::FormatFraction(unsigned short* dst, int num, int den) {
    if (num > den) num = den;
    char buf[16];
    Sprintf(buf, s_fractionFmt, num, den);
    int len = strlen(buf);
    UTF8ToUCS2(buf, len + 1, dst);
}
