// 0x80181C58 (52B) UIUpdateTable::ContainsEntry(CBFunctor0&)
// Walk entry list, return 1 if any entry->field12 == &functor, else 0.

class CBFunctor0 { public: char pad[16]; };

struct UTEntry {
    UTEntry* prev;
    UTEntry* next;
    void* field8;
    void* field12;
};

class UIUpdateTable {
public:
    UTEntry* head;
    int ContainsEntry(CBFunctor0& functor);
};

int UIUpdateTable::ContainsEntry(CBFunctor0& functor) {
    UTEntry* e = head;
    if (e) {
        for (;;) {
            void* field12 = e->field12;
            UTEntry* next = e->next;
            if (field12 == &functor) return 1;
            e = next;
            if (!e) break;
        }
    }
    return 0;
}
