struct StringBuffer2;

struct StringBuffer {
    void clear(void);
    void appendRef(StringBuffer2* ref, int len);
    void copy(StringBuffer2* ref);
};

void StringBuffer::copy(StringBuffer2* ref) {
    clear();
    appendRef(ref, -1);
}
