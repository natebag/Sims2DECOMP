// 0x800A69E4 StringBuffer::appendChar(char) (48B)
struct StringBuffer;

extern void StringBuffer__append(StringBuffer* self, char* s, int n);

void StringBuffer__appendChar(StringBuffer* self, char c) {
    char buf[2];
    buf[0] = c;
    buf[1] = 0;
    StringBuffer__append(self, buf, -1);
}
