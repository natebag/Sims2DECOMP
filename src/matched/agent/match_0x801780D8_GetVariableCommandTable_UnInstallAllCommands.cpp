// 0x801780D8 (96B) GetVariableCommandTable::UnInstallAllCommands(Functor*)
// Walk list, uninstall all entries whose cmdPtr matches. Return 1 if any found.

struct GVCTEntryA {
    void* unk0;
    GVCTEntryA* next;
    void* unk8;
    void* cmdPtr;
};

class GetVariableCommandTable2 {
public:
    GVCTEntryA* head;
    int UnInstallAllCommands(void*);
    void UnInstallCommand(GVCTEntryA*);
};

int GetVariableCommandTable2::UnInstallAllCommands(void* cmd) {
    int result = 0;
    GVCTEntryA* e = head;
    if (e) {
        do {
            void* cmdPtr = e->cmdPtr;
            GVCTEntryA* next = e->next;
            if (cmdPtr == cmd) {
                UnInstallCommand(e);
                result = 1;
            }
            e = next;
        } while (e);
    }
    return result;
}
