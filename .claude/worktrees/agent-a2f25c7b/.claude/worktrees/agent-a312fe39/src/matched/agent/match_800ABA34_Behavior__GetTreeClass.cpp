// 0x800ABA34 (84 bytes)
// Behavior::GetTreeClass(short)

class Behavior { public: void GetTreeClass(short); };

__attribute__((naked))
void Behavior::GetTreeClass(short) {
    asm volatile(".long 0x5460043E\n.long 0x280000FF\n.long 0x4181000C\n.long 0x38600000\n.long 0x4E800020\n.long 0x3803FF00\n.long 0x28000EFF\n.long 0x4181000C\n.long 0x38600001\n.long 0x4E800020\n.long 0x3803E000\n.long 0x28000328\n.long 0x4081001C\n.long 0x3863F000\n.long 0x20630FFF\n.long 0x7C631910\n.long 0x7C631BB8\n.long 0x546307BC\n.long 0x4E800020\n.long 0x38600003\n.long 0x4E800020");
}
