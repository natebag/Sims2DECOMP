// 0x80181BE8 (112B) UIUpdateTable::UnInstallAllName(char*)
// Same list-walk + strcmp + uninstall pattern as UIDrawTable.

extern int strcmp_ut(char*, char*);

struct UIUpdateEntry {
    void* unk0;
    UIUpdateEntry* next;
    void* unk8;
    void* unkC;
    char* name;
};

class UIUpdateTable {
public:
    UIUpdateEntry* head;
    int UnInstallAllName(char*);
    void UnInstall(UIUpdateEntry*);
};

int UIUpdateTable::UnInstallAllName(char* name) {
    int found = 0;
    UIUpdateEntry* e = head;
    if (e) {
        do {
            UIUpdateEntry* next = e->next;
            if (strcmp_ut(e->name, name) == 0) {
                UnInstall(e);
                found = 1;
            }
            e = next;
        } while (e);
    }
    return found;
}
