// 0x80177EE8 (100B) GetVariableCommandTable::AddRecord(char* name, Functor* cmd)
// Pop from freelist, link at tail of doubly-linked list, store payload.
// Leaf function (no stack frame).

struct GVAEntry {
    GVAEntry* prev;
    GVAEntry* next;
    char* name;
    void* cmd;
};

class GetVariableCommandTable3 {
public:
    GVAEntry* head;
    GVAEntry* tail;
    GVAEntry* freelist;
    void AddRecord(char*, void*);
};

void GetVariableCommandTable3::AddRecord(char* name, void* cmd) {
    GVAEntry* newEntry = freelist;
    GVAEntry* newFreelistHead = newEntry->next;
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
