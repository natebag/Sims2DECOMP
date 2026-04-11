// 0x80113018 InteractionList::InteractionList (20b)

struct InteractionList {
    int f0;
    int f4;
    InteractionList();
};

InteractionList::InteractionList() {
    InteractionList* p = this;
    p->f0 = 0;
    p->f4 = 0;
}
