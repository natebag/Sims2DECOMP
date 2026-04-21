// 0x8033A6B0 (56B) ENgcRC::ViewMatrix(EMat4 *, int, float)
// EDLEntry { cmd=13, data=mat_ptr } dispatched to renderer singleton.
// Extra int/float args are dropped — only the pointer goes into the entry.

struct EDLEntry {
    char cmd;
    char pad[3];
    void* data;
};

class EMat4;

class ENgcRenderer {
public:
    void ViewMatrix(EDLEntry* e);
};

extern char s_renderer[];

class ENgcRC {
public:
    void ViewMatrix(EMat4* m, int, float);
};

void ENgcRC::ViewMatrix(EMat4* m, int, float) {
    EDLEntry e;
    e.cmd = 13;
    e.data = m;
    ((ENgcRenderer*)s_renderer)->ViewMatrix(&e);
}
