// 0x8009BF2C (48B) localConvertFromWide(char*, wchar_t*)
// Wide-to-ASCII: copy low byte of each wchar, zero terminator.

void localConvertFromWide(char* dst, unsigned short* src) {
    while (*src) {
        *dst++ = (char)*src;
        ++src;
    }
    *dst = 0;
}
