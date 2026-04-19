// 0x80181B94 (84B) UIUpdateTable::UnInstallEntry(CBFunctor0&)
// Walk entry list, compare entry->field12 against &functor, UnInstall + return 1 on match, else 0.

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
    int UnInstallEntry(CBFunctor0& functor);
    int UnInstall(UTEntry* e);
};

int UIUpdateTable::UnInstallEntry(CBFunctor0& functor) {
    UTEntry* e = head;
    if (e) {
        do {
            void* field12 = e->field12;
            UTEntry* next = e->next;
            if (field12 == &functor) {
                UnInstall(e);
                return 1;
            }
            e = next;
        } while (e);
    }
    return 0;
}
