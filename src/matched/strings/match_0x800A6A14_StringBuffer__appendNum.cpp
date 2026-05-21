// 0x800A6A14 StringBuffer::appendNum(int) (80B)

extern int Sprintf(char* buf, char* fmt, ...);

class StringBuffer {
public:
    int append(char* s, int n);
    int appendNum(int n);
};

extern char s_intFmt[];  // 0x803D90B4

int StringBuffer::appendNum(int n) {
    char buf[32];
    Sprintf(buf, s_intFmt, n);
    return append(buf, -1);
}
