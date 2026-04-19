// 0x80178524 (120B) SetVariableCommandTable::UnInstallCommand(Functor*)
// Walk list, match by pointer or via compare, uninstall first match. Return 1 if found, 0 else.

extern int FunctorCmpSV(void*, void*);

struct SVCTEntry {
    void* unk0;
    SVCTEntry* next;
    void* cmd;
};

class SetVariableCommandTable {
public:
    SVCTEntry* head;
    int UnInstallCommand(void*);
    void UnInstall(SVCTEntry*);
};

int SetVariableCommandTable::UnInstallCommand(void* cmd) {
    SVCTEntry* e = head;
    if (e) {
        do {
            if (e->cmd == cmd || FunctorCmpSV(e->cmd, cmd) == 0) {
                UnInstall(e);
                return 1;
            }
            e = e->next;
        } while (e);
    }
    return 0;
}
