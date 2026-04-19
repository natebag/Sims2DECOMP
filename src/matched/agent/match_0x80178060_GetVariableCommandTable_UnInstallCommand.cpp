// 0x80178060 (120B) GetVariableCommandTable::UnInstallCommand(Functor*)
// Walk list, match by pointer or via compare, uninstall first match. Return 1 if found, 0 else.

extern int FunctorCmpGV(void*, void*);

struct GVCTEntry {
    void* unk0;
    GVCTEntry* next;
    void* cmd;
};

class GetVariableCommandTable {
public:
    GVCTEntry* head;
    int UnInstallCommand(void*);
    void UnInstall(GVCTEntry*);
};

int GetVariableCommandTable::UnInstallCommand(void* cmd) {
    GVCTEntry* e = head;
    if (e) {
        do {
            if (e->cmd == cmd || FunctorCmpGV(e->cmd, cmd) == 0) {
                UnInstall(e);
                return 1;
            }
            e = e->next;
        } while (e);
    }
    return 0;
}
