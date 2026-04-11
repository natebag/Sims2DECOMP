// 0x8023122C EOrderTableEntry::EOrderTableEntry (20b)

struct EOrderTableEntry {
    int f0;
    int f4;
    EOrderTableEntry();
};

EOrderTableEntry::EOrderTableEntry() {
    EOrderTableEntry* p = this;
    p->f0 = 0;
    p->f4 = 0;
}
