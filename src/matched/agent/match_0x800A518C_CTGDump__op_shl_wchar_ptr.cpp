// CTGDump::operator<<(unsigned wchar_t *) at 0x800A518C (92B)

typedef unsigned short wchar_t_u;

extern unsigned int wcslen(wchar_t_u*);
extern void localConvertToASCII(char*, wchar_t_u*);

struct CTGDump_wchar {
    CTGDump_wchar& operator<<(wchar_t_u* wstr);
};

CTGDump_wchar& CTGDump_wchar::operator<<(wchar_t_u* wstr) {
    char* buf = new char[wcslen(wstr) + 1];
    localConvertToASCII(buf, wstr);
    delete[] buf;
    return *this;
}
