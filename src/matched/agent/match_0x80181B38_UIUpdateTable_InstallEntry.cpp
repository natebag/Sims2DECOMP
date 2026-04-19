// 0x80181B38 (92B) UIUpdateTable::InstallEntry(UpdateTablePriority, CBFunctor0&, char*)
// If initialized, walk list to detect duplicate functor; if none, AddRecord and return 1.

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
    int field4;
    int field8;
    int InstallEntry(int priority, CBFunctor0& functor, char* name);
    void AddRecord(int priority, CBFunctor0& functor, char* name);
};

int UIUpdateTable::InstallEntry(int priority, CBFunctor0& functor, char* name) {
    if (field8 != 0) {
        UTEntry* e = head;
        while (e != 0) {
            if (e->field12 == &functor) goto fail;
            e = e->next;
        }
        AddRecord(priority, functor, name);
        return 1;
    }
fail:
    return 0;
}
