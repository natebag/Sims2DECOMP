// 0x8017AA1C (52B) UIDrawTable::ContainsEntry(CBFunctor1<ERC*>&)
// Walk entry list, return 1 if any entry->field12 == &functor, else 0.

class CBFunctor1 { public: char pad[16]; };

struct DTEntry {
    DTEntry* prev;
    DTEntry* next;
    void* field8;
    void* field12;
};

class UIDrawTable {
public:
    DTEntry* head;
    int ContainsEntry(CBFunctor1& functor);
};

int UIDrawTable::ContainsEntry(CBFunctor1& functor) {
    DTEntry* e = head;
    if (e) {
        for (;;) {
            void* field12 = e->field12;
            DTEntry* next = e->next;
            if (field12 == &functor) return 1;
            e = next;
            if (!e) break;
        }
    }
    return 0;
}
