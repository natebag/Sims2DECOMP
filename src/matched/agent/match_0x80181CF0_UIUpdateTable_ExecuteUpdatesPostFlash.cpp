// 0x80181CF0 (92B) UIUpdateTable::ExecuteUpdatesPostFlash()
// Walk entries; if field8 <= 50, invoke functor thunk via mtlr/blrl (no null check).

class CBFunctor0 {
public:
    char pad[12];
    void (*fn)(CBFunctor0*);
};

struct UTEntry {
    UTEntry* prev;
    UTEntry* next;
    int field8;
    CBFunctor0* field12;
};

class UIUpdateTable {
public:
    UTEntry* head;
    void ExecuteUpdatesPostFlash();
};

void UIUpdateTable::ExecuteUpdatesPostFlash() {
    UTEntry* e = this->head;
    if (e != 0) {
        do {
            int pri = e->field8;
            UTEntry* next = e->next;
            if (pri <= 50) {
                CBFunctor0* f = e->field12;
                f->fn(f);
            }
            e = next;
        } while (e != 0);
    }
}
