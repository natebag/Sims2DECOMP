// CTGDump::operator<<(double &) at 0x800A51E8 (68B)

extern int Sprintf(char* dest, const char* fmt, ...);

struct CTGDump_double {
    CTGDump_double& operator<<(double& d);
};

CTGDump_double& CTGDump_double::operator<<(double& d) {
    char buf[64];
    Sprintf(buf, "%g", d);
    return *this;
}
