// CTGDump::operator<<(int) at 0x800A522C (68B)

extern int Sprintf(char* dest, const char* fmt, ...);

struct CTGDump_int {
    CTGDump_int& operator<<(int n);
};

CTGDump_int& CTGDump_int::operator<<(int n) {
    char buf[64];
    Sprintf(buf, "%d", n);
    return *this;
}
