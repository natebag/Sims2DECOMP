// 0x801783AC (100B) SetVariableCommandTable::AddRecord(char* name, Functor* cmd)
// Pop from freelist, link at tail of doubly-linked list, store payload.

struct SVAEntry {
    SVAEntry* prev;
    SVAEntry* next;
    char* name;
    void* cmd;
};

class SetVariableCommandTable3 {
public:
    SVAEntry* head;
    SVAEntry* tail;
    SVAEntry* freelist;
    void AddRecord(char*, void*);
};

void SetVariableCommandTable3::AddRecord(char* name, void* cmd) {
    SVAEntry* newEntry = freelist;
    SVAEntry* newFreelistHead = newEntry->next;
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
