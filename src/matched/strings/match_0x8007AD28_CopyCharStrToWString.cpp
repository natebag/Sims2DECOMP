// 0x8007AD28 CopyCharStrToWString(char*, unsigned wchar_t*, unsigned int) (80B)
// TRIAGE

int CopyCharStrToWString(char* src, unsigned short* dst, unsigned int maxLen) {
    char* p = src;
    unsigned char ch = (unsigned char)*p;
    int count = 0;
    if (ch == 0) goto end;
    maxLen--;
    if ((unsigned int)count >= maxLen) goto end;
    while (1) {
        signed short v = (signed char)ch;
        count++;
        *dst = (unsigned short)v;
        dst++;
        ch = (unsigned char)*(++p);
        if (ch == 0) goto end;
        if ((unsigned int)count >= maxLen) goto end;
    }
end:
    *dst = 0;
    return count;
}
