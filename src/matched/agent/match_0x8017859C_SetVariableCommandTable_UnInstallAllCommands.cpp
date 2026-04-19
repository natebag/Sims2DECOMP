// 0x8017859C (96B) SetVariableCommandTable::UnInstallAllCommands(Functor*)
// Walk list, uninstall all entries whose cmdPtr matches. Return 1 if any found.

struct SVCTEntryA {
    void* unk0;
    SVCTEntryA* next;
    void* unk8;
    void* cmdPtr;
};

class SetVariableCommandTable2 {
public:
    SVCTEntryA* head;
    int UnInstallAllCommands(void*);
    void UnInstallCommand(SVCTEntryA*);
};

int SetVariableCommandTable2::UnInstallAllCommands(void* cmd) {
    int result = 0;
    SVCTEntryA* e = head;
    if (e) {
        do {
            void* cmdPtr = e->cmdPtr;
            SVCTEntryA* next = e->next;
            if (cmdPtr == cmd) {
                UnInstallCommand(e);
                result = 1;
            }
            e = next;
        } while (e);
    }
    return result;
}
