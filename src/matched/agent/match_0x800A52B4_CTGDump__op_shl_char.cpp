// CTGDump::operator<<(char) at 0x800A52B4 (68B)

extern int Sprintf(char* dest, const char* fmt, ...);

struct CTGDump_char {
    CTGDump_char& operator<<(char n);
};

CTGDump_char& CTGDump_char::operator<<(char n) {
    char buf[64];
    Sprintf(buf, "%d", n);
    return *this;
}
