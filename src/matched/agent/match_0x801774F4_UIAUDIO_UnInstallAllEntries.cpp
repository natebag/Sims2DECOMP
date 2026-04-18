// 0x801774F4 (96B) UIAUDIO::UnInstallAllEntries(char *)
struct UIAUDIORecord {
    UIAUDIORecord* prev;
    UIAUDIORecord* next;
    char* name;
    unsigned int code;
    char* key;
};

struct UIAUDIO {
    UIAUDIORecord* m_head;
    void RemoveEntry(UIAUDIORecord*);
    int UnInstallAllEntries(char* key);
};

int UIAUDIO::UnInstallAllEntries(char* key) {
    int result = 0;
    UIAUDIORecord* entry = m_head;
    while (entry) {
        UIAUDIORecord* next = entry->next;
        if (entry->key == key) {
            RemoveEntry(entry);
            result = 1;
        }
        entry = next;
    }
    return result;
}
