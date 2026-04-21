// 0x8033A4BC (60B) ENgcRC::DisableGeometryModes(unsigned int)
// Twin of EnableGeometryModes with cmd=19 + bitwise-NOT of mask before dispatch.

struct EDLEntry {
    char cmd;
    char pad[3];
    unsigned int data;
};

class ENgcRenderer {
public:
    void DisableGeometryModes(EDLEntry* e);
};

extern char s_renderer[];

class ENgcRC {
public:
    void DisableGeometryModes(unsigned int modes);
};

void ENgcRC::DisableGeometryModes(unsigned int modes) {
    EDLEntry e;
    e.cmd = 19;
    e.data = ~modes;
    ((ENgcRenderer*)s_renderer)->DisableGeometryModes(&e);
}
