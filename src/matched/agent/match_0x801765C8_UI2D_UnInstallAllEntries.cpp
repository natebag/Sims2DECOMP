// 0x801765C8 (96B) UI2D::UnInstallAllEntries(char*)
// Walk linked list; for each entry where entry->name == key, call RemoveEntry; return 1 if any removed.

struct UI2DRecord {
    UI2DRecord* prev;
    UI2DRecord* next;
    char pad[12];
    char* name;
};

struct UI2D {
    UI2DRecord* m_head;
    void RemoveEntry(UI2DRecord*);
    int UnInstallAllEntries(char* key);
};

int UI2D::UnInstallAllEntries(char* key) {
    int result = 0;
    UI2DRecord* entry = m_head;
    while (entry) {
        UI2DRecord* next = entry->next;
        if (entry->name == key) {
            RemoveEntry(entry);
            result = 1;
        }
        entry = next;
    }
    return result;
}
