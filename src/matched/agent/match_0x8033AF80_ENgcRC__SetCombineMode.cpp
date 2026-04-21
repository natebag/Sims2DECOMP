// 0x8033AF80 (60B) ENgcRC::SetCombineMode(int, int)
// EDLEntry layout { cmd byte at 0, halfword at 2, int data at 4 } — sth at offset 10 = struct[2].

struct EDLEntryHW {
    char cmd;
    char pad0;
    unsigned short hword;
    unsigned int data;
};

class ENgcRenderer {
public:
    void SetCombineMode(EDLEntryHW* e);
};

extern char s_renderer[];

class ENgcRC {
public:
    void SetCombineMode(int a, int b);
};

void ENgcRC::SetCombineMode(int a, int b) {
    EDLEntryHW e;
    e.cmd = 51;
    e.hword = (unsigned short)b;
    e.data = (unsigned int)a;
    ((ENgcRenderer*)s_renderer)->SetCombineMode(&e);
}
