// 0x80182174 (92B) UIUserDrawCBTable::FindEntry(char*)
// Walk list; break on entry->field8 == name OR strcmp(field8, name) == 0; return entry or null.

extern "C" int strcmp(const char*, const char*);

struct UDEntry {
    UDEntry* prev;
    UDEntry* next;
    char* field8;
};

class UIUserDrawCBTable {
public:
    UDEntry* head;
    UDEntry* FindEntry(char* name);
};

UDEntry* UIUserDrawCBTable::FindEntry(char* name) {
    UDEntry* e;
    for (e = this->head; e != 0; e = e->next) {
        char* f8 = e->field8;
        if (f8 == name) break;
        if (strcmp(f8, name) == 0) break;
    }
    return e;
}
