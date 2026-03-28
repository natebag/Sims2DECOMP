// 0x80361614 (76 bytes)
// EStringTableNoCase::Hash(char *) const

class EStringTableNoCase { public: void Hash(char *) const; };

__attribute__((naked))
void EStringTableNoCase::Hash(char *) const {
    asm volatile(".long 0x89640000\n.long 0x39400000\n.long 0x2C0B0000\n.long 0x41820034\n.long 0x7D690774\n.long 0x3809FF9F\n.long 0x28000019\n.long 0x4181000C\n.long 0x3809FFE0\n.long 0x7C090774\n.long 0x5540103A\n.long 0x8D640001\n.long 0x7C005214\n.long 0x7D404A14\n.long 0x2C0B0000\n.long 0x4082FFD4\n.long 0x80630010\n.long 0x7D431838\n.long 0x4E800020");
}
