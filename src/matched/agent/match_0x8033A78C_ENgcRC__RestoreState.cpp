// 0x8033A78C (52B) ENgcRC::RestoreState(void)
// Twin of SaveState with cmd=29.

struct EDLEntry {
    char cmd;
    char pad[3];
    unsigned int data;
};

class ENgcRenderer {
public:
    void RestoreState(EDLEntry* e);
};

extern char s_renderer[];

class ENgcRC {
public:
    void RestoreState();
};

void ENgcRC::RestoreState() {
    EDLEntry e;
    e.cmd = 29;
    ((ENgcRenderer*)s_renderer)->RestoreState(&e);
}
