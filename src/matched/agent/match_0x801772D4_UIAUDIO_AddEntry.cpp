// 0x801772D4 (104B) UIAUDIO::AddEntry(char *, unsigned int, char *)
struct UIAUDIORecord {
    UIAUDIORecord* prev;
    UIAUDIORecord* next;
    char* name;
    unsigned int code;
    char* key;
};

struct UIAUDIO {
    UIAUDIORecord* m_head;
    UIAUDIORecord* m_tail;
    UIAUDIORecord* m_freelist;
    void AddEntry(char* name, unsigned int code, char* key);
};

void UIAUDIO::AddEntry(char* name, unsigned int code, char* key) {
    UIAUDIORecord* rec = m_freelist;
    m_freelist = rec->next;
    if (m_freelist) {
        m_freelist->prev = 0;
    }
    if (m_head == 0) {
        m_head = rec;
        rec->prev = 0;
        m_tail = rec;
        rec->next = 0;
    } else {
        UIAUDIORecord* tail = m_tail;
        tail->next = rec;
        rec->prev = m_tail;
        m_tail = rec;
        rec->next = 0;
    }
    rec->name = name;
    rec->code = code;
    rec->key = key;
}
