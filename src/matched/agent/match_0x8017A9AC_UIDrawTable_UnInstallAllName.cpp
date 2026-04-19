// 0x8017A9AC (112B) UIDrawTable::UnInstallAllName(char*)
// Walk linked list, strcmp each entry's name, uninstall matches. Return found flag.

extern int strcmp_dt(char*, char*);

struct UIDrawEntry {
    void* unk0;
    UIDrawEntry* next;
    void* unk8;
    void* unkC;
    char* name;
};

class UIDrawTable {
public:
    UIDrawEntry* head;
    int UnInstallAllName(char*);
    void UnInstall(UIDrawEntry*);
};

int UIDrawTable::UnInstallAllName(char* name) {
    int found = 0;
    UIDrawEntry* e = head;
    if (e) {
        do {
            UIDrawEntry* next = e->next;
            if (strcmp_dt(e->name, name) == 0) {
                UnInstall(e);
                found = 1;
            }
            e = next;
        } while (e);
    }
    return found;
}
