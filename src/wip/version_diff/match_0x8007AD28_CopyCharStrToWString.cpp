// VERSION_DIFF: register allocation and loop structure differ
// C++ logic is correct - char to wchar copy loop
// 0x8007AD28 (80 bytes)
/* CopyCharStrToWString(char *, unsigned wchar_t *, unsigned int) */

void CopyCharStrToWString(char* src, unsigned short* dst, unsigned int maxLen) {
    int i = 0;
    char c = *src;
    if (c != 0) {
        maxLen--;
        while (i <= maxLen) {
            dst[0] = (unsigned short)c;
            i++;
            src++;
            c = *src;
            if (c == 0) break;
        }
    }
    dst[0] = 0;
}
