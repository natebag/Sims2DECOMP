struct StringBuffer {
    void clear(void);
    void append(char* str, int len);
    void copy(char* str);
};

void StringBuffer::copy(char* str) {
    clear();
    append(str, -1);
}
