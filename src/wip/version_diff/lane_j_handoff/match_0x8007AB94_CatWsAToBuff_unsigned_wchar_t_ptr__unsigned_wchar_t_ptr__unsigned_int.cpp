// 0x8007AB94 (128B) CatWsAToBuff(unsigned wchar_t*, unsigned wchar_t*, unsigned int)
// Wide-char strcat with length limit. Returns chars copied.

extern "C" {
    unsigned int CatWsAToBuff(const unsigned short* src, unsigned short* dst, unsigned int maxLen) {
        unsigned short* appendPos = dst;
        unsigned int totalLen = 0;
        
        while (*appendPos) {
            appendPos++;
            totalLen++;
        }
        
        unsigned int copied = 0;
        unsigned short ch = *src;
        while (ch && totalLen < maxLen - 1) {
            *appendPos++ = ch;
            totalLen++;
            copied++;
            ch = *++src;
        }
        
        *appendPos = 0;
        return copied;
    }
}
