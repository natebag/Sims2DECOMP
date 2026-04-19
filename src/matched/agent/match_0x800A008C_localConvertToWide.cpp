// 0x800A008C (44B) localConvertToWide(wchar_t*, char*)
// ASCII-to-wide: zero-extend each byte to a wchar_t, null-terminate.

void localConvertToWide_a(unsigned short* dst, unsigned char* src) {
    while (*src) {
        *dst++ = (unsigned short)*src;
        ++src;
    }
    *dst = 0;
}
