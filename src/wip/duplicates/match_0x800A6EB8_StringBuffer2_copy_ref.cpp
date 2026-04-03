struct StringBuffer2ref;

struct StringBuffer2 {
    void clear(void);
    void appendRef(StringBuffer2ref* ref, int len);
    void copy(StringBuffer2ref* ref);
};

void StringBuffer2::copy(StringBuffer2ref* ref) {
    clear();
    appendRef(ref, -1);
}
