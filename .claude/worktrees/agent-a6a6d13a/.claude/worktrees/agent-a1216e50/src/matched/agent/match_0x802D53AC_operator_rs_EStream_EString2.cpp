struct EStream {
    void ReadString(char* buf, int maxLen);
};

struct EString2 {
    void Set(char* str);
};

EStream& operator>>(EStream& s, EString2& str) {
    char buf[8192];
    s.ReadString(buf, 4096);
    str.Set(buf);
    return s;
}
