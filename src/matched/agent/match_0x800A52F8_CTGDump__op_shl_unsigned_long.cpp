// CTGDump::operator<<(unsigned long) at 0x800A52F8 (68B)

extern int Sprintf(char* dest, const char* fmt, ...);

struct CTGDump_ulong {
    CTGDump_ulong& operator<<(unsigned long n);
};

CTGDump_ulong& CTGDump_ulong::operator<<(unsigned long n) {
    char buf[64];
    Sprintf(buf, "%lu", n);
    return *this;
}
