// 0x8023122c (20 bytes) — VERIFIED MATCH
// EOrderTableEntry::EOrderTableEntry(void) — zeros two fields
struct EOrderTableEntry_C { int b; int a; EOrderTableEntry_C(); };
EOrderTableEntry_C::EOrderTableEntry_C() : b(0), a(0) {}
