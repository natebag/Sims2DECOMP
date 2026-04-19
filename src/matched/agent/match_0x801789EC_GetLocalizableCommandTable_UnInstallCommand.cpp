// 0x801789EC (120B) GetLocalizableCommandTable::UnInstallCommand(Functor*)
// Walk list, match by pointer or via compare, uninstall first match. Return 1 if found, 0 else.

extern int FunctorCmpGL(void*, void*);

struct GLCTEntry {
    void* unk0;
    GLCTEntry* next;
    void* cmd;
};

class GetLocalizableCommandTable {
public:
    GLCTEntry* head;
    int UnInstallCommand(void*);
    void UnInstall(GLCTEntry*);
};

int GetLocalizableCommandTable::UnInstallCommand(void* cmd) {
    GLCTEntry* e = head;
    if (e) {
        do {
            if (e->cmd == cmd || FunctorCmpGL(e->cmd, cmd) == 0) {
                UnInstall(e);
                return 1;
            }
            e = e->next;
        } while (e);
    }
    return 0;
}
