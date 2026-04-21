// 0x8033A5AC (60B) ENgcRC::SetRasterModes(unsigned int, int)
// 2-byte-header EDLEntry { cmd=23, arg2, pad[2], data } dispatched to renderer singleton.

struct EDLEntry2 {
    char cmd;
    char arg2;
    char pad[2];
    unsigned int data;
};

class ENgcRenderer {
public:
    void SetRasterModes(EDLEntry2* e);
};

extern char s_renderer[];

class ENgcRC {
public:
    void SetRasterModes(unsigned int modes, int arg2);
};

void ENgcRC::SetRasterModes(unsigned int modes, int arg2) {
    EDLEntry2 e;
    e.cmd = 23;
    e.arg2 = (char)arg2;
    e.data = modes;
    ((ENgcRenderer*)s_renderer)->SetRasterModes(&e);
}
