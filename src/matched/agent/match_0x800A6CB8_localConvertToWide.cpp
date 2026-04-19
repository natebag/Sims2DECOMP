// 0x800A6CB8 (44B) localConvertToWide(wchar_t*, char*)
// ASCII-to-wide: zero-extend each byte to a wchar_t, null-terminate.

void localConvertToWide_b(unsigned short* dst, unsigned char* src) {
    while (*src) {
        *dst++ = (unsigned short)*src;
        ++src;
    }
    *dst = 0;
}
