// 0x8017A958 (84B) UIDrawTable::UnInstallEntry(CBFunctor1<ERC *>&)
// Walk entry list, compare entry->field12 against &functor, UnInstall + return 1 on match, else 0.

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
    int UnInstallEntry(CBFunctor1& functor);
    int UnInstall(DTEntry* e);
};

int UIDrawTable::UnInstallEntry(CBFunctor1& functor) {
    DTEntry* e = head;
    if (e) {
        do {
            void* field12 = e->field12;
            DTEntry* next = e->next;
            if (field12 == &functor) {
                UnInstall(e);
                return 1;
            }
            e = next;
        } while (e);
    }
    return 0;
}
