class INVTarget {
public:
    int GetMaxWCharBufSize(unsigned short* str);
};

int INVTarget::GetMaxWCharBufSize(unsigned short* str) {
    int len = 0;
    while (*str != 0) {
        str++;
        len++;
    }
    return (len + 2) * 4;
}
