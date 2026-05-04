// CTGDump::operator<<(unsigned int) at 0x800A5270 (68B)

extern int Sprintf(char* dest, const char* fmt, ...);

struct CTGDump_uint {
    CTGDump_uint& operator<<(unsigned int n);
};

CTGDump_uint& CTGDump_uint::operator<<(unsigned int n) {
    char buf[64];
    Sprintf(buf, "%u", n);
    return *this;
}
