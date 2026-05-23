// 0x801f1228 INVTarget::GetMaxWCharBufSize(unsigned wchar_t *) (44B)

struct INVTarget {
    int GetMaxWCharBufSize(unsigned short* str);
};

int INVTarget::GetMaxWCharBufSize(unsigned short* str) {
    int len = 0;
    unsigned short* p = str;
    if (*p) {
        do {
            p++;
            len++;
        } while (*p);
    }
    return (len + 2) * 4;
}
