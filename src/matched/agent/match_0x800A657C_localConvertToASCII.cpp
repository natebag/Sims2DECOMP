// 0x800A657C (48B) localConvertToASCII(char*, wchar_t*)
// Wide-to-ASCII: copy low byte of each wchar, zero terminator.

void localConvertToASCII_b(char* dst, unsigned short* src) {
    while (*src) {
        *dst++ = (char)*src;
        ++src;
    }
    *dst = 0;
}
