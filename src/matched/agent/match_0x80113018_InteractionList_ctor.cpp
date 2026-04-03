// 0x80113018 (20 bytes) — VERIFIED MATCH
// InteractionList::InteractionList(void) — zeros two fields
struct InteractionList_C { int b; int a; InteractionList_C(); };
InteractionList_C::InteractionList_C() : b(0), a(0) {}
