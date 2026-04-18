// 0x80177554 (96B) UIAUDIO::ContainsEntry(char *)
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
    int ContainsEntry(char* name);
};

int UIAUDIO::ContainsEntry(char* name) {
    UIAUDIORecord* entry = m_head;
    while (entry) {
        if (strcmp(entry->name, name) == 0) {
            return 1;
        }
        entry = entry->next;
    }
    return 0;
}
