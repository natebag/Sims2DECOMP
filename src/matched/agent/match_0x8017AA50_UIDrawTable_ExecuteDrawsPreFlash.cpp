// 0x8017AA50 (100B) UIDrawTable::ExecuteDrawsPreFlash(ERC*)
// Walk entries; if field8 > 50, invoke functor(erc) via mtlr/blrl (no null check).

struct ERC;

class CBFunctor1 {
public:
    char pad[12];
    void (*fn)(CBFunctor1*, ERC*);
};

struct DTEntry {
    DTEntry* prev;
    DTEntry* next;
    int field8;
    CBFunctor1* field12;
};

class UIDrawTable {
public:
    DTEntry* head;
    void ExecuteDrawsPreFlash(ERC* erc);
};

void UIDrawTable::ExecuteDrawsPreFlash(ERC* erc) {
    DTEntry* e = this->head;
    if (e != 0) {
        do {
            int pri = e->field8;
            DTEntry* next = e->next;
            if (pri > 50) {
                CBFunctor1* f = e->field12;
                f->fn(f, erc);
            }
            e = next;
        } while (e != 0);
    }
}
