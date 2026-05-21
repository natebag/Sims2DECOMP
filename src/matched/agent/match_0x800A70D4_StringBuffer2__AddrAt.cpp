// 0x800A70D4 StringBuffer2::AddrAt(int) (84B)

class StringBuffer2 {
public:
    int length() const;
    char* c_str() const;
    char* AddrAt(int idx);
};

char* StringBuffer2::AddrAt(int idx) {
    if (idx < 0) goto fail;
    if (idx >= length()) goto fail;
    {
        char* p = c_str();
        int n = idx + idx;
        return p + n;
    }
fail:
    return 0;
}
