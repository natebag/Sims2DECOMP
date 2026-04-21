// 0x8033A758 (52B) ENgcRC::SaveState(void)
// EDLEntry { cmd=28 } — no payload — dispatched to renderer singleton.

struct EDLEntry {
    char cmd;
    char pad[3];
    unsigned int data;
};

class ENgcRenderer {
public:
    void SaveState(EDLEntry* e);
};

extern char s_renderer[];

class ENgcRC {
public:
    void SaveState();
};

void ENgcRC::SaveState() {
    EDLEntry e;
    e.cmd = 28;
    ((ENgcRenderer*)s_renderer)->SaveState(&e);
}
