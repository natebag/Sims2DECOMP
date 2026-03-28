struct StringBuffer2 {
    void clear(void);
    void append(unsigned short* str, int len);
    void copy(unsigned short* str);
};

void StringBuffer2::copy(unsigned short* str) {
    clear();
    append(str, -1);
}
