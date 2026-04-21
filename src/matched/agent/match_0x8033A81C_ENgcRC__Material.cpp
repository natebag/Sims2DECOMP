// 0x8033A81C (56B) ENgcRC::Material(EMaterial *)
// EDLEntry { cmd=35, data=material_ptr } dispatched to renderer singleton.

struct EDLEntry {
    char cmd;
    char pad[3];
    void* data;
};

class EMaterial;

class ENgcRenderer {
public:
    void Material(EDLEntry* e);
};

extern char s_renderer[];

class ENgcRC {
public:
    void Material(EMaterial* m);
};

void ENgcRC::Material(EMaterial* m) {
    EDLEntry e;
    e.cmd = 35;
    e.data = m;
    ((ENgcRenderer*)s_renderer)->Material(&e);
}
