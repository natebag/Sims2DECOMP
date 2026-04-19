// 0x80176F30 (96B) UI3D::UnInstallAllEntries(char*)
// Walk linked list; for each entry where entry->name == key, call RemoveEntry; return 1 if any removed.

struct UI3DRecord {
    UI3DRecord* prev;
    UI3DRecord* next;
    char pad[16];
    char* name;
};

struct UI3D {
    UI3DRecord* m_head;
    void RemoveEntry(UI3DRecord*);
    int UnInstallAllEntries(char* key);
};

int UI3D::UnInstallAllEntries(char* key) {
    int result = 0;
    UI3DRecord* entry = m_head;
    while (entry) {
        UI3DRecord* next = entry->next;
        if (entry->name == key) {
            RemoveEntry(entry);
            result = 1;
        }
        entry = next;
    }
    return result;
}
