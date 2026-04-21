// 0x8033A4F8 (56B) ENgcRC::SetGeometryModes(unsigned int)
// EDLEntry { cmd=20, data=modes } dispatched to renderer singleton.

struct EDLEntry {
    char cmd;
    char pad[3];
    unsigned int data;
};

class ENgcRenderer {
public:
    void SetGeometryModes(EDLEntry* e);
};

extern char s_renderer[];

class ENgcRC {
public:
    void SetGeometryModes(unsigned int modes);
};

void ENgcRC::SetGeometryModes(unsigned int modes) {
    EDLEntry e;
    e.cmd = 20;
    e.data = modes;
    ((ENgcRenderer*)s_renderer)->SetGeometryModes(&e);
}
