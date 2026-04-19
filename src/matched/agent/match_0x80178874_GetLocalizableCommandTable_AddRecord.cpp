// 0x80178874 (100B) GetLocalizableCommandTable::AddRecord(char* name, Functor* cmd)
// Pop from freelist, link at tail of doubly-linked list, store payload.

struct GLAEntry {
    GLAEntry* prev;
    GLAEntry* next;
    char* name;
    void* cmd;
};

class GetLocalizableCommandTable3 {
public:
    GLAEntry* head;
    GLAEntry* tail;
    GLAEntry* freelist;
    void AddRecord(char*, void*);
};

void GetLocalizableCommandTable3::AddRecord(char* name, void* cmd) {
    GLAEntry* newEntry = freelist;
    GLAEntry* newFreelistHead = newEntry->next;
    freelist = newFreelistHead;
    if (newFreelistHead) {
        newFreelistHead->prev = 0;
    }
    if (head == 0) {
        head = newEntry;
        newEntry->prev = 0;
        tail = newEntry;
        newEntry->next = 0;
    } else {
        tail->next = newEntry;
        newEntry->prev = tail;
        tail = newEntry;
        newEntry->next = 0;
    }
    newEntry->name = name;
    newEntry->cmd = cmd;
}
