// 0x8033A720 (56B) ENgcRC::WindowMatrix(EMat4 *)
// EDLEntry { cmd=15, data=mat_ptr } dispatched to renderer singleton.

struct EDLEntry {
    char cmd;
    char pad[3];
    void* data;
};

class EMat4;

class ENgcRenderer {
public:
    void WindowMatrix(EDLEntry* e);
};

extern char s_renderer[];

class ENgcRC {
public:
    void WindowMatrix(EMat4* m);
};

void ENgcRC::WindowMatrix(EMat4* m) {
    EDLEntry e;
    e.cmd = 15;
    e.data = m;
    ((ENgcRenderer*)s_renderer)->WindowMatrix(&e);
}
