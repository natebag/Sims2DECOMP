// 0x8017747C (120B) UIAUDIO::UnInstallEntry(char *)
extern "C" int strcmp(const char*, const char*);

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
    int UnInstallEntry(char* name);
};

int UIAUDIO::UnInstallEntry(char* name) {
    UIAUDIORecord* entry = m_head;
    while (entry) {
        char* entryName = entry->name;
        if (entryName == name || strcmp(entryName, name) == 0) {
            RemoveEntry(entry);
            return 1;
        }
        entry = entry->next;
    }
    return 0;
}
