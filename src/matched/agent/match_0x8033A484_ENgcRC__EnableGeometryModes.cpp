// 0x8033A484 (56B) ENgcRC::EnableGeometryModes(unsigned int)
// Build EDLEntry { cmd=18, data=modes } on the stack, dispatch to renderer singleton.

struct EDLEntry {
    char cmd;
    char pad[3];
    unsigned int data;
};

class ENgcRenderer {
public:
    void EnableGeometryModes(EDLEntry* e);
};

extern char s_renderer[];  // singleton at 0x804D54B8

class ENgcRC {
public:
    void EnableGeometryModes(unsigned int modes);
};

void ENgcRC::EnableGeometryModes(unsigned int modes) {
    EDLEntry e;
    e.cmd = 18;
    e.data = modes;
    ((ENgcRenderer*)s_renderer)->EnableGeometryModes(&e);
}
