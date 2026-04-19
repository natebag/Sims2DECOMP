// FLAGS: -fno-schedule-insns
// 0x8017A860 (156 bytes)
// UIDrawTable::RemoveRecord(UIDrawTable::DrawTableRecord *)

struct DrawTableRecord {
    DrawTableRecord* prev;   // offset 0
    DrawTableRecord* next;   // offset 4
    int priority;            // offset 8
    void* functor;           // offset 12
    char* name;              // offset 16
};

class UIDrawTable_RR {
public:
    DrawTableRecord* head;     // offset 0
    DrawTableRecord* tail;     // offset 4
    DrawTableRecord* freelist; // offset 8
    void RemoveRecord(DrawTableRecord* rec);
};

void UIDrawTable_RR::RemoveRecord(DrawTableRecord* rec) {
    DrawTableRecord* p = rec->prev;
    if (p) {
        p->next = rec->next;
    }
    DrawTableRecord* n = rec->next;
    if (n) {
        n->prev = rec->prev;
    }

    if (head == rec) {
        head = rec->next;
    }
    if (tail == rec) {
        tail = rec->prev;
    }

    rec->next = 0;
    rec->prev = 0;

    DrawTableRecord* fl = freelist;
    if (fl) {
        rec->next = fl;
        freelist->prev = rec;
    }
    freelist = rec;

    freelist->priority = 75;
    freelist->functor = 0;
    freelist->name = 0;
}
