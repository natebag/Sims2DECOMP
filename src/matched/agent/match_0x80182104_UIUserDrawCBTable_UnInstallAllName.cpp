// 0x80182104 (112B) UIUserDrawCBTable::UnInstallAllName(char*)
// Same list-walk + strcmp + uninstall pattern as UIDrawTable.

extern int strcmp_udcb(char*, char*);

struct UIUDCBEntry {
    void* unk0;
    UIUDCBEntry* next;
    void* unk8;
    void* unkC;
    char* name;
};

class UIUserDrawCBTable {
public:
    UIUDCBEntry* head;
    int UnInstallAllName(char*);
    void UnInstall(UIUDCBEntry*);
};

int UIUserDrawCBTable::UnInstallAllName(char* name) {
    int found = 0;
    UIUDCBEntry* e = head;
    if (e) {
        do {
            UIUDCBEntry* next = e->next;
            if (strcmp_udcb(e->name, name) == 0) {
                UnInstall(e);
                found = 1;
            }
            e = next;
        } while (e);
    }
    return found;
}
