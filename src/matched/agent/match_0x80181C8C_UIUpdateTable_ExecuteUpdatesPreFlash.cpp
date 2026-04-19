// 0x80181C8C (100B) UIUpdateTable::ExecuteUpdatesPreFlash()
// Walk entries; if field8 > 50 and functor ptr not null, invoke functor thunk via mtlr/blrl.

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
    void ExecuteUpdatesPreFlash();
};

void UIUpdateTable::ExecuteUpdatesPreFlash() {
    UTEntry* e = this->head;
    if (e != 0) {
        do {
            int pri = e->field8;
            UTEntry* next = e->next;
            if (pri > 50) {
                CBFunctor0* f = e->field12;
                if (f != 0) {
                    f->fn(f);
                }
            }
            e = next;
        } while (e != 0);
    }
}
