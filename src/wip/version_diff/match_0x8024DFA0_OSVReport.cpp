// OSVReport - Nintendo SDK function
// Wrapper that calls OSReport (0x8036E3E8)

extern "C" void OSReport(const char* fmt, ...);

extern "C" void OSVReport(const char* fmt, ...) {
    OSReport(fmt);
}
