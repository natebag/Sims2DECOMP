// 0x80178A64 (96B) GetLocalizableCommandTable::UnInstallAllCommands(Functor*)
// Walk list, uninstall all entries whose cmdPtr matches. Return 1 if any found.

struct GLCTEntryA {
    void* unk0;
    GLCTEntryA* next;
    void* unk8;
    void* cmdPtr;
};

class GetLocalizableCommandTable2 {
public:
    GLCTEntryA* head;
    int UnInstallAllCommands(void*);
    void UnInstallCommand(GLCTEntryA*);
};

int GetLocalizableCommandTable2::UnInstallAllCommands(void* cmd) {
    int result = 0;
    GLCTEntryA* e = head;
    if (e) {
        do {
            void* cmdPtr = e->cmdPtr;
            GLCTEntryA* next = e->next;
            if (cmdPtr == cmd) {
                UnInstallCommand(e);
                result = 1;
            }
            e = next;
        } while (e);
    }
    return result;
}
