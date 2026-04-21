// 0x8033A6E8 (56B) ENgcRC::ProjectionMatrix(EMat4 *)
// EDLEntry { cmd=14, data=mat_ptr } dispatched to renderer singleton.

struct EDLEntry {
    char cmd;
    char pad[3];
    void* data;
};

class EMat4;

class ENgcRenderer {
public:
    void ProjectionMatrix(EDLEntry* e);
};

extern char s_renderer[];

class ENgcRC {
public:
    void ProjectionMatrix(EMat4* m);
};

void ENgcRC::ProjectionMatrix(EMat4* m) {
    EDLEntry e;
    e.cmd = 14;
    e.data = m;
    ((ENgcRenderer*)s_renderer)->ProjectionMatrix(&e);
}
