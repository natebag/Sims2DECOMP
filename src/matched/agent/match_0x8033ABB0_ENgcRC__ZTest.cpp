// 0x8033ABB0 (68B) ENgcRC::ZTest(bool, int, int, int)
// EDLEntry { 4 bytes header + int data } — cmd=43, three byte args + int.

struct EDLEntry4B {
    char cmd;
    char b1;
    char b2;
    char b3;
    unsigned int data;
};

class ENgcRenderer {
public:
    void ZTest(EDLEntry4B* e);
};

extern char s_renderer[];

class ENgcRC {
public:
    void ZTest(bool a, int b, int c, int d);
};

void ENgcRC::ZTest(bool a, int b, int c, int d) {
    EDLEntry4B e;
    e.cmd = 43;
    e.b1 = (char)a;
    e.b2 = (char)b;
    e.b3 = (char)c;
    e.data = (unsigned int)d;
    ((ENgcRenderer*)s_renderer)->ZTest(&e);
}
