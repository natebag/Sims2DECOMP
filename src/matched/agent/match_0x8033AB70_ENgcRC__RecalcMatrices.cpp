// 0x8033AB70 (60B) ENgcRC::RecalcMatrices(int, int)
// EDLEntry with 3 byte header (cmd, b1, b2), no int data — cmd=37.

struct EDLEntry3B {
    char cmd;
    char b1;
    char b2;
};

class ENgcRenderer {
public:
    void RecalcMatrices(EDLEntry3B* e);
};

extern char s_renderer[];

class ENgcRC {
public:
    void RecalcMatrices(int a, int b);
};

void ENgcRC::RecalcMatrices(int a, int b) {
    EDLEntry3B e;
    e.cmd = 37;
    e.b1 = (char)a;
    e.b2 = (char)b;
    ((ENgcRenderer*)s_renderer)->RecalcMatrices(&e);
}
