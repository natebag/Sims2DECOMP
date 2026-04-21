// 0x8033A530 (60B) ENgcRC::EnableRasterModes(unsigned int, int)
// 2-byte-header EDLEntry { cmd, arg2, pad[2], data } dispatched to renderer singleton.

struct EDLEntry2 {
    char cmd;
    char arg2;
    char pad[2];
    unsigned int data;
};

class ENgcRenderer {
public:
    void EnableRasterModes(EDLEntry2* e);
};

extern char s_renderer[];

class ENgcRC {
public:
    void EnableRasterModes(unsigned int modes, int arg2);
};

void ENgcRC::EnableRasterModes(unsigned int modes, int arg2) {
    EDLEntry2 e;
    e.cmd = 21;
    e.arg2 = (char)arg2;
    e.data = modes;
    ((ENgcRenderer*)s_renderer)->EnableRasterModes(&e);
}
