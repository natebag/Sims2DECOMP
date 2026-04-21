// 0x8033AEC8 (64B) ENgcRC::Stencil(int, int, int)
// EDLEntry { 4 bytes header } — cmd=65, three byte args, no int data.

struct EDLEntry4B {
    char cmd;
    char b1;
    char b2;
    char b3;
};

class ENgcRenderer {
public:
    void Stencil(EDLEntry4B* e);
};

extern char s_renderer[];

class ENgcRC {
public:
    void Stencil(int a, int b, int c);
};

void ENgcRC::Stencil(int a, int b, int c) {
    EDLEntry4B e;
    e.cmd = 65;
    e.b1 = (char)a;
    e.b2 = (char)b;
    e.b3 = (char)c;
    ((ENgcRenderer*)s_renderer)->Stencil(&e);
}
